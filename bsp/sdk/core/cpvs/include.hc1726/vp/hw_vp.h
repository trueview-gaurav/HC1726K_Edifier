/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef HW_VP_H_
#define HW_VP_H_

#include "csr_bank_vp.h"
#include "csr_bank_me.h"
#include "csr_bank_nr.h"

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/* clang-format off */

/* enum of mux select */

typedef enum vp_dhz_sel {
	VP_DHZ_SEL_VP0 = 0,
	VP_DHZ_SEL_VP1,
	VP_DHZ_SEL_VP2,
	VP_DHZ_SEL_NONE = 0,
} VpDhzSel;

typedef enum vp_mcvp_sel {
	VP_MCVP_SEL_DHZ = 0,
	VP_MCVP_SEL_VP0,
	VP_MCVP_SEL_VP1,
	VP_MCVP_SEL_VP2,
	VP_MCVP_SEL_NONE = 0,
} VpMcvpSel;

typedef enum vp_unpacker_sel {
	VP_UNPACKER_SEL_MCVP = 0,
	VP_UNPACKER_SEL_MCVP_INK,
	VP_UNPACKER_SEL_NONE = 0,
} VpUnpackerSel;

typedef enum vp_vppup0_sel {
	VP_VPPUP0_SEL_B2R = 0,
	VP_VPPUP0_SEL_VP1,
	VP_VPPUP0_SEL_VP2,
	VP_VPPUP0_SEL_DHZ,
	VP_VPPUP0_SEL_NONE = 0,
} VpVppup0Sel;

typedef enum vp_vpw0_sel {
	VP_VPW0_SEL_B2R = 0,
	VP_VPW0_SEL_DHZ,
	VP_VPW0_SEL_VP1,
	VP_VPW0_SEL_VP2,
	VP_VPW0_SEL_VPPUP1,
	VP_VPW0_SEL_NONE = 0,
} VpVpw0Sel;

typedef enum vp_vpw1_sel {
	VP_VPW1_SEL_B2R = 0,
	VP_VPW1_SEL_DHZ,
	VP_VPW1_SEL_VP1,
	VP_VPW1_SEL_VP2,
	VP_VPW1_SEL_VPPUP0,
	VP_VPW1_SEL_NONE = 0,
} VpVpw1Sel;

/* union of broadcast */

typedef union vp_vp0_brdcst {
	struct {
		uint8_t to_dhz  : 1;
		uint8_t to_mcvp : 1;
		uint8_t : 6; /* padding */
	};
	uint8_t value;
} VpVp0Brdcst;

typedef union vp_vp12_brdcst {
	struct {
		uint8_t to_dhz    : 1;
		uint8_t to_mcvp   : 1;
		uint8_t to_vppup0 : 1;
		uint8_t to_vpw0   : 1;
		uint8_t to_vpw1   : 1;
		uint8_t : 3; /* padding */
	};
	uint8_t value;
} VpVp12Brdcst;

typedef union vp_dhz_brdcst {
	struct {
		uint8_t to_mcvp   : 1;
		uint8_t to_vppup0 : 1;
		uint8_t to_vpw0   : 1;
		uint8_t to_vpw1   : 1;
		uint8_t : 3; /* padding */
	};
	uint8_t value;
} VpDhzBrdcst;

typedef union vp_b2r_brdcst {
	struct {
		uint8_t to_vppup0 : 1;
		uint8_t to_vpw0   : 1;
		uint8_t to_vpw1   : 1;
		uint8_t : 5; /* padding */
	};
	uint8_t value;
} VpB2rBrdcst;

typedef union vp_vppup1_brdcst {
	struct {
		uint8_t to_vplp : 1;
		uint8_t to_vpw0 : 1;
		uint8_t : 6;
	};
	uint8_t value;
} VpVppup1Brdcst;

typedef struct vp_path_cfg {
	/* mux select */
	VpDhzSel      dhz_sel;
	VpMcvpSel     mcvp_sel;
	VpUnpackerSel unpacker_sel;
	VpVppup0Sel   vppup0_sel;
	VpVpw0Sel     vpw0_sel;
	VpVpw1Sel     vpw1_sel;

	/* broadcast */
	VpVp0Brdcst  isp0_brdcst;
	VpVp12Brdcst isp1_brdcst;
	VpVp12Brdcst isp2_brdcst;
	VpDhzBrdcst  dhz_brdcst;
	VpB2rBrdcst  b2r_brdcst;
	VpVppup1Brdcst vppup1_brdcst;
} VpPathCfg;

void vp_set_path(volatile CsrBankVp *vp, volatile CsrBankMe *me, volatile CsrBankNr *nr, const VpPathCfg *cfg);

#endif /* HW_VP_H_ */
