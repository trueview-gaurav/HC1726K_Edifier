/* 
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All rights reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
#include <gst/gst.h>
#include <gst/rtsp-server/rtsp-server.h>
#include <gst/app/app.h>
#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <alsa/asoundlib.h>
#include <pthread.h>   /* OPT-3: pthread_attr_setstacksize for thread stack reduction */

#include <gio/gio.h> //libgio for GTlsCertificate, GTlsAuthenticationMode

#include <ifaddrs.h> //network interface
#include <arpa/inet.h>

#define RTSPS_support 1 /* 1: RTSP + RTSPS 	0: RTSP only */

/* ============================================================================
 * agtx-rtsp-server — Usage & Configuration Guide
 * ============================================================================
 *
 * SYNOPSIS
 *   agtx-rtsp-server [-s <sensor_index>] [-S] [-c <config_file>]
 *
 * OPTIONS
 *
 *   -s <sensor_index>
 *       Sensor index this instance should serve (default: 0).
 *       The server loads its configuration exclusively from
 *       /system/mpp/case_config/agtx-rtsp_<sensor_index>.conf
 *       and only registers the encoder channels declared under
 *       [sensor] in that file.
 *
 *       Example:  -s 0   → loads agtx-rtsp_0.conf, serves sensor 0 channels
 *                 -s 1   → loads agtx-rtsp_1.conf, serves sensor 1 channels
 *
 * IVA OPTIONS (only available when built with GST_RTSP_SERVER_ENABLE_IVA)
 *
 *   -S
 *       Force-enable IVA/SEI metadata injection on ALL channels of this
 *       sensor instance.
 *
 *   -c <config_file>
 *       Manually specify the path to the configuration file.
 *       Overrides the automatic path derived from -s.
 *       The file must exist; it will NOT be created automatically.
 *
 *
 * CONFIG FILE   /system/mpp/case_config/agtx-rtsp_<N>.conf   (.conf format)
 *
 *
 *
 *
 *   [sensor]              # Sensor-to-channel mapping for this instance
 *   sensor_index  = 0     # sensor index this file belongs to (must match -s)
 *   chn_start     = 0     # first encoder channel owned by this sensor
 *   chn_count     = 2     # number of consecutive channels for this sensor
 *   rtsp_port     = 8554  # RTSP listen port for this sensor instance
 *   rtsps_port    = 9554  # RTSPS listen port for this sensor instance
 *
 *   [channel_0]           # Per-channel IVA settings for channel 0
 *   iva_src_chn = 0       # source window channel index
 *   iva_src_win = 0       # source window index
 *   iva_dst_chn = 0       # destination window channel
 *   iva_dst_win = 0       # destination window index
 *
 *   [channel_1]           # Per-channel IVA settings for channel 1
 *   iva_src_chn = 1
 *   iva_src_win = 0
 *   iva_dst_chn = 0
 *   iva_dst_win = 0
 *
 *   ... repeat [channel_N] for each channel in this sensor's range ...
 *
 *   Config file rules:
 *   - Lines beginning with '#' or ';' are comments and are ignored.
 *   - Missing keys keep their default value: src=MPI_VIDEO_WIN(0,0,0), dst=MPI_VIDEO_WIN(0,chn,0).
 *   - If the sensor-specific .conf file is absent it is created
 *     automatically with fully-commented default values on first run.
 *   - Each sensor instance must use a unique rtsp_port / rtsps_port so
 *     two instances can run side-by-side on the same device.
 *
 * PRIORITY ORDER (lowest → highest)
 *   1. Built-in defaults    : src=MPI_VIDEO_WIN(0,0,0) dst=MPI_VIDEO_WIN(0,chn,0), chn_start=0,
 *                             chn_count=2, rtsp_port=8554, rtsps_port=9554
 *   2. /system/mpp/case_config/agtx-rtsp_<N>.conf : per-sensor, per-channel settings
 *   3. CLI flag -S          : force-enables IVA for this instance
 *
 * STREAM URLS (auto-detected at runtime)
 *   RTSP  (plain) : rtsp://<ip>:<rtsp_port>/augentixN    (N = chn_start .. chn_start+chn_count-1)
 *   RTSPS (TLS)   : rtsps://<ip>:<rtsps_port>/augentixN  (when RTSPS_support=1)
 *
 * CHANNEL DETECTION
 *   On startup the server probes MPI encoder channels 0 .. (CHANNEL_NUM-1)
 *   and registers only the channels that are physically present on this
 *   platform (Option-D: detect_platform_channel_count).  A GLib periodic
 *   timer (every CHANNEL_REPROBE_SEC seconds) re-probes missing or
 *   failed channels and dynamically registers them once they become
 *   available again.  After CHANNEL_REPROBE_GIVEUP consecutive failures
 *   the channel is permanently discarded (g_channel_permanently_absent[]
 *   set TRUE) — no further MPI calls are ever made for it, and the
 *   reprobe timer is stopped once all startup channels are either
 *   registered or permanently absent.  A mid-stream channel death
 *   (sensor malfunction after initial success) resets the failure
 *   counter and re-arms the reprobe timer so recovery is still
 *   attempted; permanently-absent channels are never re-armed.
 *
 * SENSOR RECOVERY
 *   If MPI_getBitStream() fails mid-stream the server retries up to
 *   SENSOR_RECOVERY_MAX times (with SENSOR_RECOVERY_DELAY_S second
 *   backoff).  On full failure EOS is sent, the channel is marked for
 *   re-probe, and the periodic timer will re-register the factory once
 *   the sensor recovers — without affecting any other active channel.
 *
 * STARTUP LOG
 *   On startup, after server initialisation, print_running_config() emits
 *   a full snapshot of the active configuration to the log:
 *     - Config file path (created if default path and not found)
 *     - RTSP / RTSPS port and TLS cert paths
 *     - Platform encoder channel count (Option-D detected)
 *     - Sensor recovery tuning constants
 *     - IVA active/disabled state (-S flag) and per-channel iva_src / iva_dst windows
 *     - Whether each channel was successfully registered
 *
 * USAGE EXAMPLES
 *
 *   # Sensor 0 only (loads agtx-rtsp_0.conf, IVA disabled)
 *   # (if agtx-rtsp_0.conf does not exist it is created automatically)
 *   agtx-rtsp-server -s 0 &
 *
 *   # Sensor 1 only (loads agtx-rtsp_1.conf)
 *   agtx-rtsp-server -s 1 &
 *
 *   # Two independent instances, one per sensor (different ports set in each .conf)
 *   agtx-rtsp-server -s 0 &   # reads agtx-rtsp_0.conf  (rtsp_port=8554, rtsps_port=9554)
 *   agtx-rtsp-server -s 1 &   # reads agtx-rtsp_1.conf  (rtsp_port=8555, rtsps_port=9555)
 *
 *   # Force IVA on sensor 0's channels
 *   agtx-rtsp-server -s 0 -S &
 *
 *   # Force IVA on sensor 1's channels
 *   agtx-rtsp-server -s 1 -S &
 *
 *   # Minimal (no -s flag → defaults to sensor 0)
 *   agtx-rtsp-server &
 *
 * ============================================================================
 */


#include "mpi_dev.h"
#include "mpi_enc.h"
#include "mpi_sys.h"

#ifdef GST_RTSP_SERVER_ENABLE_IVA
#ifdef CLAMP
#undef CLAMP
#endif
#include "avftr.h"
#include "avftr_conn.h"
#define MAX_SEI_SIZE  2048
#define SEI_UUID_SIZE 16
#endif /* GST_RTSP_SERVER_ENABLE_IVA */

#define LOG_N(fmt, ...) g_print("[INFO][%s:%d] " fmt "\n", __func__, __LINE__, ##__VA_ARGS__)
#define ERR_N(fmt, ...) g_printerr("[ERROR][%s:%d] " fmt "\n", __func__, __LINE__, ##__VA_ARGS__)
/* OPT-1B: debug-level macro — only prints when sg_debug_mode is TRUE (-d flag).
 * Use for high-frequency per-channel probe messages that spam syslog on
 * platforms with absent channels (e.g. HC1726 2-channel with CHANNEL_NUM=6). */
