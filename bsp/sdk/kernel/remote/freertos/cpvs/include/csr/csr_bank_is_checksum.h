#ifndef CSR_BANK_IS_CHECKSUM_H_
#define CSR_BANK_IS_CHECKSUM_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from is_checksum  ***/
typedef struct csr_bank_is_checksum {
	/* CLR 10'h000 */
	union {
		uint32_t clr; // word name
		struct {
			uint32_t clear : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* ASYNC_FIFO 10'h004 */
	union {
		uint32_t async_fifo; // word name
		struct {
			uint32_t checksum_async_fifo : 32;
		};
	};
	/* FE0_EDP0 10'h008 */
	union {
		uint32_t fe0_edp0; // word name
		struct {
			uint32_t checksum_fe0_edp_0 : 32;
		};
	};
	/* FE0_EDP1 10'h00C */
	union {
		uint32_t fe0_edp1; // word name
		struct {
			uint32_t checksum_fe0_edp_1 : 32;
		};
	};
	/* FE0_ISR 10'h010 */
	union {
		uint32_t fe0_isr; // word name
		struct {
			uint32_t checksum_fe0_isr : 32;
		};
	};
	/* FE1_EDP0 10'h014 */
	union {
		uint32_t fe1_edp0; // word name
		struct {
			uint32_t checksum_fe1_edp_0 : 32;
		};
	};
	/* FE1_EDP1 10'h018 */
	union {
		uint32_t fe1_edp1; // word name
		struct {
			uint32_t checksum_fe1_edp_1 : 32;
		};
	};
	/* FE1_ISR 10'h01C */
	union {
		uint32_t fe1_isr; // word name
		struct {
			uint32_t checksum_fe1_isr : 32;
		};
	};
	/* INPUT_ROUTE0 10'h020 */
	union {
		uint32_t input_route0; // word name
		struct {
			uint32_t checksum_input_route_dst0 : 32;
		};
	};
	/* INPUT_ROUTE1 10'h024 */
	union {
		uint32_t input_route1; // word name
		struct {
			uint32_t checksum_input_route_dst1 : 32;
		};
	};
	/* INPUT_ROUTE2 10'h028 */
	union {
		uint32_t input_route2; // word name
		struct {
			uint32_t checksum_input_route_dst2 : 32;
		};
	};
	/* INPUT_ROUTE3 10'h02C */
	union {
		uint32_t input_route3; // word name
		struct {
			uint32_t checksum_input_route_dst3 : 32;
		};
	};
	/* INPUT_ROUTE4 10'h030 */
	union {
		uint32_t input_route4; // word name
		struct {
			uint32_t checksum_input_route_dst4 : 32;
		};
	};
	/* INPUT_ROUTE5 10'h034 */
	union {
		uint32_t input_route5; // word name
		struct {
			uint32_t checksum_input_route_dst5 : 32;
		};
	};
	/* OUTPUT_ROUTE0 10'h038 */
	union {
		uint32_t output_route0; // word name
		struct {
			uint32_t checksum_output_route_dst0 : 32;
		};
	};
	/* OUTPUT_ROUTE1 10'h03C */
	union {
		uint32_t output_route1; // word name
		struct {
			uint32_t checksum_output_route_dst1 : 32;
		};
	};
	/* OUTPUT_ROUTE2 10'h040 */
	union {
		uint32_t output_route2; // word name
		struct {
			uint32_t checksum_output_route_dst2 : 32;
		};
	};
	/* OUTPUT_ROUTE3 10'h044 */
	union {
		uint32_t output_route3; // word name
		struct {
			uint32_t checksum_output_route_dst3 : 32;
		};
	};
	/* PWE0 10'h048 */
	union {
		uint32_t pwe0; // word name
		struct {
			uint32_t checksum_pwe0 : 32;
		};
	};
	/* PWE1 10'h04C */
	union {
		uint32_t pwe1; // word name
		struct {
			uint32_t checksum_pwe1 : 32;
		};
	};
	/* PWE2 10'h050 */
	union {
		uint32_t pwe2; // word name
		struct {
			uint32_t checksum_pwe2 : 32;
		};
	};
	/* PWE3 10'h054 */
	union {
		uint32_t pwe3; // word name
		struct {
			uint32_t checksum_pwe3 : 32;
		};
	};
} CsrBankIs_checksum;

#endif