#ifndef CSR_BANK_IS_CHECKSUM_H_
#define CSR_BANK_IS_CHECKSUM_H_

#ifndef __KERNEL__
#include <stdint.h>
#else
#include <linux/types.h>
#endif

/***  C struct generated from is_checksum  ***/
typedef struct csr_bank_is_checksum {
	/* CLR 10'h00 */
	union {
		uint32_t clr; // word name
		struct {
			uint32_t clear_k : 1;
			uint32_t : 7; // padding bits
			uint32_t clear_d : 1;
			uint32_t : 7; // padding bits
			uint32_t : 8; // padding bits
			uint32_t : 8; // padding bits
		};
	};
	/* FE0_EDP0 10'h04 */
	union {
		uint32_t fe0_edp0; // word name
		struct {
			uint32_t checksum_fe0_edp_0 : 32;
		};
	};
	/* FE0_EDP1 10'h08 */
	union {
		uint32_t fe0_edp1; // word name
		struct {
			uint32_t checksum_fe0_edp_1 : 32;
		};
	};
	/* ISR0 10'h0C */
	union {
		uint32_t isr0; // word name
		struct {
			uint32_t checksum_isr0 : 32;
		};
	};
	/* FE1_EDP0 10'h10 */
	union {
		uint32_t fe1_edp0; // word name
		struct {
			uint32_t checksum_fe1_edp_0 : 32;
		};
	};
	/* FE1_EDP1 10'h14 */
	union {
		uint32_t fe1_edp1; // word name
		struct {
			uint32_t checksum_fe1_edp_1 : 32;
		};
	};
	/* ISR1 10'h18 */
	union {
		uint32_t isr1; // word name
		struct {
			uint32_t checksum_isr1 : 32;
		};
	};
	/* INPUT_ROUTE0 10'h1C */
	union {
		uint32_t input_route0; // word name
		struct {
			uint32_t checksum_input_route_dst0 : 32;
		};
	};
	/* INPUT_ROUTE1 10'h20 */
	union {
		uint32_t input_route1; // word name
		struct {
			uint32_t checksum_input_route_dst1 : 32;
		};
	};
	/* INPUT_ROUTE2 10'h24 */
	union {
		uint32_t input_route2; // word name
		struct {
			uint32_t checksum_input_route_dst2 : 32;
		};
	};
	/* INPUT_ROUTE3 10'h28 */
	union {
		uint32_t input_route3; // word name
		struct {
			uint32_t checksum_input_route_dst3 : 32;
		};
	};
	/* INPUT_ROUTE4 10'h2C */
	union {
		uint32_t input_route4; // word name
		struct {
			uint32_t checksum_input_route_dst4 : 32;
		};
	};
	/* INPUT_ROUTE5 10'h30 */
	union {
		uint32_t input_route5; // word name
		struct {
			uint32_t checksum_input_route_dst5 : 32;
		};
	};
	/* OUTPUT_ROUTE0 10'h34 */
	union {
		uint32_t output_route0; // word name
		struct {
			uint32_t checksum_output_route_dst0 : 32;
		};
	};
	/* OUTPUT_ROUTE1 10'h38 */
	union {
		uint32_t output_route1; // word name
		struct {
			uint32_t checksum_output_route_dst1 : 32;
		};
	};
	/* OUTPUT_ROUTE2 10'h3C */
	union {
		uint32_t output_route2; // word name
		struct {
			uint32_t checksum_output_route_dst2 : 32;
		};
	};
	/* OUTPUT_ROUTE3 10'h40 */
	union {
		uint32_t output_route3; // word name
		struct {
			uint32_t checksum_output_route_dst3 : 32;
		};
	};
	/* PWE0 10'h44 */
	union {
		uint32_t pwe0; // word name
		struct {
			uint32_t checksum_pwe0 : 32;
		};
	};
	/* PWE1 10'h48 */
	union {
		uint32_t pwe1; // word name
		struct {
			uint32_t checksum_pwe1 : 32;
		};
	};
	/* PWE2 10'h4C */
	union {
		uint32_t pwe2; // word name
		struct {
			uint32_t checksum_pwe2 : 32;
		};
	};
	/* PWE3 10'h50 */
	union {
		uint32_t pwe3; // word name
		struct {
			uint32_t checksum_pwe3 : 32;
		};
	};
	/* ISW0_LSB 10'h54 */
	union {
		uint32_t isw0_lsb; // word name
		struct {
			uint32_t checksum_isw0_lsb : 32;
		};
	};
	/* ISW0_MSB 10'h58 */
	union {
		uint32_t isw0_msb; // word name
		struct {
			uint32_t checksum_isw0_msb : 32;
		};
	};
	/* ISW1_LSB 10'h5C */
	union {
		uint32_t isw1_lsb; // word name
		struct {
			uint32_t checksum_isw1_lsb : 32;
		};
	};
	/* ISW1_MSB 10'h60 */
	union {
		uint32_t isw1_msb; // word name
		struct {
			uint32_t checksum_isw1_msb : 32;
		};
	};
	/* ISW2_LSB 10'h64 */
	union {
		uint32_t isw2_lsb; // word name
		struct {
			uint32_t checksum_isw2_lsb : 32;
		};
	};
	/* ISW2_MSB 10'h68 */
	union {
		uint32_t isw2_msb; // word name
		struct {
			uint32_t checksum_isw2_msb : 32;
		};
	};
	/* ISW3_LSB 10'h6C */
	union {
		uint32_t isw3_lsb; // word name
		struct {
			uint32_t checksum_isw3_lsb : 32;
		};
	};
	/* ISW3_MSB 10'h70 */
	union {
		uint32_t isw3_msb; // word name
		struct {
			uint32_t checksum_isw3_msb : 32;
		};
	};
} CsrBankIs_checksum;

#endif