#define LOG_D(fmt, ...) do { if (sg_debug_mode) \
	g_print("[DEBUG][%s:%d] " fmt "\n", __func__, __LINE__, ##__VA_ARGS__); } while(0)

/* -------------------- original constants -------------------- */
#define CHANNEL_NUM 6
/* Maximum consecutive MPI_getBitStream errors before treating the
 * sensor as malfunctional and sending EOS downstream. Mirrors the
 * -ENODATA / chnRestartTrigger logic in AuxVidDeviceSource.cpp.   */
#define SENSOR_TIMEOUT_MAX     10
/* number of MPI re-probe attempts before giving up on
 * a mid-stream sensor recovery.                                    */
#define SENSOR_RECOVERY_MAX     5
/* seconds between re-probe attempts for mid-stream
 * recovery, and between GLib periodic re-probe ticks for channels
 * that were absent at startup.                                     */
#define SENSOR_RECOVERY_DELAY_S 2
#define CHANNEL_REPROBE_SEC     5

/* For dsnoop mode, use the capture PCM name configured in /etc/asound.conf */
#define AUDIO_CHANNELS 1
#define AUDIO_RATE 8000
#define AUDIO_FRAME_SIZE 1024 /* ex:S16LE, 1024 frames * 1ch * 2 bytes = 2048 bytes */

typedef struct _ElementCapsCodecMap {
	const char *parser_name;
	const char *payloader_name;
	const char *codec_name;
} ElementCapsCodecMap;

static ElementCapsCodecMap sgMap[MPI_VENC_TYPE_NUM] = {
	[MPI_VENC_TYPE_H264] = { "h264parse", "rtph264pay", "video/x-h264" },
	[MPI_VENC_TYPE_H265] = { "h265parse", "rtph265pay", "video/x-h265" },
	[MPI_VENC_TYPE_MJPEG] = { "identity",  "rtpjpegpay", "image/jpeg" },
	[MPI_VENC_TYPE_JPEG]  = { "identity",  "rtpjpegpay", "image/jpeg" }
};

typedef struct _AugentixRtspElements {
	GstElement *source;
	GstElement *vqueue, *parser, *payloader;
	/* audio elements */
	GstElement *asource;
	GstElement *aqueue;
	GstElement *audioconvert;
	/*GstElement *audioresample;*/
	GstElement *apayloader;
} AugentixRtspElements;

typedef struct _StreamContext {
	MPI_BCHN mpi_b_channel;
	MPI_VENC_TYPE_E mpi_enc_type;
	GstElement *appsrc;        /* video appsrc */
	GstElement *audio_appsrc;  /* audio appsrc */
	GstElement *pipeline;      /* GST-5: pipeline for get_running_time(); set in media_configure() */
	pthread_t thread;          /* OPT-3: was GThread*; pthread_create with 256 KB stack */
	pthread_t athread;         /* OPT-3: was GThread*; pthread_create with 256 KB stack */
	gboolean  thread_started;  /* OPT-3: TRUE only after pthread_create succeeds (POSIX-safe join guard) */
	gboolean  athread_started; /* OPT-3: TRUE only after pthread_create succeeds (POSIX-safe join guard) */
	bool isRunning;
	MPI_VENC_INFO_S mpi_venc_info;
	int timeout_cnt; /* consecutive MPI_getBitStream error counter     */
	snd_pcm_t *pcm_handle;
	int audio_frame_size;

#ifdef GST_RTSP_SERVER_ENABLE_IVA
	/*
	 * Initialized in media_configure() before push_data_thread starts.
	 */
	MPI_WIN iva_idx; /* source IVA window index (fIvaIdx)  */
	MPI_WIN dst_idx; /* destination window index (fIdx)	  */
	MPI_RECT_S src_rect; /* source rect	(fSrcRect)			  */
	MPI_RECT_S dst_rect; /* destination rect (fDstRect)		  */
	MPI_RECT_S src_roi; /* source ROI	(fSrcRoi)			  */
	MPI_RECT_S dst_roi; /* destination ROI (fDstRoi)		  */
	char          *tmp_sei_str;  /* OPT-2: heap-alloc only when g_avftr_conn > 0; NULL otherwise */
	unsigned char *sei_nalu;     /* OPT-2: heap-alloc only when g_avftr_conn > 0; NULL otherwise */
#endif /* GST_RTSP_SERVER_ENABLE_IVA */
} StreamContext;

typedef struct _AugentixRTSPMedia {
	GstRTSPMedia parent;
} AugentixRTSPMedia;
typedef struct _AugentixRTSPMediaClass {
	GstRTSPMediaClass parent_class;
} AugentixRTSPMediaClass;
#define AUGENTIX_TYPE_RTSP_MEDIA (augentix_rtsp_media_get_type())
#define AUGENTIX_RTSP_MEDIA(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), AUGENTIX_TYPE_RTSP_MEDIA, AugentixRTSPMedia))
G_DEFINE_TYPE(AugentixRTSPMedia, augentix_rtsp_media, GST_TYPE_RTSP_MEDIA)

typedef struct _AugentixMediaFactory {
	GstRTSPMediaFactory parent;
	gint channel_idx;
} AugentixMediaFactory;
typedef struct _AugentixMediaFactoryClass {
	GstRTSPMediaFactoryClass parent_class;
} AugentixMediaFactoryClass;
#define AUGENTIX_TYPE_MEDIA_FACTORY (augentix_media_factory_get_type())
#define AUGENTIX_MEDIA_FACTORY(obj) \
	(G_TYPE_CHECK_INSTANCE_CAST((obj), AUGENTIX_TYPE_MEDIA_FACTORY, AugentixMediaFactory))
G_DEFINE_TYPE(AugentixMediaFactory, augentix_media_factory, GST_TYPE_RTSP_MEDIA_FACTORY)

/* -------------------- globals -------------------- */
static GMainLoop *loop = NULL;
static GstRTSPServer *server_inst = NULL; //RTSP server
static guint server_id; //RTSP server id
static volatile gint sg_isServiceRunning = 1; /* atomic: 1=running, 0=stopped.
 * Declared volatile so the compiler never caches the value across thread
 * boundaries; use g_atomic_int_get/set for all reads and writes.           */
/* tracks which channels have an active factory mounted.
 * Written in setup_augentix_rtsp_server() and in the periodic
 * re-probe callback; read-only after that (GLib main loop context). */
static gboolean sg_debug_mode = FALSE;      /* OPT-1B: set TRUE by -d CLI flag */
static gboolean g_channel_registered[CHANNEL_NUM];
/* kept alive so the periodic re-probe callback can add
 * factories after startup without calling gst_rtsp_server_get_mount_points()
 * again (which would create a second independent set of mount points). */
static GstRTSPMountPoints *g_mounts = NULL;
/* TRUE when a channel exhausted all mid-stream recovery attempts
 * and sent EOS. The reprobe timer will re-register the factory once the
 * sensor comes back, allowing new clients to connect again.             */
static gboolean g_channel_needs_reprobe[CHANNEL_NUM];
/* Maximum consecutive reprobe failures before permanently silencing a channel.
 * Once g_channel_reprobe_fail[i] reaches this limit, reprobe_missing_channels()
 * stops calling is_channel_available(i) entirely, eliminating the
 * [VPLAT] "ENC N does not exist" syslog flood for channels that will
 * never become available on this platform/sensor configuration.
 * Set to 0 to disable the give-up logic (infinite retries, old behaviour). */
#define CHANNEL_REPROBE_GIVEUP  3
/* Per-channel consecutive reprobe-failure counter.
 * Incremented each time is_channel_available() returns FALSE in the periodic
 * reprobe callback.  Reset to 0 when the channel becomes available again.
 * When it reaches CHANNEL_REPROBE_GIVEUP the channel is silenced:
 * no further MPI_ENC_getVencAttr() calls are made until the channel suffers
 * a mid-stream death (g_channel_needs_reprobe[i]=TRUE resets the counter). */
static gint g_channel_reprobe_fail[CHANNEL_NUM];
/* TRUE once g_channel_reprobe_fail[i] reaches CHANNEL_REPROBE_GIVEUP for
 * a startup-miss channel.  Once set, reprobe_missing_channels() never
 * calls is_channel_available(i) again, and mid-stream deaths on this
 * channel do NOT re-arm the reprobe timer (hot-plug not supported). */
static gboolean g_channel_permanently_absent[CHANNEL_NUM];
/* GLib source ID of the periodic reprobe timer.
 * 0 means the timer is not currently running.
 * Stored so push_data_thread() can re-arm the timer after a
 * mid-stream death without creating duplicate timer sources. */
static guint g_reprobe_timer_id = 0;
/* Option-D: actual number of encoder channels present on this platform,
 * detected once at startup by detect_platform_channel_count().
 * Probing only 0..g_active_channel_num-1 prevents [VPLAT] ENC-N-does-
 * not-exist log spam for channels that will never exist on this SoC.  */
static gint g_active_channel_num = 0;

#ifdef GST_RTSP_SERVER_ENABLE_IVA
/*
 * AVFTR globals
 *	 int avftrUnxSktClientFD;		   Unix socket FD to AVFTR server
 *	 int avftrResShmClientFD;		   shared-memory result FD
 *	 AVFTR_CTX_S *avftr_res_shm_client; SHM client context
 *	 int g_avftr_conn;	   0=disabled, 1=enabled via config file, 2=force-enabled (-S flag)
 *	 MPI_WIN g_avftr_dst_win; destination window (chn + win, same shape as g_avftr_src_win)
 *	 MPI_WIN g_avftr_src_win; source window
 */
static int avftrUnxSktClientFD = -1;
static int avftrResShmClientFD = -1;
static AVFTR_CTX_S *avftr_res_shm_client = NULL;
static int g_avftr_conn = 0;
static MPI_WIN g_avftr_dst_win = MPI_VIDEO_WIN(0, 0, 0);
static MPI_WIN g_avftr_src_win = MPI_VIDEO_WIN(0, 0, 0);

/* per-channel IVA configuration loaded from
 * /system/mpp/case_config/agtx-rtsp.conf at startup.  CLI flags -S/-i/-o override these
 * values after the config file is parsed.                           */
typedef struct {
    MPI_WIN iva_src_win; /* -i equivalent: source IVA window (chn+win) */
    MPI_WIN iva_dst_win; /* -o equivalent: destination window (chn+win) */
    guint       vqueue_max_bytes; /* 0 = use built-in default (4194304) */
    guint       aqueue_max_bytes; /* 0 = use built-in default (524288)  */
} ChannelIvaConf;

static ChannelIvaConf g_channel_conf[CHANNEL_NUM];

#endif /* GST_RTSP_SERVER_ENABLE_IVA */

#if (RTSPS_support)
static GstRTSPServer *server_tls_inst = NULL; //RTSPS server
static guint server_tls_id = 0; //RTSPS server id

#if 1 //use nginx default cert. and private key
#define CERT_path "/etc/nginx/ssl/cert.pem.default" /* certification */
#define KEY_path "/etc/nginx/ssl/key.pem.default" /* private key */
#else
/* openssl req -x509 -nodes -newkey rsa:2048 -keyout server-key.pem -out server-cert.pem -keyout server-key.pem -out server-cert.pem -days 3650 -subj "/CN=augentix-rtsp" */
#define CERT_path "/system/bin/server-cert.pem" /* certification */
#define KEY_path "/system/bin/server-key.pem" /* private key */
#endif

#endif


/* ── load_rtsp_config() ─────────────────────────────
 * Reads /system/mpp/case_config/agtx-rtsp.conf and fills g_channel_conf[].
 *
 * File format (.conf-style):
 *   [global]
 *   avftr_conn = 1        # 0=disabled, 1=enable IVA (config), 2=force-enable (-S flag)
 *
 *   [channel_0]
 *   iva_src_chn = 0         # -i <chn> equivalent
 *   iva_src_win = 0         # -i <win> equivalent
 *   iva_dst_chn = 0         # -o <chn> equivalent
 *   iva_dst_win = 0         # -o <win> equivalent
 *
 *   [channel_1] ... [channel_N]
 *
 * Lines beginning with '#' or ';' are comments and are ignored.
 * Missing keys keep their default zero values (MPI_VIDEO_WIN(0,0,0)).
 * If the config file does not exist the defaults are used silently.
 * ─────────────────────────────────────────────────────────────────────────*/
#define RTSP_CONF_DIR  "/system/mpp/case_config"
#define RTSP_CONF_PATH "/system/mpp/case_config/agtx-rtsp.conf" /* legacy, unused at runtime */
/* ── Sensor-index-based per-instance globals ─────────────────────
 * Set by -s <N> CLI flag (default: sensor 0).
 * g_conf_path is derived as  RTSP_CONF_DIR/agtx-rtsp_<N>.conf
 * at the start of main() after -s is parsed.                      */
static gint         g_sensor_index    = 0;         /* -s <N>           */
static char         g_conf_path_buf[256]            /* generated path   */
                    = RTSP_CONF_DIR "/agtx-rtsp_0.conf";
static const char  *g_conf_path       = g_conf_path_buf;
static gboolean     g_conf_path_custom = FALSE;           /* TRUE when -c overrides auto path */
/* Channel range and RTSP ports — loaded from [sensor] section in
 * the .conf file; may be overridden by defaults below if absent.  */
static gint         g_sensor_chn_start  = 0;       /* [sensor] chn_start  */
static gint         g_sensor_chn_count  = 2;       /* [sensor] chn_count  */
static char         g_rtsp_port_buf[16]  = "8554";  /* [sensor] rtsp_port  */
static char         g_rtsps_port_buf[16] = "9554";  /* [sensor] rtsps_port */

/* ── create_default_config() ────────────────────────────────────
 * Creates a well-commented default config file at conf_path when it does not
 * exist.  Called from load_rtsp_config() on first-time startup so the
 * operator always has a reference file to edit.
 *
 * The generated file is fully self-documenting: every parameter has an inline
 * comment explaining its meaning and valid range.
 * ─────────────────────────────────────────────────────────────────────────*/
static void create_default_config(const char *conf_path)
{
    FILE *fp = fopen(conf_path, "w");
    if (!fp) {
        ERR_N("Cannot create default config file %s (check permissions)", conf_path);
        return;
    }
    /* Derive default port offsets from sensor index so two instances do
     * not collide when auto-created (sensor 0 → 8554/9554,
     * sensor N → 8554+N / 9554+N).                                   */
    int default_rtsp_port  = 8554 + g_sensor_index;
    int default_rtsps_port = 9554 + g_sensor_index;
    int default_chn_start  = g_sensor_index * 2; /* 2 channels per sensor */
    int default_chn_count  = 2;
    fprintf(fp,
        "# =============================================================\n"
        "# agtx-rtsp-server — default configuration file\n"
        "# Generated automatically on first run.\n"
        "# Sensor index : %d\n"
        "# Path         : %s\n"
        "# =============================================================\n"
        "\n"
        "# -------------------------------------------------------------\n"
        "# [global] — server-wide settings (apply to all channels)\n"
        "# -------------------------------------------------------------\n"
        "[global]\n"
        "\n"
        "# avftr_conn : IVA/SEI enable flag\n"
        "#   0 = disabled (default)\n"
        "#   1 = enable IVA from config file\n"
        "#   2 = force-enable (same as -S CLI flag; -S always wins)\n"
        "avftr_conn = 0\n"  /* always baseline 0; use -S or edit this file to enable */
        "\n"
        "# -------------------------------------------------------------\n"
        "# [sensor] — sensor-to-channel mapping for this instance\n"
        "# -------------------------------------------------------------\n"
        "[sensor]\n"
        "\n"
        "# sensor_index : must match the -s <N> CLI argument\n"
        "sensor_index = %d\n"
        "\n"
        "# chn_start : first MPI encoder channel owned by this sensor\n"
        "chn_start = %d\n"
        "\n"
        "# chn_count : number of consecutive channels for this sensor\n"
        "chn_count = %d\n"
        "\n"
        "# rtsp_port  : RTSP listen port for this sensor instance\n"
        "#              (use a unique port for each running instance)\n"
        "rtsp_port = %d\n"
        "\n"
        "# rtsps_port : RTSPS (TLS) listen port for this sensor instance\n"
        "rtsps_port = %d\n"
        "\n",
        g_sensor_index, conf_path,
        g_sensor_index,
        default_chn_start, default_chn_count,
        default_rtsp_port, default_rtsps_port);
    /* Per-channel sections — only for channels owned by this sensor */
    for (int i = default_chn_start; i < default_chn_start + default_chn_count; i++) {
        fprintf(fp,
            "# -------------------------------------------------------------\n"
            "# [channel_%d] — settings for encoder channel %d\n"
            "# -------------------------------------------------------------\n"
            "[channel_%d]\n"
            "\n"
            "iva_src_chn = 0\n"
            "iva_src_win = 0\n"
            "\n"
            "iva_dst_chn = %d\n"
            "iva_dst_win = 0\n"
            "\n"
            "# Video queue buffer size in bytes; 0 = built-in default (4194304 = 4 MB)\n"
            "#   Increase for high-bitrate / high-resolution main streams.\n"
            "#   Decrease to reduce latency on low-bitrate sub-streams.\n"
            "#   Example: vqueue_max_bytes = 8388608   # 8 MB\n"
            "vqueue_max_bytes = 0\n"
            "\n"
            "# Audio queue buffer size in bytes; 0 = built-in default (524288 = 512 KB)\n"
            "#   Example: aqueue_max_bytes = 262144    # 256 KB\n"
            "aqueue_max_bytes = 0\n"
            "\n",
            i, i, i, i);
    }
    fclose(fp);
    LOG_N("Default config file created at %s (sensor=%d chn_start=%d chn_count=%d rtsp_port=%d)",
          conf_path, g_sensor_index, default_chn_start, default_chn_count, default_rtsp_port);
}
static void load_rtsp_config(const char *conf_path)
{
    /* Initialise all per-channel confs to zero / MPI_VIDEO_WIN(0,0,0). */
    for (int i = 0; i < CHANNEL_NUM; i++) {
        /* iva_src defaults to dev=0, chn=0, win=0 (shared global source) */
        g_channel_conf[i].iva_src_win = MPI_VIDEO_WIN(0, 0, 0);
        /* iva_dst defaults to dev=0, chn=i, win=0 (each channel targets itself) */
        g_channel_conf[i].iva_dst_win = MPI_VIDEO_WIN(0, i, 0);
        g_channel_conf[i].vqueue_max_bytes = 0; /* 0 → use DEFAULT_VQUEUE_MAX_BYTES */
        g_channel_conf[i].aqueue_max_bytes = 0; /* 0 → use DEFAULT_AQUEUE_MAX_BYTES */
    }
    FILE *fp = fopen(conf_path, "r");
    if (!fp) {
        /* Auto-create if this is the sensor-specific default path */
        char expected[256];
        snprintf(expected, sizeof(expected),
                 RTSP_CONF_DIR "/agtx-rtsp_%d.conf", g_sensor_index);
        if (!g_conf_path_custom && strcmp(conf_path, expected) == 0) {
            LOG_N("Config file %s not found — creating default", conf_path);
            create_default_config(conf_path);
            fp = fopen(conf_path, "r");
            if (!fp) {
                ERR_N("Failed to re-open %s after creation — using defaults", conf_path);
                return;
            }
        } else {
            ERR_N("Config file %s not found — using built-in defaults", conf_path);
            return;
        }
    }
    /* ── First pass: extract [sensor] chn_start/chn_count/ports so that
     *    the channel-ownership filter in the second pass is correct even
     *    when [channel_N] sections appear before [sensor] in the file.   */
    {
        char line[256];
        gboolean in_sensor = FALSE;
        while (fgets(line, sizeof(line), fp)) {
            char *nl = strpbrk(line, "\r\n"); if (nl) *nl = '\0';
            char *p = line;
            while (*p == ' ' || *p == '\t') p++;
            if (*p == '\0' || *p == '#' || *p == ';') continue;
            if (*p == '[') {
                char sec[64] = { 0 };
                sscanf(p, "[%63[^]]]", sec);
                in_sensor = (strcmp(sec, "sensor") == 0);
                continue;
            }
            if (!in_sensor) continue;
            char key[64] = { 0 }, val[64] = { 0 };
            if (sscanf(p, "%63[^= \t] = %63s", key, val) != 2)
                if (sscanf(p, "%63[^=]=%63s", key, val) != 2) continue;
            char *ke = key + strlen(key) - 1;
            while (ke > key && (*ke == ' ' || *ke == '\t')) *ke-- = '\0';
            int ival = atoi(val);
            if (strcmp(key, "chn_start") == 0)  g_sensor_chn_start = ival;
            else if (strcmp(key, "chn_count") == 0)  g_sensor_chn_count = ival;
            else if (strcmp(key, "rtsp_port") == 0)
                snprintf(g_rtsp_port_buf,  sizeof(g_rtsp_port_buf),  "%d", ival);
            else if (strcmp(key, "rtsps_port") == 0)
                snprintf(g_rtsps_port_buf, sizeof(g_rtsps_port_buf), "%d", ival);
        }
        rewind(fp);  /* reset for full second pass */
    }

    char line[256];
    int  cur_chn = -1;       /* -1=[global], -3=[sensor], >=0=[channel_N], -2=ignore */
    gboolean in_sensor_section = FALSE;
    while (fgets(line, sizeof(line), fp)) {
        /* Strip trailing newline / carriage-return */
        char *nl = strpbrk(line, "\r\n");
        if (nl) *nl = '\0';
        /* Skip blank lines and comments */
        char *p = line;
        while (*p == ' ' || *p == '\t') p++;
        if (*p == '\0' || *p == '#' || *p == ';')
            continue;
        /* Section header */
        if (*p == '[') {
            char section[64] = { 0 };
            in_sensor_section = FALSE;
            if (sscanf(p, "[%63[^]]]", section) == 1) {
                if (strcmp(section, "global") == 0) {
                    cur_chn = -1;
                } else if (strcmp(section, "sensor") == 0) {
                    cur_chn = -3;
                    in_sensor_section = TRUE;
                } else if (strncmp(section, "channel_", 8) == 0) {
                    int idx = atoi(section + 8);
                    /* Only parse channels owned by this sensor */
                    if (idx >= g_sensor_chn_start &&
                        idx <  g_sensor_chn_start + g_sensor_chn_count &&
                        idx <  CHANNEL_NUM)
                        cur_chn = idx;
                    else
                        cur_chn = -2;
                }
            }
            continue;
        }
        /* Key = value pair */
        char key[64] = { 0 };
        char val[64] = { 0 };
        if (sscanf(p, "%63[^= \t] = %63s", key, val) != 2)
            if (sscanf(p, "%63[^=]=%63s", key, val) != 2)
                continue;
        /* Trim trailing spaces from key */
        char *ke = key + strlen(key) - 1;
        while (ke > key && (*ke == ' ' || *ke == '\t')) *ke-- = '\0';
        int ival = atoi(val);
        if (in_sensor_section) {
            /* ── [sensor] keys ── */
            if (strcmp(key, "sensor_index") == 0) {
                if (ival != g_sensor_index)
                    ERR_N("Config sensor_index=%d does not match CLI -s %d",
                          ival, g_sensor_index);
            } else if (strcmp(key, "chn_start") == 0) {
                g_sensor_chn_start = ival;
                LOG_N("Config: sensor chn_start = %d", g_sensor_chn_start);
            } else if (strcmp(key, "chn_count") == 0) {
                g_sensor_chn_count = ival;
                LOG_N("Config: sensor chn_count = %d", g_sensor_chn_count);
            } else if (strcmp(key, "rtsp_port") == 0) {
                snprintf(g_rtsp_port_buf, sizeof(g_rtsp_port_buf), "%d", ival);
                LOG_N("Config: sensor rtsp_port  = %s", g_rtsp_port_buf);
            } else if (strcmp(key, "rtsps_port") == 0) {
                snprintf(g_rtsps_port_buf, sizeof(g_rtsps_port_buf), "%d", ival);
                LOG_N("Config: sensor rtsps_port = %s", g_rtsps_port_buf);
            }
        } else if (cur_chn == -1) {
            /* ── [global] keys ── */
            if (strcmp(key, "avftr_conn") == 0) {
                if (g_avftr_conn != 2) {
                    /* Only apply config value when -S flag was NOT given;
                     * g_avftr_conn == 2 means the -S CLI flag was already set;
                     * any other value (0 = default, 1 = set by earlier config key)
                     * is safe to overwrite with the new parsed value. */
                    g_avftr_conn = ival;
                    LOG_N("Config: global avftr_conn = %d", g_avftr_conn);
                } else {
                    LOG_N("Config: global avftr_conn = %d (overridden by -S flag, keeping 2)",
                          ival);
                }
            }
        } else if (cur_chn >= 0) {
            /* ── [channel_N] keys ── */
            if (strcmp(key, "iva_src_chn") == 0) {
                g_channel_conf[cur_chn].iva_src_win.chn = (uint8_t)ival;
                LOG_N("Config: channel_%d iva_src_chn = %d", cur_chn, ival);
            } else if (strcmp(key, "iva_src_win") == 0) {
                g_channel_conf[cur_chn].iva_src_win.win = (uint8_t)ival;
                LOG_N("Config: channel_%d iva_src_win = %d", cur_chn, ival);
            } else if (strcmp(key, "iva_dst_chn") == 0) {
                g_channel_conf[cur_chn].iva_dst_win.chn = (uint8_t)ival;
                LOG_N("Config: channel_%d iva_dst_chn = %d", cur_chn, ival);
            } else if (strcmp(key, "iva_dst_win") == 0) {
                g_channel_conf[cur_chn].iva_dst_win.win = (uint8_t)ival;
                LOG_N("Config: channel_%d iva_dst_win = %d", cur_chn, ival);
            } else if (strcmp(key, "vqueue_max_bytes") == 0) {
                if (val[0] == '-') {
                    LOG_N("Config: channel_%d vqueue_max_bytes negative value ignored, using default", cur_chn);
                } else {
                    g_channel_conf[cur_chn].vqueue_max_bytes = (guint)strtoul(val, NULL, 10);
                    LOG_N("Config: channel_%d vqueue_max_bytes = %u", cur_chn, g_channel_conf[cur_chn].vqueue_max_bytes);
                }
            } else if (strcmp(key, "aqueue_max_bytes") == 0) {
                if (val[0] == '-') {
                    LOG_N("Config: channel_%d aqueue_max_bytes negative value ignored, using default", cur_chn);
                } else {
                    g_channel_conf[cur_chn].aqueue_max_bytes = (guint)strtoul(val, NULL, 10);
                    LOG_N("Config: channel_%d aqueue_max_bytes = %u", cur_chn, g_channel_conf[cur_chn].aqueue_max_bytes);
                }
            }
        }
    }
    fclose(fp);
    LOG_N("Config %s loaded (sensor=%d chn_start=%d chn_count=%d rtsp_port=%s)",
          conf_path, g_sensor_index, g_sensor_chn_start, g_sensor_chn_count, g_rtsp_port_buf);
}

//get the ip address
static int get_ipv4_of_iface(const char *ifname, char *out_ip, size_t buflen)
{
	struct ifaddrs *ifaddr, *ifa;

	if (getifaddrs(&ifaddr) == -1)
		return -1;

	for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
		if (ifa->ifa_addr == NULL)
			continue;

		if (ifa->ifa_addr->sa_family == AF_INET && strcmp(ifa->ifa_name, ifname) == 0) {
			struct sockaddr_in *sa = (struct sockaddr_in *)ifa->ifa_addr;
			inet_ntop(AF_INET, &(sa->sin_addr), out_ip, buflen);
			freeifaddrs(ifaddr);
			return 0;
		}
	}

	freeifaddrs(ifaddr);
	return -1;
}

