#ifndef AGTX_VIDEO_ISP_H_
#define AGTX_VIDEO_ISP_H_

#include "csr_bank_isp.h"
#include "csr_bank_isp_cfg.h"
#include "csr_bank_ccq.h"
#include "csr_bank_ccqr.h"
#include "csr_bank_ccqw.h"
#include "csr_bank_pg.h"
#include "csr_bank_cs.h"
#include "csr_bank_dms.h"
#include "csr_bank_fcs.h"
#include "csr_bank_dbf.h"
#include "csr_bank_ccm.h"
#include "csr_bank_gma.h"
#include "csr_bank_pca.h"
#include "csr_bank_cst.h"
#include "csr_bank_sc.h"
#include "csr_bank_enh.h"
#include "csr_bank_shp.h"
#include "csr_bank_dhz.h"
#include "csr_bank_vp.h"
#include "csr_bank_mcvp.h"
#include "csr_bank_nr.h"
#include "csr_bank_me.h"
#include "csr_bank_dwb2r.h" // tmp
#include "csr_bank_isp_checksum.h"
#include "csr_bank_ispin_checksum.h"
#include "csr_bank_enh_checksum.h"
#include "csr_bank_vp_checksum.h"

#include "da.h"
#include "utils.h"

#define ISP_USE_CCQ (0)

#define EARLYVIDEO_ISP_FRAME_NUM (3)
#define EARLYVIDEO_ISPIN_ROUTE_NUM (2)
#define EARLYVIDEO_VPW_NUM (2)
#define EARLYVIDEO_MAX_TILE_NUM (16)
#define EARLYVIDEO_SC_TAP (6)
#define EARLYVIDEO_SC_PHASE_PRECISION (20)

#if ISP_USE_CCQ
#define CCQ_CMD_LEN_BYTES (8)
#define CCQ_MAX_CMDS_PER_TILE (256) /* FIXME: Revise this value to 128 after finishing developing */
#define CCQ_OPCODE_START_BIT (58)
#define CCQ_ADDR_START_BIT (32)
#define OP_CODE_OFFSET (CCQ_OPCODE_START_BIT - CCQ_ADDR_START_BIT)
#define CCQ_ADDR_MASK (0x3FFFFF)
#endif

/* ISP data structures */
struct isp_csr {
	/* ISP TOP */
	volatile struct csr_bank_isp *isp;
	volatile struct csr_bank_isp_cfg *isp_cfg;
#if ISP_USE_CCQ
	volatile struct csr_bank_ccq *ccq;
	volatile struct csr_bank_ccqr *ccqr;
	volatile struct csr_bank_ccqw *ccqw;
#endif
	/* ISPIN */
	volatile struct csr_bank_pxr *ispr[EARLYVIDEO_ISPIN_ROUTE_NUM];
	volatile struct csr_bank_pg *pg[EARLYVIDEO_ISPIN_ROUTE_NUM];
	volatile struct csr_bank_cs *cs[EARLYVIDEO_ISPIN_ROUTE_NUM];
	/* RGBP */
	volatile struct csr_bank_dms *dms;
	volatile struct csr_bank_fcs *fcs;
	volatile struct csr_bank_dbf *dbf;
	volatile struct csr_bank_ccm *ccm;
	volatile struct csr_bank_gma *gma;
	volatile struct csr_bank_pca *pca;
	volatile struct csr_bank_cst *cst;
	/* SC */
	volatile struct csr_bank_sc *sc;
	/* ENH + SHP */
	volatile struct csr_bank_enh *enh;
	volatile struct csr_bank_shp *shp;
	/* DHZ */
	volatile struct csr_bank_dhz *dhz;
	/* VP */
	volatile struct csr_bank_vp *vp;
	volatile struct csr_bank_mcvp *mcvp;
	volatile struct csr_bank_me *me;
	volatile struct csr_bank_nr *nr;
	volatile struct csr_bank_mer *mer;
	volatile struct csr_bank_nrw *nrw;
	volatile struct csr_bank_mv8w *mv8w;
	volatile struct csr_bank_mv8r *mv8r;
	volatile struct csr_bank_venc_mvw *venc_mvw;
	volatile struct csr_bank_dwb2r *b2r;
	/* Output */
	volatile struct csr_bank_pxw *vpw[EARLYVIDEO_VPW_NUM];
#if EARLYVIDEO_DEBUG
	volatile struct csr_bank_isp_checksum *isp_checksum;
	volatile struct csr_bank_ispin_checksum *ispin_checksum;
	volatile struct csr_bank_enh_checksum *enh_checksum;
	volatile struct csr_bank_vp_checksum *vp_checksum;
#endif
};

#if ISP_USE_CCQ
struct isp_ccq {
	uint32_t blk_phys_addr; /* The start address of ccq instructions */
	uint32_t curr_virt_addr; /* The current address of ccq instruction */
	uint32_t instruction_length;
};
#endif

struct tile_da_reg {
	struct da_pixel_tile ispr[EARLYVIDEO_ISPIN_ROUTE_NUM];
	struct da_pixel_tile vpw[EARLYVIDEO_VPW_NUM];
	struct da_block_tile nrw;
	struct da_block_tile mer;
	struct da_linear_tile mv8w;
	struct da_linear_tile mv8r;
	struct da_linear_tile venc_mvw;
};

