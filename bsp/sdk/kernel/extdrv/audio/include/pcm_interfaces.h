#ifndef PCM_INTERFACES_H_
#define PCM_INTERFACES_H_

/* Codec mode */
typedef enum {
	RAW = 0,
	A_LAW,
	MU_LAW,
	G726_4_LE,
	G726_4_BE,
	G726_2_LE,
	G726_2_BE,
} codec_mode_t;

typedef struct anr_params {
	uint8_t window_size_opt; /* [0, 1, 2], default:2 */
	uint8_t auto_noise_mag; /* [true, false], default:false */
	uint16_t noise_mag_thd; /* [0:1023], default:600   */
	uint8_t large_mag_gain; /* [1~7], default:1        */
	uint8_t noise_level_rto; /* [1, 2, 4, 8], default:4 */
	uint8_t global_min_avg_iir_wei; /* [0:16], default:15 */
	uint8_t global_avg_to_nthd_rate; /* [0:31], default:9 */
	uint16_t noise_mag_auto_thd_base; /* [0:2047], default:790 */
	uint16_t nr_min_level; /* [0:256], default:50 */
	uint16_t nr_max_level; /* [0:256], default:230 */
	uint8_t gaindecade_en; /* [true, false], default:true */
	uint16_t gain_decrease; /* [20:2000], default:500 */
	uint8_t gain_increase; /* [20:200], default:30 */
} AnrParams;

#define AGTX_AUDIO_IOCTL_SET_ANR_ENABLE _IOW('N', 0x0, unsigned char)
#define AGTX_AUDIO_IOCTL_GET_ANR_ENABLE _IOR('N', 0x1, unsigned char)
#define AGTX_AUDIO_IOCTL_SET_ANR_PARAMS _IOW('N', 0x2, struct anr_params)
#define AGTX_AUDIO_IOCTL_GET_ANR_PARAMS _IOR('N', 0x3, struct anr_params)

/* Ioctl for update codec mode */
#define HC_IOCTL_SET_DEC_MODE   _IOW('D', 0x0, unsigned int)
#define HC_IOCTL_GET_DEC_MODE   _IOR('D', 0x1, unsigned int)

#define HC_IOCTL_SET_ENC_MODE   _IOW('E', 0x0, unsigned int)
#define HC_IOCTL_GET_ENC_MODE   _IOR('E', 0x1, unsigned int)

#define HC_IOCTL_VIOLATION_DIS  _IO('V', 0x0)
#define HC_IOCTL_VIOLATION_EN   _IO('V', 0x1)

#endif /* PCM_INTERFACES_H_ */