#if (RTSPS_support)
static GTlsCertificate *create_default_tls_certificate(void)
{
	GTlsCertificate *cert = NULL;
	GError *error = NULL;

	cert = g_tls_certificate_new_from_files(CERT_path, KEY_path, &error);
	if (!cert) {
		ERR_N("Failed to load TLS certificate: %s", error ? error->message : "unknown");
		g_clear_error(&error);
	} else {
		LOG_N("Loaded TLS certificate from %s , %s", CERT_path, KEY_path);
	}

	return cert;
}
#endif

static void audio_close_alsa(snd_pcm_t *pcm_handle)
{
	if (!pcm_handle)
		return;
	snd_pcm_drain(pcm_handle);
	snd_pcm_close(pcm_handle);
}

static int audio_init_alsa(snd_pcm_t **pcm_handle, const char *device, unsigned int rate, int channels, int frames)
{
	int rc;
	snd_pcm_hw_params_t *params;
	unsigned int actual_rate = rate;
	int dir = 0;
	snd_pcm_uframes_t period = frames;

	rc = snd_pcm_open(pcm_handle, device, SND_PCM_STREAM_CAPTURE, 0);
	if (rc < 0) {
		ERR_N("Unable to open PCM device %s: %s", device, snd_strerror(rc));
		return -1;
	}

	snd_pcm_hw_params_alloca(&params);
	snd_pcm_hw_params_any(*pcm_handle, params);
	snd_pcm_hw_params_set_access(*pcm_handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);
	snd_pcm_hw_params_set_format(*pcm_handle, params, SND_PCM_FORMAT_S16_LE);
	snd_pcm_hw_params_set_channels(*pcm_handle, params, channels);
	snd_pcm_hw_params_set_rate_near(*pcm_handle, params, &actual_rate, &dir);
	snd_pcm_hw_params_set_period_size_near(*pcm_handle, params, &period, &dir);

	rc = snd_pcm_hw_params(*pcm_handle, params);
	if (rc < 0) {
		ERR_N("Unable to set HW parameters: %s", snd_strerror(rc));
		snd_pcm_close(*pcm_handle);
		return -1;
	}

	LOG_N("ALSA opened %s @ %u Hz, channels=%d, frames=%d", device, actual_rate, channels, (int)period);
	return 0;
}

/* -------------------- ctx free -------------------- */
static void ctx_free(StreamContext *ctx)
{
	if (!ctx)
		return;

	ctx->isRunning = false;
	/* OPT-3: use explicit started flags as join guards — avoids relying on
	 * pthread_t zero-value which is Linux/glibc-specific and not POSIX. */
	if (ctx->thread_started)
		pthread_join(ctx->thread, NULL);
	if (ctx->athread_started)
		pthread_join(ctx->athread, NULL);

	if (VALID_MPI_ENC_BCHN(ctx->mpi_b_channel))
		MPI_destroyBitStreamChn(ctx->mpi_b_channel);

	if (ctx->appsrc)
		gst_object_unref(ctx->appsrc);
	if (ctx->audio_appsrc)
		gst_object_unref(ctx->audio_appsrc);
	if (ctx->pipeline)
		gst_object_unref(ctx->pipeline); /* GST-5: release own ref taken in media_configure() */

	audio_close_alsa(ctx->pcm_handle);
	ctx->pcm_handle = NULL;

#ifdef GST_RTSP_SERVER_ENABLE_IVA
	g_free(ctx->tmp_sei_str);  /* OPT-2: g_free(NULL) is a no-op — safe when IVA disabled */
	g_free(ctx->sei_nalu);
#endif

	g_free(ctx);
}
#ifdef GST_RTSP_SERVER_ENABLE_IVA
/*
 * Queries MPI_DEV_getChnLayout() and extracts the rect for the given
 * MPI_WIN index from the layout's window array.
 *
 * Returns	0 on success, -1 on failure.
 */
static int getWinLayout(MPI_WIN idx, MPI_RECT_S *rect)
{
	MPI_CHN_LAYOUT_S layout_attr;
	MPI_CHN chn;
	uint8_t i;

	chn = MPI_VIDEO_CHN(idx.dev, idx.chn);
	if (MPI_DEV_getChnLayout(chn, &layout_attr) < 0) {
		ERR_N("Cannot get channel layout for chn:%d", chn.chn);
		return -1;
	}
	for (i = 0; i < layout_attr.window_num; i++) {
		if (idx.value == layout_attr.win_id[i].value)
			break;
	}
	if (i == layout_attr.window_num) {
		ERR_N("Window %d does not exist in channel %d", idx.win, idx.chn);
		return -1;
	}
	rect->x = layout_attr.window[i].x;
	rect->y = layout_attr.window[i].y;
	rect->width = layout_attr.window[i].width;
	rect->height = layout_attr.window[i].height;
	return 0;
}

/* find_sei_insert_offset() removed.
 * SEI NAL is always prepended at offset 0 (before VPS/SPS/PPS/IDR).
 * This satisfies decoders (e.g. iCatch NVR) that require SEI before VPS.
 * No bitstream scanning is needed.
 */

/*
 * Builds a user_data_unregistered SEI NAL unit into ctx->sei_nalu[] and
 * returns the total number of bytes written, or:
 *	 0	- AVFTR has no stat data for this frame (skip SEI injection).
 *	-1	- AVFTR_tranVideoResV2() failed (skip SEI injection).
 *
 * Byte layout:
 *	 [00 00 00 01]	  Annex-B start code
 *	 [NAL header]	  H.264: 0x06 (1 byte)
 *					  H.265: 0x4E 0x01 (2 bytes)
 *						NOTE: iCatch NVR can only decode SEI before VPS,
 *						so we always use 0x4E for H.265.
 *	 [0x05]			  SEI payload type: user_data_unregistered
 *	 [size field]	  multi-byte: 0xFF per 255 bytes, then remainder
 *	 [UUID 16 bytes]  0F 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F
 *	 [XML payload]	  from AVFTR_tranVideoResV2()
 *	 [0x80]			  RBSP trailing stop bit
 */