struct isp_buffer_info {
	uint32_t ispr_addr;
	uint32_t nrw_addr;
	uint32_t mer_addr;
	uint32_t mv8w_addr;
	uint32_t mv8r_addr;
	uint32_t venc_mvw_addr;
	uint32_t vpw_addr;
};

struct tile_sc_param {
	uint16_t frame_width_i;
	uint16_t frame_height_i;
	uint16_t frame_width_o;
	uint16_t frame_height_o;
	/* Vertical */
	uint32_t up_scaling_ver;
	uint32_t phase_step_ver;
	uint32_t filt_phase_step_ds_ver;
	int32_t ini_phase_ver;
	int32_t ini_filt_phase_ds_ver;
	int32_t ini_cnt_ver[EARLYVIDEO_SC_TAP];
	/* Horizontal */
	uint32_t up_scaling_hor;
	uint32_t phase_step_hor;
	int32_t filt_phase_step_ds_hor;
	int32_t ini_phase_hor[EARLYVIDEO_MAX_TILE_NUM];
	int32_t ini_filt_phase_ds_hor[EARLYVIDEO_MAX_TILE_NUM];
	int32_t ini_cnt_hor[EARLYVIDEO_MAX_TILE_NUM][EARLYVIDEO_SC_TAP];
	uint16_t tile_width_i[EARLYVIDEO_MAX_TILE_NUM];
	uint16_t tile_width_o[EARLYVIDEO_MAX_TILE_NUM];
	uint32_t crop_o_left[EARLYVIDEO_MAX_TILE_NUM];
};

#define PCA_EEE_WORD_NUM (490)
#define PCA_EOE_WORD_NUM (420)
#define PCA_OEE_WORD_NUM (490)
#define PCA_OOE_WORD_NUM (420)
#define PCA_EEO_WORD_NUM (392)
#define PCA_EOO_WORD_NUM (336)
#define PCA_OEO_WORD_NUM (392)
#define PCA_OOO_WORD_NUM (336)
struct pca_table_cfg {
	int eee[PCA_EEE_WORD_NUM];
	int eoe[PCA_EOE_WORD_NUM];
	int oee[PCA_OEE_WORD_NUM];
	int ooe[PCA_OOE_WORD_NUM];
	int eeo[PCA_EEO_WORD_NUM];
	int eoo[PCA_EOO_WORD_NUM];
	int oeo[PCA_OEO_WORD_NUM];
	int ooo[PCA_OOO_WORD_NUM];
};

struct isp_frame_table {
	uint8_t idx;
	uint8_t binding_path;
	uint8_t bayer_phase;
	/* PCA table */
	struct pca_table_cfg pca_table;
	/* Tile-related information */
	uint8_t tile_n;
	struct tile_info pre_sc[EARLYVIDEO_MAX_TILE_NUM];
	struct tile_info post_sc[EARLYVIDEO_MAX_TILE_NUM];
	struct tile_sc_param sc_param;
	struct tile_da_reg tile_da_reg[EARLYVIDEO_MAX_TILE_NUM];
	struct isp_buffer_info buffer_info;
	/* Frame start */
	uint8_t start_ispr[EARLYVIDEO_ISPIN_ROUTE_NUM];
	uint8_t start_dms;
	uint8_t start_sc;
	uint8_t start_enh;
	uint8_t start_mcvp;
	uint8_t start_vpw[EARLYVIDEO_VPW_NUM];
	/* Input resolution */
	uint16_t frame_width_i;
	uint16_t frame_height_i;
	/* Output resolution */
	uint16_t frame_width_o;
	uint16_t frame_height_o;
};

void isp_sc_set_tile_csr(volatile CsrBankSc *csr, struct tile_sc_param *sc_param, int t);
void isp_sc_set_frame_csr(volatile CsrBankSc *csr, struct tile_sc_param *sc_param);
void isp_calc_sc_ver_param(struct tile_sc_param *sc_param, uint16_t frame_height_i, uint16_t frame_height_o);
void isp_calc_sc_hor_param(struct tile_sc_param *sc_param, uint16_t frame_width_i, uint16_t frame_width_o,
                           const struct tile_info *tile_i, const struct tile_info *tile_o, int tile_n);
void isp_calc_pca_reg(struct isp_frame_table *ftbl);
void isp_pca_set_table_cfg(volatile CsrBankPca *csr, const struct pca_table_cfg *cfg);
void isp_calc_scale_down_tile(struct isp_frame_table *ftbl);
void isp_calc_process_mv_tile(struct isp_frame_table *ftbl);
void isp_calc_da_tile_info(struct isp_frame_table *ftbl);
void isp_print_ftbl(struct isp_frame_table *ftbl);
void isp_print_info(void);
void isp_install_irq_handler(void);
void isp_start_snapshot(void);

#if ISP_USE_CCQ
void isp_ccq_init(struct earlyvideo_drvdata *drvdata);
void isp_write_ccq_cmd(struct earlyvideo_drvdata *drvdata, struct isp_frame_table *ftbl);
void ccq_buf_setting(volatile struct csr_bank_ccqr *ccqr, volatile struct csr_bank_ccqw *ccqw,
                     struct isp_ccq *isp_ccq_s);
void ccq_start(struct earlyvideo_drvdata *drvdata);
#endif

#endif