static int build_sei_nalu(StreamContext *ctx, uint32_t timestamp)
{
	static const unsigned char uuid[SEI_UUID_SIZE] = { 0x0F, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
		                                           0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F };

	unsigned int pos = 0;
	int xml_len = 0;
	unsigned int sei_payload_sz = 0;
	/* Gate: only proceed if AVFTR has valid video stat data for this channel */
	if (!AVFTR_getVideoStat(ctx->iva_idx, &avftr_res_shm_client->vftr))
		return 0;

	memset(ctx->tmp_sei_str, 0, MAX_SEI_SIZE);
	memset(ctx->sei_nalu, 0, MAX_SEI_SIZE);

	/* Annex-B start code: 00 00 00 01 */
	ctx->sei_nalu[pos++] = 0x00;
	ctx->sei_nalu[pos++] = 0x00;
	ctx->sei_nalu[pos++] = 0x00;
	ctx->sei_nalu[pos++] = 0x01;

	/* NAL header */
	if (ctx->mpi_enc_type == MPI_VENC_TYPE_H265) {
		/* H.265 PREFIX_SEI_NUT (type 39)*/
		ctx->sei_nalu[pos++] = 0x4E;
		ctx->sei_nalu[pos++] = 0x01;
	} else {
		/* H.264 SEI NAL type = 6.
		 *	 fSeiNalu[start_sei++] = 0x06; */
		ctx->sei_nalu[pos++] = 0x06;
	}

	/* SEI payload type: user_data_unregistered = 5 */
	ctx->sei_nalu[pos++] = 0x05;

	/* Reserve 4 bytes for payload size field; back-fill after XML length known */
	unsigned int size_field_pos = pos;
	pos += 4;

	/* UUID (16 bytes) */
	memcpy(ctx->sei_nalu + pos, uuid, SEI_UUID_SIZE);
	pos += SEI_UUID_SIZE;

	/* XML payload from AVFTR */
	xml_len = AVFTR_tranVideoResV2(ctx->iva_idx, /* arg 1 : src IVA window index	 */
	                               ctx->dst_idx, /* arg 2 : dst window index		 */
	                               &ctx->src_rect, /* arg 3 : source rect			 */
	                               &ctx->dst_rect, /* arg 4 : destination rect		 */
	                               &ctx->src_roi, /* arg 5 : source ROI			 */
	                               &ctx->dst_roi, /* arg 6 : destination ROI		 */
	                               &avftr_res_shm_client->vftr, /* arg 7 : vftr result struct	 */
	                               timestamp, /* arg 8 : frame timestamp		 */
	                               ctx->tmp_sei_str, /* arg 9 : output XML buffer	 */
	                               MAX_SEI_SIZE - 1 /* arg 10: buffer size (leave 1 byte for NUL) */
	);

	if (xml_len <= 0) {
		ERR_N("AVFTR_tranVideoResV2 failed: %d", xml_len);
		return -1;
	}

	/* SEI Bug 2 fix: the back-fill loop encodes sei_payload_sz (UUID + XML) as
	 * one 0xFF per 255 bytes plus a remainder byte, and we reserved exactly 4
	 * bytes for that field.  If sei_payload_sz >= 255*4 = 1020 the loop would
	 * need 5+ bytes and overwrite data already placed in sei_nalu[].
	 * Reject early: xml_len must be < 255*4 - SEI_UUID_SIZE = 1004. */
	if ((unsigned int)xml_len >= (255u * 4u - SEI_UUID_SIZE)) {
		ERR_N("SEI payload too large for 4-byte size field: xml_len=%d", xml_len);
		return -1;
	}

	/* Original buffer-space check (guards UUID copy + XML copy + stop byte). */
	if (pos + (unsigned int)xml_len + 1 >= MAX_SEI_SIZE) {
		ERR_N("SEI buffer overflow: xml_len=%d", xml_len);
		return -1;
	}

	memcpy(ctx->sei_nalu + pos, ctx->tmp_sei_str, (size_t)xml_len);
	pos += (unsigned int)xml_len;

	/* RBSP trailing stop bit */
	ctx->sei_nalu[pos++] = 0x80;

	/* Back-fill the payload size field.
	 * SEI payload = UUID (16) + XML data.
	 * Encoded as: one 0xFF byte per 255 bytes, then the remainder.
	 * SEI Bug 1 fix: we reserved exactly 4 bytes for this field; the
	 * xml_len >= 1004 guard above ensures bytes_written never exceeds 4.
	 * The loop bound (bytes_written < 4) is a belt-and-suspenders safety
	 * cap that prevents any write past the reserved region even if the
	 * guard above is somehow bypassed. */
	sei_payload_sz = SEI_UUID_SIZE + (unsigned int)xml_len;
	{
		unsigned int sz_pos = size_field_pos;
		unsigned int rem = sei_payload_sz;
		unsigned int bytes_written = 0;

		while (rem >= 255 && bytes_written < 4) {
			ctx->sei_nalu[sz_pos + bytes_written] = 0xFF;
			bytes_written++;
			rem -= 255;
		}
		ctx->sei_nalu[sz_pos + bytes_written] = (unsigned char)rem;
		bytes_written++;

		/* Compact the buffer if fewer than 4 reserved bytes were used */
		if (bytes_written < 4) {
			unsigned int shift = 4 - bytes_written;
			memmove(ctx->sei_nalu + size_field_pos + bytes_written, ctx->sei_nalu + size_field_pos + 4,
			        pos - (size_field_pos + 4));
			pos -= shift;
		}
	}

	return (int)pos;
}

#endif /* GST_RTSP_SERVER_ENABLE_IVA */

/* GST-5: returns pipeline running time, or GST_CLOCK_TIME_NONE if not ready.
 * Caller must handle GST_CLOCK_TIME_NONE (Option A: skip the buffer). */
static GstClockTime get_running_time(GstElement *pipeline)
{
	if (!pipeline || GST_STATE(pipeline) != GST_STATE_PLAYING)
		return GST_CLOCK_TIME_NONE;
	GstClock *clock = gst_element_get_clock(pipeline);
	if (!clock)
		return GST_CLOCK_TIME_NONE;
	GstClockTime base = gst_element_get_base_time(pipeline);
	GstClockTime now  = gst_clock_get_time(clock);
	gst_object_unref(clock);
	return (now >= base) ? (now - base) : 0;
}

/* Payload for set_channel_recovery_state_cb: carries the channel index so
 * the main-loop callback knows which channel to update. */
typedef struct {
	gint chn;
} ChannelRecoveryData;

/* Helper: marks a channel as needing re-registration after a mid-stream
 * death. Clears g_channel_registered, resets the reprobe counters, and
 * sets g_channel_needs_reprobe — all three writes are serialised on the
 * GLib main loop so reprobe_missing_channels() never sees a torn state. */
static gboolean set_channel_recovery_state_cb(gpointer user_data)
{
	ChannelRecoveryData *d = (ChannelRecoveryData *)user_data;
	gint chn = d->chn;
	g_free(d);
	/* Skip permanently absent channels — they are never re-probed. */
	if (g_channel_permanently_absent[chn])
		return G_SOURCE_REMOVE;
	/* Write all three fields atomically on the main loop — ordering matters:
	 * registered=FALSE must be visible before needs_reprobe=TRUE so that
	 * reprobe_missing_channels() never sees registered=FALSE + needs_reprobe=FALSE
	 * simultaneously (which would trigger the startup give-up path).           */
	g_channel_registered[chn]    = FALSE; /* P1: moved from worker thread     */
	g_channel_needs_reprobe[chn] = TRUE;
	g_channel_reprobe_fail[chn]  = 0;    /* reset give-up counter             */
	LOG_N("chn=%d marked for re-probe (all state written on main loop)", chn);
	return G_SOURCE_REMOVE;
}

/* Forward declaration — reprobe_missing_channels is defined after rearm_reprobe_timer_cb */
static gboolean reprobe_missing_channels(gpointer user_data);

/* Helper: arms (or re-arms) the channel reprobe timer from ANY thread.
 * Scheduled via g_main_context_invoke() so the actual g_timeout_add_seconds()
 * call — and the read/write of g_reprobe_timer_id — always runs on the GLib
 * main loop, eliminating the TOCTOU race and the duplicate-timer hazard. */
static gboolean rearm_reprobe_timer_cb(gpointer user_data)
{
	(void)user_data;
	/* Guard: do not arm after shutdown */
	if (!g_atomic_int_get(&sg_isServiceRunning))
		return G_SOURCE_REMOVE;
	/* Guard: timer already running (another thread beat us here) */
	if (g_reprobe_timer_id != 0)
		return G_SOURCE_REMOVE;
	g_reprobe_timer_id = g_timeout_add_seconds(
	        CHANNEL_REPROBE_SEC, reprobe_missing_channels, NULL);
	LOG_N("reprobe timer re-armed from main loop (id=%u)", g_reprobe_timer_id);
	return G_SOURCE_REMOVE;
}

/* -------- video thread -------- */
static gpointer push_data_thread(gpointer user_data)
{
	StreamContext *ctx = (StreamContext *)user_data;

	/* GST-5 Option C: wait for pipeline to reach PLAYING before first push
	 * so get_running_time() has a valid clock from the very first frame.
	 * Timeout after 10 s (2000 * 5 ms) to avoid infinite spin on HW stall. */
	{ gint _wait_ms = 0;
	  while (ctx->isRunning && g_atomic_int_get(&sg_isServiceRunning) &&
	         GST_STATE(ctx->pipeline) != GST_STATE_PLAYING) {
		g_usleep(5000);
		if (++_wait_ms > 2000) {
			ERR_N("[video-push] pipeline did not reach PLAYING in 10 s — aborting");
			return NULL;
		}
	  }
	}

	while (ctx->isRunning && g_atomic_int_get(&sg_isServiceRunning)) {
		int ret = 0;
		GstFlowReturn gret;
		MPI_BUF_SEG_S *seg;
		GstBuffer *buffer = NULL;
		size_t frame_size = 0;
		unsigned char i = 0;
		/* OPT-5: param is only live between MPI_getBitStreamV2 and
		 * MPI_releaseBitStreamV2 within the same iteration — stack-local
		 * is safe and reduces StreamContext footprint by sizeof(param). */
		MPI_STREAM_PARAMS_V2_S param;
		memset(&param, 0, sizeof(MPI_STREAM_PARAMS_V2_S));
		ret = MPI_getBitStreamV2(ctx->mpi_b_channel, &param, 10000);
		if (ret != MPI_SUCCESS) {
			/* ── Sensor / encoder error handling ─────────────
			 * Mirrors AuxVidDeviceSource::getBitStream() errno dispatch:
			 *   -EAGAIN    : no frame ready yet              - silent retry
			 *   -ETIMEDOUT : blocking timeout                - silent retry
			 *   -EINTR     : interrupted by signal           - silent retry
			 *   -EFAULT    : driver fault                    - log, count
			 *   -ENODATA   : encoder stopped (sensor fault)  - recovery retry
			 *                → SENSOR_RECOVERY_MAX attempts with
			 *                  SENSOR_RECOVERY_DELAY_S back-off each;
			 *                  EOS only after all attempts exhausted.
			 *   other      : log, count; recovery after SENSOR_TIMEOUT_MAX.
			 * ─────────────────────────────────────────────────────────── */
			if (ret == -EAGAIN || ret == -ETIMEDOUT || ret == -EINTR) {
				continue;
			} else if (ret == -ENODATA) {
				/* mid-stream sensor recovery retry */
				ERR_N("MPI_getBitStream ENODATA chn=%d: sensor malfunction — attempting recovery",
				      (int)ctx->mpi_b_channel.chn);
				gboolean recovered = FALSE;
				for (int r = 0; r < SENSOR_RECOVERY_MAX && g_atomic_int_get(&sg_isServiceRunning); r++) {
					LOG_N("recovery attempt %d/%d for chn=%d ...",
					      r + 1, SENSOR_RECOVERY_MAX, (int)ctx->mpi_b_channel.chn);
					sleep(SENSOR_RECOVERY_DELAY_S);
					/* Re-probe the MPI encoder channel attribute.
					 * If it succeeds the sensor is back online — resume
					 * the bitstream loop. The existing mpi_b_channel handle
					 * is still valid because MPI_destroyBitStreamChn() has
					 * not been called yet.                                   */
					MPI_ECHN mpi_e_chn = MPI_ENC_CHN((int)ctx->mpi_b_channel.chn);
					MPI_VENC_ATTR_S attr;
					if (MPI_ENC_getVencAttr(mpi_e_chn, &attr) == MPI_SUCCESS) {
						LOG_N("chn=%d sensor recovered on attempt %d — resuming stream",
						      (int)ctx->mpi_b_channel.chn, r + 1);
						ctx->timeout_cnt = 0;
						recovered = TRUE;
						break;
					}
				}
				if (recovered)
					continue; /* back to the top of the bitstream loop */
				ERR_N("chn=%d sensor did not recover after %d attempts — sending EOS",
				      (int)ctx->mpi_b_channel.chn, SENSOR_RECOVERY_MAX);
				/* Serialize all channel state updates onto the GLib main loop:
				 * set_channel_recovery_state_cb writes registered, needs_reprobe,
				 * and reprobe_fail atomically, avoiding any ordering gap (P1).
				 * Check shutdown BEFORE allocating to avoid a memory leak if the
				 * main loop has already stopped (P2).                            */
				if (!g_atomic_int_get(&sg_isServiceRunning))
					goto send_eos_enodata;
				{
					ChannelRecoveryData *d = g_new(ChannelRecoveryData, 1);
					d->chn = (gint)ctx->mpi_b_channel.chn;
					g_main_context_invoke(NULL, set_channel_recovery_state_cb, d);
				}
				if (!g_channel_permanently_absent[ctx->mpi_b_channel.chn])
					g_main_context_invoke(NULL, rearm_reprobe_timer_cb, NULL);
				send_eos_enodata:
				gst_app_src_end_of_stream(GST_APP_SRC(ctx->appsrc));
				if (ctx->audio_appsrc)
					gst_app_src_end_of_stream(GST_APP_SRC(ctx->audio_appsrc));
				ctx->isRunning = false;
				break;
			} else {
				ERR_N("MPI_getBitStream failed: %d (consecutive=%d)", ret, ctx->timeout_cnt + 1);
				ctx->timeout_cnt++;
			}
			if (ctx->timeout_cnt >= SENSOR_TIMEOUT_MAX) {
				/* mid-stream recovery for non-ENODATA errors */
				ERR_N("chn=%d %d consecutive errors — attempting recovery",
				      (int)ctx->mpi_b_channel.chn, ctx->timeout_cnt);
				gboolean recovered = FALSE;
				for (int r = 0; r < SENSOR_RECOVERY_MAX && g_atomic_int_get(&sg_isServiceRunning); r++) {
					LOG_N("recovery attempt %d/%d for chn=%d ...",
					      r + 1, SENSOR_RECOVERY_MAX, (int)ctx->mpi_b_channel.chn);
					sleep(SENSOR_RECOVERY_DELAY_S);
					MPI_ECHN mpi_e_chn = MPI_ENC_CHN((int)ctx->mpi_b_channel.chn);
					MPI_VENC_ATTR_S attr;
					if (MPI_ENC_getVencAttr(mpi_e_chn, &attr) == MPI_SUCCESS) {
						LOG_N("chn=%d sensor recovered on attempt %d — resuming stream",
						      (int)ctx->mpi_b_channel.chn, r + 1);
						ctx->timeout_cnt = 0;
						recovered = TRUE;
						break;
					}
				}
				if (recovered)
					continue; /* back to the top of the bitstream loop */
				ERR_N("chn=%d sensor did not recover after %d attempts — sending EOS",
				      (int)ctx->mpi_b_channel.chn, SENSOR_RECOVERY_MAX);
				/* Same as the ENODATA path: check shutdown before allocating (P2),
				 * then serialize all state updates via set_channel_recovery_state_cb
				 * so registered/needs_reprobe/reprobe_fail are written atomically
				 * on the main loop (P1).                                          */
				if (!g_atomic_int_get(&sg_isServiceRunning))
					goto send_eos_timeout;
				{
					ChannelRecoveryData *d = g_new(ChannelRecoveryData, 1);
					d->chn = (gint)ctx->mpi_b_channel.chn;
					g_main_context_invoke(NULL, set_channel_recovery_state_cb, d);
				}
				if (!g_channel_permanently_absent[ctx->mpi_b_channel.chn])
					g_main_context_invoke(NULL, rearm_reprobe_timer_cb, NULL);
				send_eos_timeout:
				gst_app_src_end_of_stream(GST_APP_SRC(ctx->appsrc));
				if (ctx->audio_appsrc)
					gst_app_src_end_of_stream(GST_APP_SRC(ctx->audio_appsrc));
				ctx->isRunning = false;
				break;
			}
			goto release;
		}
		/* ── Frame segment sanity check ───────────────────────────────
		 * Mirrors AuxVidDeviceSource: seg_cnt < 0 or > MAX => skip frame.
		 * A good frame resets the consecutive-error counter.           */
		if (!param.seg || param.seg_cnt == 0 ||
		    param.seg_cnt > MPI_ENC_MAX_FRAME_SEG_CNT) {
			ERR_N("invalid seg_cnt=%d", param.seg_cnt);
			goto release;
		}
		ctx->timeout_cnt = 0; /* reset on every successfully received frame */

		for (i = 0; i < param.seg_cnt; ++i)
			frame_size += param.seg[i].size;

#ifdef GST_RTSP_SERVER_ENABLE_IVA
		/* ================================================================
		 * SEI injection - mirrors AuxVidDeviceSource::getNextFrame() logic.
		 *
		 * Steps:
		 *	a) build_sei_nalu() assembles SEI into ctx->sei_nalu[].
		 *	b) SEI is prepended at offset 0 (before VPS/SPS/PPS).
		 *	c) Final GstBuffer = sei_nalu[0..sei_size]
		 *					   + frame[0..frame_size]
		 *
		 * NAL order for IDR frame : [SEI][VPS][SPS][PPS][IDR slice]
		 * NAL order for P/B frame : [SEI][P/B slice]
		 *
		 * g_avftr_conn == 0 : SEI disabled.
		 * g_avftr_conn >= 1 : SEI injected when AVFTR has data.
		 * Only H.264 and H.265 carry SEI; JPEG passed through as-is.
		 * ================================================================ */
		int sei_size = 0;

		gboolean do_sei =
		        (g_avftr_conn > 0) &&
		        (ctx->mpi_enc_type == MPI_VENC_TYPE_H264 || ctx->mpi_enc_type == MPI_VENC_TYPE_H265) &&
		        (avftr_res_shm_client != NULL) &&
		        (ctx->sei_nalu != NULL) &&    /* NULL when iva_layout_failed path was taken */
		        (ctx->tmp_sei_str != NULL);

		if (do_sei) {
			uint32_t ts = (uint32_t)(param.jiffies);
			sei_size = build_sei_nalu(ctx, ts);
			/* 0 = no AVFTR data this frame; -1 = AVFTR error - skip */
			if (sei_size <= 0)
				do_sei = FALSE;
		}

		if (do_sei) {
			/* SEI always at offset 0: [SEI][VPS/SPS/PPS][IDR or P/B]
			 * No frame_flat malloc needed - copy MPI segments directly after SEI. */
			buffer = gst_buffer_new_and_alloc(frame_size + (gsize)sei_size);
			if (!buffer) {
				ERR_N("gst_buffer_new_and_alloc failed (with SEI)");
				goto release;
			}
			GstMapInfo map;
			if (!gst_buffer_map(buffer, &map, GST_MAP_WRITE)) {
				ERR_N("Failed to map buffer (with SEI)");
				gst_buffer_unref(buffer);
				goto release;
			}
			/* Step 1: SEI NAL at the very beginning */
			memcpy(map.data, ctx->sei_nalu, (size_t)sei_size);
			/* Step 2: copy MPI segments directly after SEI */
			gsize dst_off = (gsize)sei_size;
			for (guint si = 0; si < param.seg_cnt; si++) {
				seg = &param.seg[si];
				memcpy(map.data + dst_off, seg->uaddr, seg->size);
				dst_off += seg->size;
			}
			gst_buffer_unmap(buffer, &map);
		} else {
			/* No SEI - plain copy (original path) */
#endif /* GST_RTSP_SERVER_ENABLE_IVA */

			buffer = gst_buffer_new_and_alloc(frame_size);
			if (!buffer)
				goto release;

			GstMapInfo map;
			if (!gst_buffer_map(buffer, &map, GST_MAP_WRITE)) {
				ERR_N("Failed to map buffer");
				gst_buffer_unref(buffer);
				goto release;
			}

			size_t offset = 0;
			for (i = 0; i < param.seg_cnt; ++i) {
				seg = &param.seg[i];
				memcpy(map.data + offset, seg->uaddr, seg->size);
				offset += seg->size;
			}
			gst_buffer_unmap(buffer, &map);

#ifdef GST_RTSP_SERVER_ENABLE_IVA
		} /* end else (no SEI) */
#endif /* GST_RTSP_SERVER_ENABLE_IVA */

		/* GST-5: use pipeline clock for PTS/DTS.
		 * Option A: skip frame if clock not ready (GST_CLOCK_TIME_NONE). */
		GstClockTime pts = get_running_time(ctx->pipeline);
		if (pts == GST_CLOCK_TIME_NONE) {
			LOG_N("[video-push] clock not ready — skipping frame");
			gst_buffer_unref(buffer);
			goto release;
		}
		GST_BUFFER_PTS(buffer) = pts;
		GST_BUFFER_DTS(buffer) = pts;
		GST_BUFFER_DURATION(buffer) = gst_util_uint64_scale_int(1, GST_SECOND, ctx->mpi_venc_info.fps);

		/* GST-2: use direct API (returns GstFlowReturn; transfers buffer ownership) */
		gret = gst_app_src_push_buffer(GST_APP_SRC(ctx->appsrc), buffer);
		/* GST-3: stop thread on pipeline shutdown or EOS */
		if (gret == GST_FLOW_FLUSHING || gret == GST_FLOW_EOS) {
			ctx->isRunning = false;
			goto release;
		}

	release:
		ret = MPI_releaseBitStreamV2(ctx->mpi_b_channel, &param);
		if (ret != MPI_SUCCESS)
			ERR_N("Release bit stream failed: %d", ret);
	}

	return NULL;
}

/* -------- push audio data to RTSP pipleline-------- */
static gpointer push_audio_thread(gpointer user_data)
{
	StreamContext *ctx = (StreamContext *)user_data;
	const int channels = AUDIO_CHANNELS;

	/* GST-5 Option C: wait for pipeline to reach PLAYING before first push
	 * so get_running_time() has a valid clock from the very first frame.
	 * Timeout after 10 s (2000 * 5 ms) to avoid infinite spin on HW stall. */
	{ gint _wait_ms = 0;
	  while (ctx->isRunning && g_atomic_int_get(&sg_isServiceRunning) &&
	         GST_STATE(ctx->pipeline) != GST_STATE_PLAYING) {
		g_usleep(5000);
		if (++_wait_ms > 2000) {
			ERR_N("[audio-push] pipeline did not reach PLAYING in 10 s — aborting");
			return NULL;
		}
	  }
	}

	while (ctx->isRunning && g_atomic_int_get(&sg_isServiceRunning)) {
		/* OPT-4: allocate a fresh PCM buffer each iteration and read
		 * directly into it.  gst_buffer_new_wrapped() transfers ownership
		 * to GStreamer — eliminates the second alloc + memcpy + map/unmap
		 * that the previous gst_buffer_new_allocate() path required.
		 * Every early-exit path before new_wrapped() must g_free(pcm). */
		gsize pcm_bytes = (gsize)ctx->audio_frame_size * channels * sizeof(int16_t);
		int16_t *pcm = g_malloc(pcm_bytes);

		int rc = snd_pcm_readi(ctx->pcm_handle, pcm, ctx->audio_frame_size);
		if (rc == -EPIPE) {
			g_free(pcm);
			snd_pcm_prepare(ctx->pcm_handle);
			continue;
		} else if (rc < 0) {
			g_free(pcm);
			ERR_N("ALSA read error: %s", snd_strerror(rc));
			continue;
		}

		/* pcm ownership transfers to gst_buf — do NOT g_free(pcm) after this */
		GstBuffer *gst_buf = gst_buffer_new_wrapped(pcm,
		                         (gsize)rc * channels * sizeof(int16_t));
		if (!gst_buf) {
			g_free(pcm); /* new_wrapped failed — reclaim pcm before continuing */
			continue;
		}

		GstClockTime dur = gst_util_uint64_scale_int(rc, GST_SECOND, AUDIO_RATE);

		/* GST-5: use pipeline clock for PTS/DTS.
		 * Option A: skip frame if clock not ready (GST_CLOCK_TIME_NONE). */
		GstClockTime pts = get_running_time(ctx->pipeline);
		if (pts == GST_CLOCK_TIME_NONE) {
			LOG_N("[audio-push] clock not ready — skipping frame");
			gst_buffer_unref(gst_buf); /* also frees pcm via GstMemory */
			continue;
		}
		GST_BUFFER_PTS(gst_buf) = pts;
		GST_BUFFER_DTS(gst_buf) = pts;
		GST_BUFFER_DURATION(gst_buf) = dur; /* sample-based: rc * GST_SECOND / AUDIO_RATE */

		/* GST-2: use direct API (returns GstFlowReturn; transfers buffer ownership) */
		GstFlowReturn gret = gst_app_src_push_buffer(GST_APP_SRC(ctx->audio_appsrc), gst_buf);
		/* GST-3: stop thread on pipeline shutdown or EOS */
		if (gret == GST_FLOW_FLUSHING || gret == GST_FLOW_EOS) {
			ctx->isRunning = false;
			break;
		}
	}

	return NULL;
}

#define DEFAULT_VQUEUE_MAX_BYTES  4194304U   /* 4 MB  */
#define DEFAULT_AQUEUE_MAX_BYTES   524288U   /* 512 KB */

/* create pipeline */
static GstElement *augentix_rtsp_elements_create(MPI_VENC_TYPE_E type, guint vqueue_max_bytes, guint aqueue_max_bytes)
{
	AugentixRtspElements *elements = g_new0(AugentixRtspElements, 1);

	/* All supported types carry audio (H.264/H.265/MJPEG/JPEG) */
	gboolean enable_audio = (type == MPI_VENC_TYPE_H264 || type == MPI_VENC_TYPE_H265 ||
							type == MPI_VENC_TYPE_MJPEG || type == MPI_VENC_TYPE_JPEG);
	/* video appsrc */
	elements->source    = gst_element_factory_make("appsrc",                       "appsrc");
	elements->vqueue    = gst_element_factory_make("queue",                        "vqueue");
	elements->parser    = gst_element_factory_make(sgMap[type].parser_name,        "parser");
	elements->payloader = gst_element_factory_make(sgMap[type].payloader_name,     "payloader");

	guint vmax = (vqueue_max_bytes > 0) ? vqueue_max_bytes : DEFAULT_VQUEUE_MAX_BYTES;
	guint amax = (aqueue_max_bytes > 0) ? aqueue_max_bytes : DEFAULT_AQUEUE_MAX_BYTES;

	/* GST-4: bound video queue to 4 MB; drop new frames when full (leaky=downstream) */
	if (elements->vqueue) {
		g_object_set(G_OBJECT(elements->vqueue),
		             "max-size-bytes",   vmax,
		             "max-size-buffers", (guint)0,
		             "max-size-time",    (guint64)0,
		             "leaky",            (gint)2,
		             NULL);
	}

	if (enable_audio) {
		/* audio elements */
		elements->asource      = gst_element_factory_make("appsrc",       "asource");
		elements->aqueue       = gst_element_factory_make("queue",        "aqueue");
		elements->audioconvert = gst_element_factory_make("audioconvert", "audioconvert");
		/*elements->audioresample = gst_element_factory_make("audioresample", "audioresample");*/
		elements->apayloader   = gst_element_factory_make("rtpL16pay",    "apayloader");

		/* GST-4: bound audio queue to 512 KB; drop new frames when full (leaky=downstream) */
		if (elements->aqueue) {
			g_object_set(G_OBJECT(elements->aqueue),
			             "max-size-bytes",   amax,
			             "max-size-buffers", (guint)0,
			             "max-size-time",    (guint64)0,
			             "leaky",            (gint)2,
			             NULL);
		}
	}

	if (!elements->source || !elements->vqueue || !elements->parser || !elements->payloader ||
	    (enable_audio && (!elements->asource || !elements->aqueue ||
	                      !elements->audioconvert || !elements->apayloader))) {
		ERR_N("Failed to create elements. parser:%s payloader:%s",
		      sgMap[type].parser_name, sgMap[type].payloader_name);
		g_free(elements);
		return NULL;
	}

	GstElement *pipeline = gst_pipeline_new("augentix-pipeline");
	if (!pipeline) {
		ERR_N("Failed to create pipeline.");
		g_free(elements);
		return NULL;
	}

	/* video caps */
	GstCaps *src_caps = NULL;
	if (type == MPI_VENC_TYPE_H264 || type == MPI_VENC_TYPE_H265) {
		src_caps = gst_caps_new_simple(sgMap[type].codec_name,
		                               "stream-format", G_TYPE_STRING, "byte-stream",
		                               "alignment",     G_TYPE_STRING, "au",
		                               NULL);
	} else {
		/* MJPEG/JPEG: minimal caps; width/height updated later in media_configure() */
		src_caps = gst_caps_new_empty_simple(sgMap[type].codec_name);
	}
	/* GST-1: block=FALSE — non-blocking push; FLUSHING return handled by GST-3 guard */
	g_object_set(G_OBJECT(elements->source), "caps", src_caps, "is-live", TRUE, "block", FALSE, "format",
	             GST_FORMAT_TIME, "do-timestamp", FALSE, NULL);
	gst_caps_unref(src_caps);

	guint pt = (type == MPI_VENC_TYPE_MJPEG || type == MPI_VENC_TYPE_JPEG) ? 26 : 96;
	g_object_set(elements->payloader, "name", "pay0", "pt", pt, NULL);

	/* For MJPEG/JPEG: configure identity as a simple pass-through (no sync delay) */
	if (type == MPI_VENC_TYPE_MJPEG || type == MPI_VENC_TYPE_JPEG) {
		g_object_set(elements->parser, "sync", FALSE, "silent", TRUE, NULL);
	}

	/* bin: video elements */
	gst_bin_add_many(GST_BIN(pipeline),
	                 elements->source, elements->vqueue, elements->parser, elements->payloader,
	                 NULL);

	if (!gst_element_link_many(elements->source, elements->vqueue, elements->parser, elements->payloader, NULL)) {
		ERR_N("Failed to link video elements.");
		gst_object_unref(pipeline);
		g_free(elements);
		return NULL;
	}

	if (enable_audio) {
		/* audio caps for appsrc: raw PCM S16LE */
		GstCaps *acaps = gst_caps_new_simple("audio/x-raw",
		                                     "format",   G_TYPE_STRING, "S16LE",
		                                     "channels", G_TYPE_INT,    AUDIO_CHANNELS,
		                                     "rate",     G_TYPE_INT,    AUDIO_RATE,
		                                     "layout",   G_TYPE_STRING, "interleaved",
		                                     NULL);
		/* GST-1: block=FALSE — non-blocking push; FLUSHING return handled by GST-3 guard */
		g_object_set(G_OBJECT(elements->asource), "caps", acaps, "is-live", TRUE, "block", FALSE, "format",
		             GST_FORMAT_TIME, "do-timestamp", FALSE, NULL);
		gst_caps_unref(acaps);
		g_object_set(elements->apayloader, "name", "pay1", "pt", 97, NULL);

		gst_bin_add_many(GST_BIN(pipeline),
		                 elements->asource, elements->aqueue, elements->audioconvert,
		                 /*elements->audioresample,*/ elements->apayloader,
		                 NULL);

		if (!gst_element_link_many(elements->asource, elements->aqueue, elements->audioconvert,
		                           /*elements->audioresample,*/ elements->apayloader, NULL)) {
			ERR_N("Failed to link audio elements.");
			gst_object_unref(pipeline);
			g_free(elements);
			return NULL;
		}
	}

	g_object_set_data_full(G_OBJECT(pipeline), "custom-data", elements, g_free);

	return pipeline;
}

/* factory create_element */
static GstElement *augentix_media_factory_create_element(GstRTSPMediaFactory *factory, const GstRTSPUrl *url)
{
	(void)url;
	AugentixMediaFactory *self = AUGENTIX_MEDIA_FACTORY(factory);
	int ret = 0;
	MPI_ECHN mpi_e_channel = MPI_ENC_CHN(self->channel_idx);
	MPI_VENC_ATTR_S attr;
	ret = MPI_ENC_getVencAttr(mpi_e_channel, &attr);

	if (ret != MPI_SUCCESS) {
		ERR_N("MPI_ENC_getVencAttr failed: %d (channel_idx=%d)", ret, self->channel_idx);
		return NULL;
	}

	LOG_N("channel_idx=%d enc_type=%d", self->channel_idx, attr.type);

	GstElement *pipeline = augentix_rtsp_elements_create(
		attr.type,
		g_channel_conf[self->channel_idx].vqueue_max_bytes,
		g_channel_conf[self->channel_idx].aqueue_max_bytes);
	if (!pipeline) {
		ERR_N("Failed to create pipeline");
		return NULL;
	}

	return pipeline;
}

static void augentix_media_factory_class_init(AugentixMediaFactoryClass *klass)
{
	GstRTSPMediaFactoryClass *factory_class = GST_RTSP_MEDIA_FACTORY_CLASS(klass);
	factory_class->create_element = augentix_media_factory_create_element;
}
/* -------- class init -------- */
static void augentix_media_factory_init(AugentixMediaFactory *factory)
{
	factory->channel_idx = 0;
}
/* ---------------------------------------------------------------------------
 * is_channel_available() — probe whether MPI encoder channel <chn_idx> is
 * configured and ready.  Uses the same MPI_ENC_getVencAttr() call that
 * augentix_media_factory_create_element() would eventually call so that we
 * detect unavailable channels at server startup rather than at connect-time.
 *
 * Returns: TRUE  — channel is present and has a valid encoder attribute
 *          FALSE — channel is absent / not yet configured
 * -------------------------------------------------------------------------*/
static gboolean is_channel_available(gint chn_idx)
{
	MPI_ECHN mpi_e_channel = MPI_ENC_CHN(chn_idx);
	MPI_VENC_ATTR_S attr;
	int ret = MPI_ENC_getVencAttr(mpi_e_channel, &attr);
	if (ret != MPI_SUCCESS) {
		LOG_D("channel %d not available (MPI_ENC_getVencAttr ret=%d) — skipping", chn_idx, ret);
		return FALSE;
	}
	LOG_D("channel %d available (enc_type=%d)", chn_idx, attr.type);
	return TRUE;
}

static GstRTSPMediaFactory *augentix_media_factory_new(gint channel_idx)
{
	AugentixMediaFactory *factory = g_object_new(AUGENTIX_TYPE_MEDIA_FACTORY, NULL);
	factory->channel_idx = channel_idx;
	return GST_RTSP_MEDIA_FACTORY(factory);
}
static void augentix_rtsp_media_class_init(AugentixRTSPMediaClass *klass)
{
	(void)klass;
}
static void augentix_rtsp_media_init(AugentixRTSPMedia *media)
{
	(void)media;
}

/* media_configure */
static void media_configure(GstRTSPMediaFactory *factory, GstRTSPMedia *media, gpointer user_data)
{
	(void)factory;

	/* GST-9: prevent double-configure on reconnect — if rtsp-extra-data is
	 * already set, this media object was already configured on a previous
	 * connect; skip entirely to avoid re-allocating ctx and re-init races. */
	if (g_object_get_data(G_OBJECT(media), "rtsp-extra-data") != NULL)
		return;

	INT32 ret;
	StreamContext *ctx = g_new0(StreamContext, 1);
	ctx->isRunning = true;
	ctx->audio_frame_size = AUDIO_FRAME_SIZE;

	GstElement *element = gst_rtsp_media_get_element(media);
	ctx->pipeline = gst_object_ref(element); /* GST-5: own ref — keeps ctx->pipeline valid after element is unref'd at end of media_configure() */
	ctx->appsrc = gst_bin_get_by_name_recurse_up(GST_BIN(element), "appsrc");
	ctx->audio_appsrc = gst_bin_get_by_name_recurse_up(GST_BIN(element), "asource");

	/* share the same system clock across medias for better A/V sync */
	GstClock *shared_clock = gst_system_clock_obtain();
	gst_pipeline_use_clock(GST_PIPELINE(element), shared_clock);
	gst_object_unref(shared_clock);
	gst_element_set_start_time(GST_ELEMENT(element), GST_CLOCK_TIME_NONE);

	MPI_ECHN mpi_e_channel = MPI_ENC_CHN(GPOINTER_TO_INT(user_data));
	ctx->mpi_b_channel = MPI_createBitStreamChn(mpi_e_channel);

	if (!VALID_MPI_ENC_BCHN(ctx->mpi_b_channel)) {
		ERR_N("MPI_createBitStreamChn failed");
		ctx_free(ctx);
		gst_object_unref(element);
		return;
	}

	ret = MPI_ENC_queryVencInfo(mpi_e_channel, &ctx->mpi_venc_info);
	if (MPI_SUCCESS != ret) {
		ERR_N("MPI_ENC_queryVencInfo Failed");
		ctx_free(ctx);
		gst_object_unref(element);
		return;
	}

	MPI_VENC_ATTR_S p_venc_attr;
	ret = MPI_ENC_getVencAttr(mpi_e_channel, &p_venc_attr);
	if (ret != MPI_SUCCESS) {
		ERR_N("Failed to MPI_ENC_getVencAttr chn:%d.\n", mpi_e_channel.chn);
		ctx_free(ctx);
		gst_object_unref(element);
		return;
	}

	ctx->mpi_enc_type = p_venc_attr.type;

#ifdef GST_RTSP_SERVER_ENABLE_IVA
	/*
	 * IVA context initialization:
	 * Always record the configured window indices (harmless even when
	 * g_avftr_conn == 0).  Only perform MPI layout/ROI queries and SEI
	 * buffer allocation when IVA is actually active (g_avftr_conn > 0),
	 * because those MPI calls can fail on windows that are not configured
	 * by the platform when running without -S.
	 */
	{
		int chn_idx = GPOINTER_TO_INT(user_data);

		/* Record configured window indices (always safe). */
		ctx->iva_idx = g_channel_conf[chn_idx].iva_src_win;
		ctx->dst_idx = g_channel_conf[chn_idx].iva_dst_win;

		if (g_avftr_conn > 0) {
			int iva_ret;
			gboolean iva_ok = TRUE;

			/* get channel layout */
			iva_ret = getWinLayout(ctx->iva_idx, &ctx->src_rect);
			if (iva_ret != 0) {
				ERR_N("IVA ctx[%d] Failed to get src layout — IVA disabled for this session", chn_idx);
				iva_ok = FALSE;
				goto iva_layout_failed;
			}
			iva_ret = getWinLayout(ctx->dst_idx, &ctx->dst_rect);
			if (iva_ret != 0) {
				ERR_N("IVA ctx[%d] Failed to get dst layout — IVA disabled for this session", chn_idx);
				iva_ok = FALSE;
				goto iva_layout_failed;
			}

			/* MJPEG/JPEG: update appsrc caps with real width/height/fps
			 * now that dst_rect and mpi_venc_info are both available.
			 * This is required because rtpjpegpay needs width/height for
			 * RTP header and SDP negotiation (RFC 2435).
			 */
			if ((ctx->mpi_enc_type == MPI_VENC_TYPE_MJPEG ||
			     ctx->mpi_enc_type == MPI_VENC_TYPE_JPEG) &&
			    ctx->appsrc != NULL &&
			    ctx->dst_rect.width > 0 && ctx->dst_rect.height > 0) {
				GstCaps *mjpeg_caps = gst_caps_new_simple("image/jpeg",
				    "width",     G_TYPE_INT,        (gint)ctx->dst_rect.width,
				    "height",    G_TYPE_INT,        (gint)ctx->dst_rect.height,
				    "framerate", GST_TYPE_FRACTION, (gint)ctx->mpi_venc_info.fps, 1,
				    NULL);
				g_object_set(G_OBJECT(ctx->appsrc), "caps", mjpeg_caps, NULL);
				gst_caps_unref(mjpeg_caps);
				LOG_N("IVA ctx[%d] MJPEG appsrc caps updated: %ux%u @ %ufps",
				      chn_idx, ctx->dst_rect.width, ctx->dst_rect.height,
				      ctx->mpi_venc_info.fps);
			}

			/* get channel ROI */
			iva_ret = MPI_DEV_getWindowRoi(ctx->iva_idx, &ctx->src_roi);
			if (iva_ret != 0) {
				ERR_N("IVA ctx[%d] Failed to get src ROI — IVA disabled for this session", chn_idx);
				iva_ok = FALSE;
				goto iva_layout_failed;
			}
			iva_ret = MPI_DEV_getWindowRoi(ctx->dst_idx, &ctx->dst_roi);
			if (iva_ret != 0) {
				ERR_N("IVA ctx[%d] Failed to get dst ROI — IVA disabled for this session", chn_idx);
				iva_ok = FALSE;
				goto iva_layout_failed;
			}

			/* OPT-2: allocate SEI buffers lazily — only when IVA is active.
			 * g_malloc0 zeroes the memory so no separate memset needed.
			 * g_malloc0 never returns NULL (aborts on OOM per GLib contract). */
			ctx->tmp_sei_str = g_malloc0(MAX_SEI_SIZE);
			ctx->sei_nalu    = g_malloc0(MAX_SEI_SIZE);

			LOG_N("IVA ctx[%d] iva_idx(dev=%d,chn=%d,win=%d) "
			      "dst_idx(dev=%d,chn=%d,win=%d)",
			      chn_idx, ctx->iva_idx.dev, ctx->iva_idx.chn, ctx->iva_idx.win,
			      ctx->dst_idx.dev, ctx->dst_idx.chn, ctx->dst_idx.win);
			LOG_N("IVA ctx[%d] src_rect(%u,%u,%u,%u) dst_rect(%u,%u,%u,%u)",
			      chn_idx, ctx->src_rect.x, ctx->src_rect.y,
			      ctx->src_rect.width, ctx->src_rect.height,
			      ctx->dst_rect.x, ctx->dst_rect.y,
			      ctx->dst_rect.width, ctx->dst_rect.height);
			LOG_N("IVA ctx[%d] src_roi(%u,%u,%u,%u) dst_roi(%u,%u,%u,%u)",
			      chn_idx, ctx->src_roi.x, ctx->src_roi.y,
			      ctx->src_roi.width, ctx->src_roi.height,
			      ctx->dst_roi.x, ctx->dst_roi.y,
			      ctx->dst_roi.width, ctx->dst_roi.height);

		iva_layout_failed:
			if (!iva_ok) {
				/* MPI layout/ROI not ready — degrade gracefully: free any
				 * partially-allocated SEI buffers and continue without IVA.
				 * ctx->tmp_sei_str / sei_nalu are set to NULL; the do_sei gate
				 * in push_data_thread checks both != NULL explicitly, so SEI
				 * injection is safely skipped for this session.
				 * The next client reconnect will retry the MPI queries. */
				g_free(ctx->tmp_sei_str); ctx->tmp_sei_str = NULL;
				g_free(ctx->sei_nalu);    ctx->sei_nalu    = NULL;
				LOG_N("IVA ctx[%d] running without SEI injection this session", chn_idx);
			}
		} /* end if (g_avftr_conn > 0) */
	}
#endif /* GST_RTSP_SERVER_ENABLE_IVA */

	/* OPT-3: spawn video push thread with a 256 KB stack instead of the
	 * GLib default (8 MB on Linux).  Push threads use ~1-2 KB of locals
	 * (including MPI_STREAM_PARAMS_V2_S ~628 B on stack after OPT-5);
	 * 256 KB gives ample headroom for MPI/ALSA internal frames.
	 * Validate with /proc/<pid>/status VmStk before reducing to 128 KB. */
	{
		pthread_attr_t _attr;
		pthread_attr_init(&_attr);
		pthread_attr_setstacksize(&_attr, 256 * 1024);
		int _rc = pthread_create(&ctx->thread, &_attr, push_data_thread, ctx);
		pthread_attr_destroy(&_attr);
		if (_rc != 0) {
			ERR_N("pthread_create video thread failed (rc=%d) — aborting media_configure", _rc);
			ctx_free(ctx);
			gst_object_unref(element);
			return;
		}
		ctx->thread_started = TRUE;
	}

	/* audio per mode */
	if (ctx->audio_appsrc) {
		/* use ALSA dsnooper for multi-channel audio data capture */
		if (audio_init_alsa(&ctx->pcm_handle, "dsnooper", AUDIO_RATE, AUDIO_CHANNELS, ctx->audio_frame_size) !=
		    0) {
			ERR_N("Failed to init ALSA capture on '%s'", "dsnooper");
			ctx->pcm_handle = NULL;
		} else {
			pthread_attr_t _aattr;
			pthread_attr_init(&_aattr);
			pthread_attr_setstacksize(&_aattr, 256 * 1024);
			int _arc = pthread_create(&ctx->athread, &_aattr, push_audio_thread, ctx);
			pthread_attr_destroy(&_aattr);
			if (_arc != 0) {
				ERR_N("pthread_create audio thread failed (rc=%d) — audio disabled", _arc);
			} else {
				ctx->athread_started = TRUE;
			}
		}
	}

	g_object_set_data_full(G_OBJECT(media), "rtsp-extra-data", ctx, (GDestroyNotify)ctx_free);

	/* GST-10: AVFTR reinit removed — AVFTR_initClient() is called once in
	 * main() before g_main_loop_run(), so it is always ready before any
	 * client can connect. Re-initializing here raced with push threads
	 * already using AVFTR state and leaked the previous AVFTR context. */

	gst_object_unref(element);
}


/* ── print_running_config() ────────────────────────────────────────────────────
 * Prints all active runtime configuration parameters to the log immediately
 * after the server is fully initialised.  This gives the operator a single
 * reference snapshot in the syslog to confirm exactly what the server is
 * running with, regardless of whether values came from the config file, CLI
 * flags, or built-in defaults.
 * ─────────────────────────────────────────────────────────────────────────── */
static void print_running_config(void)
{
    LOG_N("========================================================");
    LOG_N("  agtx-rtsp-server — Running Configuration");
    LOG_N("========================================================");

    /* ── Config file ── */
    LOG_N("  Config file            : %s%s", g_conf_path,
          g_conf_path_custom ? "  [manual -c]" : "");

    /* ── Server ports ── */
    LOG_N("  RTSP  port             : %s", g_rtsp_port_buf);
#if (RTSPS_support)
    LOG_N("  RTSPS port             : %s  (TLS enabled)", g_rtsps_port_buf);
    LOG_N("  TLS cert               : %s", CERT_path);
    LOG_N("  TLS key                : %s", KEY_path);
#else
    LOG_N("  RTSPS                  : disabled");
#endif

    /* ── Channel detection ── */
    LOG_N("  Platform encoder chns  : %d  (detected at startup)",
          g_active_channel_num);
    LOG_N("  CHANNEL_NUM (max)      : %d", CHANNEL_NUM);

    /* ── Sensor recovery tuning ── */
    LOG_N("  SENSOR_TIMEOUT_MAX     : %d  (consecutive errors before recovery)",
          SENSOR_TIMEOUT_MAX);
    LOG_N("  SENSOR_RECOVERY_MAX    : %d  (re-probe attempts before EOS)",
          SENSOR_RECOVERY_MAX);
    LOG_N("  SENSOR_RECOVERY_DELAY  : %d s (backoff between re-probes)",
          SENSOR_RECOVERY_DELAY_S);
    LOG_N("  CHANNEL_REPROBE_SEC    : %d s (periodic re-probe timer interval)",
          CHANNEL_REPROBE_SEC);
    LOG_N("  CHANNEL_REPROBE_GIVEUP : %d  (give-up after N consecutive failures, 0=infinite)",
          CHANNEL_REPROBE_GIVEUP);

#ifdef GST_RTSP_SERVER_ENABLE_IVA
    /* ── IVA / AVFTR global settings ── */
    LOG_N("  IVA (avftr_conn)        : %s (value=%d)", g_avftr_conn ? "enabled" : "disabled", g_avftr_conn);
    /* ── Per-channel IVA config ── */
    LOG_N("  --------------------------------------------------------");
    LOG_N("  Per-channel IVA configuration:");
    LOG_N("  %-8s  %-20s  %-20s  %s",
          "Channel", "iva_src (chn:win)", "iva_dst (chn:win)", "Registered");
    for (int i = 0; i < CHANNEL_NUM; i++) {
        if (!g_channel_registered[i]) continue;
        LOG_N("  chn %-4d  src=(%d:%d)              dst=(%d:%d)              %s",
              i,
              g_channel_conf[i].iva_src_win.chn,
              g_channel_conf[i].iva_src_win.win,
              g_channel_conf[i].iva_dst_win.chn,
              g_channel_conf[i].iva_dst_win.win,
              g_channel_registered[i] ? "YES" : "NO");
    }
#else
    LOG_N("  IVA / SEI injection    : disabled (build flag not set)");
#endif /* GST_RTSP_SERVER_ENABLE_IVA */

    LOG_N("========================================================");
}
/* Option-D ── detect_platform_channel_count()
 * Probes MPI encoder channels 0..CHANNEL_NUM-1 SEQUENTIALLY and stops at
 * the first failure.  Encoder channels are always contiguous (0,1,…,N-1)
 * so the first absent channel marks the platform upper bound.
 *
 * This is called ONCE at startup (before setup_augentix_rtsp_server()).
 * By setting g_active_channel_num here we avoid calling
 * MPI_ENC_getVencAttr() on channels that will NEVER exist on this SoC,
 * which is what causes the [VPLAT] "ENC N does not exist" syslog spam.
 *
 * Returns: number of encoder channels present (0 … CHANNEL_NUM).        */
static gint detect_platform_channel_count(void)
{
	gint count = 0;
	gint chn_end = g_sensor_chn_start + g_sensor_chn_count;
	if (chn_end > CHANNEL_NUM) chn_end = CHANNEL_NUM;
	for (gint i = g_sensor_chn_start; i < chn_end; i++) {
		MPI_ECHN mpi_e_channel = MPI_ENC_CHN(i);
		MPI_VENC_ATTR_S attr;
		int ret = MPI_ENC_getVencAttr(mpi_e_channel, &attr);
		/* FIX-5: removed stale !g_channel_registered[i] guard — this function is
		 * called before register_channel_factory(), so g_channel_registered[] is
		 * always FALSE at this point and would make count always return 0. */
		if (ret != MPI_SUCCESS) {
			LOG_D("Option-D: channel %d absent (ret=%d) — skip", i, ret);
			continue;
		}
		LOG_D("Option-D: channel %d present (enc_type=%d)", i, attr.type);
		count++;
	}
	LOG_N("Option-D: scan complete — %d/%d sensor-%d channel(s) present (range %d..%d)",
	      count, g_sensor_chn_count, g_sensor_index,
	      g_sensor_chn_start, chn_end - 1);
	return count;
}

/* helper: create and mount one factory for <chn_idx>.
 * Shared by setup_augentix_rtsp_server() (startup) and the periodic
 * re-probe callback (post-startup recovery).
 * Caller must hold the GLib main loop context (i.e. called from the
 * main thread or a g_timeout callback).                             */
static void register_channel_factory(GstRTSPMountPoints *mounts, gint chn_idx)
{
	GstRTSPMediaFactory *factory = augentix_media_factory_new(chn_idx);
	gst_rtsp_media_factory_set_protocols(factory, GST_RTSP_LOWER_TRANS_TCP);
	/* latency=0: valid for TCP (RTSP/RTP over TCP) only.
	 * For UDP transport, increase to accommodate jitter buffer (e.g. 200ms).
	 * Change transport in client URL: rtsp://...?transport=udp if needed. */
	gst_rtsp_media_factory_set_latency(factory, 0);
	gst_rtsp_media_factory_set_shared(factory, TRUE);
	gst_rtsp_media_factory_set_suspend_mode(factory, GST_RTSP_SUSPEND_MODE_NONE);
#if (RTSPS_support)
	gst_rtsp_media_factory_add_role(factory, "anonymous",
	    GST_RTSP_PERM_MEDIA_FACTORY_ACCESS,   G_TYPE_BOOLEAN, TRUE,
	    GST_RTSP_PERM_MEDIA_FACTORY_CONSTRUCT, G_TYPE_BOOLEAN, TRUE, NULL);
#endif
	g_signal_connect(factory, "media-configure", G_CALLBACK(media_configure),
	                 GINT_TO_POINTER(chn_idx));
	gchar *mount_point = g_strdup_printf("/augentix%d", chn_idx);
	gst_rtsp_mount_points_add_factory(mounts, mount_point, factory);
	g_free(mount_point);
	g_channel_registered[chn_idx] = TRUE;
	LOG_N("channel %d dynamically registered as /augentix%d", chn_idx, chn_idx);
}

/* GLib periodic timer callback.
 * Runs every CHANNEL_REPROBE_SEC seconds on the GLib main loop.
 * For every channel that was absent at startup (or lost its factory),
 * it re-probes MPI; if the sensor is now available it registers the
 * factory on the shared mount points so both RTSP (port 8554) and
 * RTSPS (port 9554) immediately serve the new channel.              */
static gboolean reprobe_missing_channels(gpointer user_data)
{
	(void)user_data;
	if (!g_atomic_int_get(&sg_isServiceRunning)) {
		g_reprobe_timer_id = 0;
		return G_SOURCE_REMOVE; /* server is shutting down — stop the timer */
	}
	gint chn_end = g_sensor_chn_start + g_sensor_chn_count;
	if (chn_end > CHANNEL_NUM) chn_end = CHANNEL_NUM;
	/* Track whether any channel still needs future attention.
	 * If none does, we stop the timer (G_SOURCE_REMOVE) so it does not
	 * fire as a no-op wakeup forever.  It will be re-armed from
	 * push_data_thread() the moment a mid-stream death is detected. */
	gboolean any_pending = FALSE;
	for (int i = g_sensor_chn_start; i < chn_end; i++) {
		/* Only reprobe channels that belong to this sensor instance.
		 * Mid-stream deaths are always re-probed; startup-miss channels
		 * are limited to the sensor's declared range (avoids [VPLAT] spam). */
		gboolean is_mid_stream_death = g_channel_needs_reprobe[i];
		if (g_channel_registered[i] && !is_mid_stream_death)
			continue; /* already mounted and healthy — nothing to do */
		/* Permanently absent: startup-miss channel that exhausted
		 * CHANNEL_REPROBE_GIVEUP.  Skip unconditionally — no MPI call,
		 * no pending flag.  Hot-plug is not supported for these channels. */
		if (g_channel_permanently_absent[i])
			continue;
		/* Give-up logic: skip permanently absent channels to avoid
		 * [VPLAT] "ENC N does not exist" syslog flood.
		 * NOTE: do NOT reset g_channel_reprobe_fail[i] here for mid-stream
		 * deaths — the counter is already reset to 0 in push_data_thread at
		 * the moment the death is declared (g_channel_needs_reprobe set TRUE).
		 * Resetting it again on every timer tick would prevent the counter
		 * from accumulating, bypassing the give-up logic entirely for
		 * channels that die and never recover. */
		if (CHANNEL_REPROBE_GIVEUP > 0 &&
		    !is_mid_stream_death &&
		    g_channel_reprobe_fail[i] >= CHANNEL_REPROBE_GIVEUP) {
			/* Mark permanently absent — no further MPI calls ever */
			g_channel_permanently_absent[i] = TRUE;
			LOG_N("chn=%d: %d consecutive reprobe failures — permanently discarded "
			      "(channel not present on this platform)",
			      i, CHANNEL_REPROBE_GIVEUP);
			continue;
		}
		/* This channel still needs attention on future ticks */
		any_pending = TRUE;
		if (!is_channel_available(i)) {
			g_channel_reprobe_fail[i]++;
			if (CHANNEL_REPROBE_GIVEUP > 0 &&
			    g_channel_reprobe_fail[i] >= CHANNEL_REPROBE_GIVEUP) {
				/* Will be permanently discarded on next tick's give-up guard */
				LOG_N("chn=%d: %d consecutive reprobe failures — silencing further probes "
				      "(channel not present on this platform)",
				      i, CHANNEL_REPROBE_GIVEUP);
			}
			continue; /* still not ready */
		}
		/* Sensor is now available — register (or re-register) the factory */
		g_channel_reprobe_fail[i] = 0; /* reset on success */
		register_channel_factory(g_mounts, i);
		g_channel_needs_reprobe[i] = FALSE;
		LOG_N("chn=%d factory re-registered after sensor-%d recovery", i, g_sensor_index);
	}
	if (!any_pending) {
		/* All channels are either registered or permanently absent.
		 * Stop the timer — it will be re-armed from push_data_thread()
		 * if a mid-stream death occurs on a non-permanently-absent channel. */
		LOG_N("reprobe timer stopped — all channels settled (registered or permanently absent)");
		g_reprobe_timer_id = 0;
		return G_SOURCE_REMOVE;
	}
	return G_SOURCE_CONTINUE; /* channels still pending — keep the timer running */
}

static gboolean setup_augentix_rtsp_server(void)
{
	/* ---------- RTSP server: sensor-%d port %s ---------- */
	LOG_N("Setting up RTSP server for sensor-%d on port %s (channels %d..%d)",
	      g_sensor_index, g_rtsp_port_buf,
	      g_sensor_chn_start, g_sensor_chn_start + g_sensor_chn_count - 1);
	server_inst = gst_rtsp_server_new();
	g_object_set(server_inst, "service", g_rtsp_port_buf, NULL);

	/* Create mount points and attach a media factory for every channel */
	GstRTSPMountPoints *mounts = gst_rtsp_server_get_mount_points(server_inst);

	/* Option-D: detect platform encoder count ONCE before the loop so
	 * we never call MPI_ENC_getVencAttr() on channels beyond the SoC's
	 * physical upper bound.  This eliminates [VPLAT] ENC-N-does-not-
	 * exist syslog spam at startup.                                    */
	g_active_channel_num = detect_platform_channel_count();
	LOG_N("Option-D: platform reports %d encoder channel(s)", g_active_channel_num);

	int active_channels = 0;
	gint chn_end_setup = g_sensor_chn_start + g_sensor_chn_count;
	if (chn_end_setup > CHANNEL_NUM) chn_end_setup = CHANNEL_NUM;
	for (int i = g_sensor_chn_start; i < chn_end_setup; i++) {
		/* ── Dynamic channel availability check (this sensor's range only) ──
		 * Only probe channels that belong to this sensor instance.
		 * This prevents [VPLAT] syslog spam and stops the other sensor's
		 * channels from being registered in this instance.
		 * ─────────────────────────────────────────────────────────────────*/
		if (!is_channel_available(i)) {
			LOG_D("sensor-%d channel %d skipped (not available)",
			      g_sensor_index, i);
			continue;
		}
		register_channel_factory(mounts, i);
		active_channels++;
		LOG_N("sensor-%d channel %d registered as /augentix%d",
		      g_sensor_index, i, i);
	}

	if (active_channels == 0) {
		ERR_N("No available encoder channels for sensor-%d (range %d..%d)",
		      g_sensor_index, g_sensor_chn_start, chn_end_setup - 1);
	} else {
		LOG_N("%d/%d sensor-%d channel(s) registered",
		      active_channels, g_sensor_chn_count, g_sensor_index);
	}

	/* attach RTSP server */
	server_id = gst_rtsp_server_attach(server_inst, NULL);
	if (server_id == 0) {
		ERR_N("Failed to attach RTSP server");
		g_object_unref(mounts);
		return FALSE;
	}

	LOG_N("Augentix RTSP server ready on port %s (sensor-%d)", g_rtsp_port_buf, g_sensor_index);

#if (RTSPS_support)
	/* ---------- RTSPS server: sensor-%d port %s ---------- */
	server_tls_inst = gst_rtsp_server_new();
	g_object_set(server_tls_inst, "service", g_rtsps_port_buf, NULL);

	GstRTSPAuth *auth = gst_rtsp_auth_new();
	GTlsCertificate *cert = create_default_tls_certificate();

	if (cert) {
		/* Configure TLS certificate — server cert only (client cert not required) */
		gst_rtsp_auth_set_tls_certificate(auth, cert);
		g_object_unref(cert);

		gst_rtsp_auth_set_tls_authentication_mode(auth, G_TLS_AUTHENTICATION_NONE);

		/* Use anonymous token to match the factory role set above */
		GstRTSPToken *token =
		        gst_rtsp_token_new(GST_RTSP_TOKEN_MEDIA_FACTORY_ROLE, G_TYPE_STRING, "anonymous", NULL);
		gst_rtsp_auth_set_default_token(auth, token);
		gst_rtsp_token_unref(token);

		gst_rtsp_server_set_auth(server_tls_inst, auth);
		g_object_unref(auth);

		/* Share the same mount points with the TLS server (same pipeline / factory) */
		gst_rtsp_server_set_mount_points(server_tls_inst, g_object_ref(mounts));

		server_tls_id = gst_rtsp_server_attach(server_tls_inst, NULL);
		if (server_tls_id == 0) {
			ERR_N("Failed to attach RTSPS server");
		} else {
			LOG_N("Augentix RTSPS server ready on port %s (sensor-%d)", g_rtsps_port_buf, g_sensor_index);
		}
	} else {
		ERR_N("RTSPS_support is enabled but TLS certificate could not be loaded");
		g_object_unref(auth);
	}
#endif

	/* keep a ref to mounts so the periodic re-probe callback
	 * can add factories after startup without re-querying the server.
	 * Both RTSP (port 8554) and RTSPS (port 9554) share this same
	 * GstRTSPMountPoints object, so any factory added here is instantly
	 * visible on both protocols.                                        */
	g_mounts = g_object_ref(mounts);
	g_reprobe_timer_id = g_timeout_add_seconds(
	        CHANNEL_REPROBE_SEC, reprobe_missing_channels, NULL);
	LOG_N("periodic channel re-probe timer started (id=%u, %ds interval)",
	      g_reprobe_timer_id, CHANNEL_REPROBE_SEC);

	g_object_unref(mounts);

	char ipaddr[32] = { 0 }; //get IP address
	if (get_ipv4_of_iface("eth0", ipaddr, sizeof(ipaddr)) < 0) {
		/* try wlan0 if there is no eth0 */
		if (get_ipv4_of_iface("wlan0", ipaddr, sizeof(ipaddr)) < 0)
			strncpy(ipaddr, "127.0.0.1", sizeof(ipaddr));
	}

	/* Use CHANNEL_NUM (not g_active_channel_num) as the loop bound because
	 * detect_platform_channel_count() now scans all slots without early break,
	 * making g_active_channel_num a plain count of present channels across
	 * potentially non-contiguous indices.  Iterating 0..g_active_channel_num-1
	 * would log the wrong (possibly absent) channels and silently miss the
	 * actually-registered ones at higher indices (e.g. augentix2/augentix3
	 * on a two-sensor platform where sensor-0 channels are broken).         */
	for (int i = 0; i < CHANNEL_NUM; i++) {
		if (!g_channel_registered[i])
			continue; /* channel absent or not yet mounted — skip  */
		LOG_N("Stream URL (RTSP):  rtsp://%s:%s/augentix%d", ipaddr, g_rtsp_port_buf, i);
#if (RTSPS_support)
		LOG_N("Stream URL (RTSPS): rtsps://%s:%s/augentix%d", ipaddr, g_rtsps_port_buf, i);
#endif
	}

	return TRUE;
}

static void signal_handler(int sig)
{
	(void)sig;
	LOG_N("Received SIGINT/SIGTERM, shutting down...");
	g_atomic_int_set(&sg_isServiceRunning, 0); /* stop reprobe timer and push threads first */
	if (loop)
		g_main_loop_quit(loop);
}

static void cleanup(void)
{
#ifdef GST_RTSP_SERVER_ENABLE_IVA
	if (g_avftr_conn && avftr_res_shm_client) {
		if (AVFTR_exitClient(&avftrResShmClientFD, &avftrUnxSktClientFD, &avftr_res_shm_client)) {
			ERR_N("AVFTR_exitClient failed");
		} else {
			LOG_N("AVFTR client exited.");
		}
	}
#endif /* GST_RTSP_SERVER_ENABLE_IVA */

	LOG_N("Cleaning up resources...");

	if (server_inst) {
		if (server_id != 0) {
			g_source_remove(server_id);
			server_id = 0;
		}
		g_object_unref(server_inst);
		server_inst = NULL;
	}

#if (RTSPS_support)
	if (server_tls_inst) {
		if (server_tls_id != 0) {
			g_source_remove(server_tls_id);
			server_tls_id = 0;
		}
		g_object_unref(server_tls_inst);
		server_tls_inst = NULL;
	}
#endif

	/* Stop the reprobe timer if it is still running (e.g. shutdown
	 * happened before all channels settled).                        */
	if (g_reprobe_timer_id != 0) {
		g_source_remove(g_reprobe_timer_id);
		g_reprobe_timer_id = 0;
	}
	/* release the shared mounts reference kept for the
	 * periodic re-probe callback.                                   */
	if (g_mounts) {
		g_object_unref(g_mounts);
		g_mounts = NULL;
	}

	MPI_exitBitStreamSystem();
	MPI_SYS_exit();

	if (loop) {
		g_main_loop_unref(loop);
		loop = NULL;
	}

	LOG_N("Cleanup completed");
}

static bool augentix_mpp_init()
{
	INT32 ret;

	ret = MPI_SYS_init();
	if (ret != MPI_SUCCESS) {
		ERR_N("MPI_SYS_init failed: %d", ret);
		goto exit;
	}

	ret = MPI_initBitStreamSystem();
	if (ret != MPI_SUCCESS) {
		ERR_N("MPI_initBitStreamSystem failed: %d", ret);
		goto exit;
	}

exit:
	return (MPI_SUCCESS == ret) ? true : false;
}

int main(int argc, char *argv[])
{
	signal(SIGINT,  signal_handler);
	signal(SIGTERM, signal_handler);
	/* FIX-4: ignore SIGPIPE so a client TCP disconnect does not kill the server.
	 * Without this, any write() to a broken RTSP/RTP socket raises SIGPIPE whose
	 * default action is process termination. */
	signal(SIGPIPE, SIG_IGN);

#ifdef GST_RTSP_SERVER_ENABLE_IVA
	int opt;
	/* ── Parse CLI: only -s <sensor_index>, -S, -d ──────────────────
	 * -s : select which sensor this instance serves (default: 0)
	 *      derives the .conf path as agtx-rtsp_<N>.conf
	 * -S : force-enable IVA/SEI
	 * -d : enable debug log output
	 * ─────────────────────────────────────────────────────────────── */
	while ((opt = getopt(argc, argv, "s:Sdc:")) != -1) {
		switch (opt) {
		case 's':
			/* Always update g_sensor_index; only derive the auto conf path when
			 * -c was NOT given (-c takes precedence over the auto-derived path). */
			g_sensor_index = atoi(optarg);
			if (g_sensor_index < 0) {
				fprintf(stderr, "Error: -s sensor index must be >= 0\n");
				return -1;
			}
			if (!g_conf_path_custom) {
				snprintf(g_conf_path_buf, sizeof(g_conf_path_buf),
				         RTSP_CONF_DIR "/agtx-rtsp_%d.conf", g_sensor_index);
				g_conf_path = g_conf_path_buf;
			}
			LOG_N("Sensor index: %d  config: %s", g_sensor_index, g_conf_path);
			break;
		case 'c':
			snprintf(g_conf_path_buf, sizeof(g_conf_path_buf), "%s", optarg);
			g_conf_path = g_conf_path_buf;
			g_conf_path_custom = TRUE;
			LOG_N("Config file (manual -c): %s", g_conf_path);
			break;
		case 'S':
			g_avftr_conn = 2;
			break;
		case 'd':
			sg_debug_mode = TRUE;
			break;
		default:
			break;
		}
	}
	optind = 1; /* reset so gst_init() can re-scan argv */
	/* Load sensor-specific .conf — also parses [sensor] section which
	 * sets g_sensor_chn_start, g_sensor_chn_count, g_rtsp_port_buf,
	 * g_rtsps_port_buf.                                               */
	load_rtsp_config(g_conf_path);
#else
	/* Non-IVA build: parse -s and -d; reject -S gracefully.           */
	{
		int opt;
		while ((opt = getopt(argc, argv, "s:Sdc:")) != -1) {
			switch (opt) {
			case 's':
				/* Always update g_sensor_index; only derive the auto conf path
				 * when -c was NOT given (-c takes precedence over auto path). */
				g_sensor_index = atoi(optarg);
				if (g_sensor_index < 0) {
					fprintf(stderr, "Error: -s sensor index must be >= 0\n");
					return -1;
				}
				if (!g_conf_path_custom) {
					snprintf(g_conf_path_buf, sizeof(g_conf_path_buf),
					         RTSP_CONF_DIR "/agtx-rtsp_%d.conf", g_sensor_index);
					g_conf_path = g_conf_path_buf;
				}
				LOG_N("Sensor index: %d  config: %s", g_sensor_index, g_conf_path);
				break;
			case 'c':
				snprintf(g_conf_path_buf, sizeof(g_conf_path_buf), "%s", optarg);
				g_conf_path = g_conf_path_buf;
				g_conf_path_custom = TRUE;
				LOG_N("Config file (manual -c): %s", g_conf_path);
				break;
			case 'd':
				sg_debug_mode = TRUE;
				break;
			case 'S':
				fprintf(stderr, "build config disabled SEI!!\n");
				return 0;
			default:
				break;
			}
		}
		optind = 1;
	}
	load_rtsp_config(g_conf_path);
#endif /* GST_RTSP_SERVER_ENABLE_IVA */

	gst_init(&argc, &argv);
	/* OPT-1A: suppress GStreamer debug log infrastructure in production builds.
	 * Saves ~100-300 KB of static log buffer.
	 * Three escape hatches preserve user debug intent:
	 *   1. GST_DEBUG env var set       (e.g. GST_DEBUG=3)
	 *   2. GST_DEBUG_LEVEL env var set (legacy, some GLib versions)
	 *   3. --gst-debug-level=N passed on CLI: gst_init() raises the threshold
	 *      above GST_LEVEL_NONE internally before we reach this point, so
	 *      gst_debug_get_default_threshold() > GST_LEVEL_NONE means the user
	 *      explicitly requested debug output — skip our suppression. */
	if (!getenv("GST_DEBUG") &&
	    !getenv("GST_DEBUG_LEVEL") &&
	    gst_debug_get_default_threshold() == GST_LEVEL_NONE)
		gst_debug_set_default_threshold(GST_LEVEL_NONE);

	if (!augentix_mpp_init()) {
		ERR_N("failed augentix_mpp_init");
		cleanup();
		return -1;
	}

	if (!setup_augentix_rtsp_server()) {
		ERR_N("Failed to setup RTSP server");
		cleanup();
		return -1;
	}

/* Print all active runtime configuration parameters to syslog */
	print_running_config();

#ifdef GST_RTSP_SERVER_ENABLE_IVA
	/*
	 * AVFTR client init
	 */
	if (g_avftr_conn) {
		LOG_N("Initializing AVFTR client (conn=%d dst_win chn=%d win=%d "
		      "src_win chn=%d win=%d)...",
		      g_avftr_conn, g_avftr_dst_win.chn, g_avftr_dst_win.win, g_avftr_src_win.chn, g_avftr_src_win.win);
		while (AVFTR_initClient(&avftrResShmClientFD, &avftrUnxSktClientFD, &avftr_res_shm_client)) {
			LOG_N("Waiting for AVFTR server ready...");
			sleep(1);
		}
		LOG_N("AVFTR client initialized.");
	}
#endif /* GST_RTSP_SERVER_ENABLE_IVA */

	loop = g_main_loop_new(NULL, FALSE);
	LOG_N("Server running...");
	g_main_loop_run(loop);

	LOG_N("Shutting down...");
	cleanup();
	return 0;
}
