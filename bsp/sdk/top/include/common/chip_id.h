#ifndef CHIP_ID_H_
#define CHIP_ID_H_

#include "config.h"
#define HC_CHIP CONFIG_CHIP

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

#define CHIP_ID_MASK 0xFFFFFFF0
#define CHIP_VER_MASK 0x0000000F

#define CHIP_ID(c) ((c)&CHIP_ID_MASK)
#define CHIP_VER(c) ((c)&CHIP_VER_MASK)

#define VER0 0x1
#define VER1 0x2
#define VER2 0x3
#define VER3 0x4
#define VER4 0x5
#define VER5 0x6
#define VER6 0x7
#define VER7 0x8
#define VER8 0x9
#define VER9 0xA
#define VERA 0xB
#define VERB 0xC
#define VERC 0xD
#define VERD 0xE
#define VERE 0xF

#ifndef HC_VER
#define HC_VER VER0
#endif

/** @brief Chip ID marco.
 *
 * The the LSB 4 bits are a hex number reserved for representing different chip versions.
 */
#define HC1802 0x00000010
#define HC1822 0x00000020
#define HC1852 0x00000030
#define HC1882 0x00000040
/*#define HC1892L                           0x00000050*/
#define HC1892 0x00000060
#define HC1892S 0x00000070
#define HC1722 0x00000080
#define HC1732 0x00000090
#define HC1752 0x000000A0
#define HC1772 0x000000B0
#define HC1852S 0x000000C0
#define HC1882S 0x000000D0
#define HC1762 0x000000E0
#define HC1782 0x000000F0
#define HC1702 0x00000100

#define HC1703 0x00000300
#define HC1723S 0x00000400
#define HC1753S 0x00000500
#define HC1783S 0x00000600
#define HC1783S_FPU 0x00000700
#define HC1723 0x00000800
#define HC1753 0x00000900
#define HC1753_FPU 0x00000A00
#define HC1715 0x00000B00
#define HC1705 0x00000C00
#define HC1725_FPU 0x00000D00
#define HC1703L 0x00000E00
#define HC1723I 0x00000F00
#define HC1705I 0x00001000
#define HC1705K 0x00002000
#define HC1725 0x00003000
#define HC1725S 0x00004000
#define HC1706 0x00005000
#define HC1706K 0x00006000
#define HC1705L 0x00007000
#define HC1706H 0x00008000
#define HC1706K_ES 0x00009000
#define HC1785 0x0000A000
#define HC1726 0x0000B000

#define _HC1802(v) (HC1802 | CHIP_VER(v))
#define _HC1822(v) (HC1822 | CHIP_VER(v))
#define _HC1852(v) (HC1852 | CHIP_VER(v))
#define _HC1882(v) (HC1882 | CHIP_VER(v))
/*#define _HC1892L(v)                       (HC1892L | CHIP_VER(v))*/
#define _HC1892(v) (HC1892 | CHIP_VER(v))
#define _HC1892S(v) (HC1892S | CHIP_VER(v))
#define _HC1722(v) (HC1722 | CHIP_VER(v))
#define _HC1732(v) (HC1732 | CHIP_VER(v))
#define _HC1752(v) (HC1752 | CHIP_VER(v))
#define _HC1772(v) (HC1772 | CHIP_VER(v))
#define _HC1852S(v) (HC1852S | CHIP_VER(v))
#define _HC1882S(v) (HC1882S | CHIP_VER(v))
#define _HC1762(v) (HC1762 | CHIP_VER(v))
#define _HC1782(v) (HC1782 | CHIP_VER(v))
#define _HC1702(v) (HC1702 | CHIP_VER(v))

#define _HC1703(v) (HC1703 | CHIP_VER(v))
#define _HC1703L(v) (HC1703L | CHIP_VER(v))
#define _HC1705(v) (HC1705 | CHIP_VER(v))
#define _HC1705I(v) (HC1705I | CHIP_VER(v))
#define _HC1705L(v) (HC1705L | CHIP_VER(v))
#define _HC1705K(v) (HC1705K | CHIP_VER(v))
#define _HC1715(v) (HC1715 | CHIP_VER(v))
#define _HC1723(v) (HC1723 | CHIP_VER(v))
#define _HC1723I(v) (HC1723I | CHIP_VER(v))
#define _HC1723S(v) (HC1723S | CHIP_VER(v))
#define _HC1725(v) (HC1725 | CHIP_VER(v))
#define _HC1725S(v) (HC1725S | CHIP_VER(v))
#define _HC1725_FPU(v) (HC1725_FPU | CHIP_VER(v))
#define _HC1753(v) (HC1753 | CHIP_VER(v))
#define _HC1753S(v) (HC1753S | CHIP_VER(v))
#define _HC1753_FPU(v) (HC1753_FPU | CHIP_VER(v))
#define _HC1783S(v) (HC1783S | CHIP_VER(v))
#define _HC1783S_FPU(v) (HC1783S_FPU | CHIP_VER(v))

#define _HC1706(v) (HC1706 | CHIP_VER(v))
#define _HC1706K(v) (HC1706K | CHIP_VER(v))
#define _HC1706H(v) (HC1706H | CHIP_VER(v))
#define _HC1706K_ES(v) (HC1706K_ES | CHIP_VER(v))
#define _HC1726(v) (HC1726 | CHIP_VER(v))

#define _HC1785(v) (HC1785 | CHIP_VER(v))

#if (HC_CHIP == HC1802)
#if (HC_VER == VER0)
#define CID _HC1802(VER0)
#elif (HC_VER == VER1)
#define CID _HC1802(VER1)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1822)
#if (HC_VER == VER0)
#define CID _HC1822(VER0)
#elif (HC_VER == VER1)
#define CID _HC1822(VER1)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1852)
#if (HC_VER == VER0)
#define CID _HC1852(VER0)
#elif (HC_VER == VER1)
#define CID _HC1852(VER1)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1852S)
#if (HC_VER == VER0)
#define CID _HC1852S(VER0)
#elif (HC_VER == VER1)
#define CID _HC1852S(VER1)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1882)
#if (HC_VER == VER0)
#define CID _HC1882(VER0)
#elif (HC_VER == VER1)
#define CID _HC1882(VER1)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1882S)
#if (HC_VER == VER0)
#define CID _HC1882S(VER0)
#elif (HC_VER == VER1)
#define CID _HC1882S(VER1)
#else
#error "Chip version is not supported."
#endif
/*
#elif (HC_CHIP == HC1892L)
#if (HC_VER == VER0)
#define CID  _HC1892L(VER0)
#elif (HC_VER == VER1)
#define CID  _HC1892L(VER1)
#else
#error "Chip version is not supported."
#endif
*/
#elif (HC_CHIP == HC1892)
#if (HC_VER == VER0)
#define CID _HC1892(VER0)
#elif (HC_VER == VER1)
#define CID _HC1892(VER1)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1892S)
#if (HC_VER == VER0)
#define CID _HC1892S(VER0)
#elif (HC_VER == VER1)
#define CID _HC1892S(VER1)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1722)
#if (HC_VER == VER0)
#define CID _HC1722(VER0)
#elif (HC_VER == VER1)
#define CID _HC1722(VER1)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1732)
#if (HC_VER == VER0)
#define CID _HC1732(VER0)
#elif (HC_VER == VER1)
#define CID _HC1732(VER1)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1752)
#if (HC_VER == VER0)
#define CID _HC1752(VER0)
#elif (HC_VER == VER1)
#define CID _HC1752(VER1)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1762)
#if (HC_VER == VER0)
#define CID _HC1762(VER0)
#elif (HC_VER == VER1)
#define CID _HC1762(VER1)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1772)
#if (HC_VER == VER0)
#define CID _HC1772(VER0)
#elif (HC_VER == VER1)
#define CID _HC1772(VER1)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1782)
#if (HC_VER == VER0)
#define CID _HC1782(VER0)
#elif (HC_VER == VER1)
#define CID _HC1782(VER1)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1702)
#if (HC_VER == VER0)
#define CID _HC1702(VER0)
#elif (HC_VER == VER1)
#define CID _HC1702(VER1)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1703)
#if (HC_VER == VER0)
#define CID _HC1703(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1703L)
#if (HC_VER == VER0)
#define CID _HC1703L(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1705)
#if (HC_VER == VER0)
#define CID _HC1705(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1705I)
#if (HC_VER == VER0)
#define CID _HC1705I(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1705L)
#if (HC_VER == VER0)
#define CID _HC1705L(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1705K)
#if (HC_VER == VER0)
#define CID _HC1705K(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1715)
#if (HC_VER == VER0)
#define CID _HC1715(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1723)
#if (HC_VER == VER0)
#define CID _HC1723(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1723I)
#if (HC_VER == VER0)
#define CID _HC1723I(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1723S)
#if (HC_VER == VER0)
#define CID _HC1723S(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1725)
#if (HC_VER == VER0)
#define CID _HC1725(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1725S)
#if (HC_VER == VER0)
#define CID _HC1725S(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1725_FPU)
#if (HC_VER == VER0)
#define CID _HC1725_FPU(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1753)
#if (HC_VER == VER0)
#define CID _HC1753(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1753S)
#if (HC_VER == VER0)
#define CID _HC1753S(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1753_FPU)
#if (HC_VER == VER0)
#define CID _HC1753_FPU(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1783S)
#if (HC_VER == VER0)
#define CID _HC1783S(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1783S_FPU)
#if (HC_VER == VER0)
#define CID _HC1783S_FPU(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1706)
#if (HC_VER == VER0)
#define CID _HC1706(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1706K)
#if (HC_VER == VER0)
#define CID _HC1706K(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1706H)
#if (HC_VER == VER0)
#define CID _HC1706H(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1706K_ES)
#if (HC_VER == VER0)
#define CID _HC1706K_ES(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1785)
#if (HC_VER == VER0)
#define CID _HC1785(VER0)
#else
#error "Chip version is not supported."
#endif

#elif (HC_CHIP == HC1726)
#if (HC_VER == VER0)
#define CID _HC1726(VER0)
#else
#error "Chip version is not supported."
#endif

#else
#error "CHIP ID is not supported!"
#endif

#define IS_HC1802_SUPPORT (CHIP_ID(CID) == HC1802)
#define IS_HC1802E0_SUPPORT (CID == _HC1802(VER0))
#define IS_HC1802E1_SUPPORT (CID == _HC1802(VER1))

#define IS_HC1822_SUPPORT (CHIP_ID(CID) == HC1822)
#define IS_HC1822E0_SUPPORT (CID == _HC1822(VER0))
#define IS_HC1822E1_SUPPORT (CID == _HC1822(VER1))

#define IS_HC1852_SUPPORT (CHIP_ID(CID) == HC1852)
#define IS_HC1852E0_SUPPORT (CID == _HC1852(VER0))
#define IS_HC1852E1_SUPPORT (CID == _HC1852(VER1))

#define IS_HC1852S_SUPPORT (CHIP_ID(CID) == HC1852S)
#define IS_HC1852SE0_SUPPORT (CID == _HC1852S(VER0))
#define IS_HC1852SE1_SUPPORT (CID == _HC1852S(VER1))

#define IS_HC1882_SUPPORT (CHIP_ID(CID) == HC1882)
#define IS_HC1882E0_SUPPORT (CID == _HC1882(VER0))
#define IS_HC1882E1_SUPPORT (CID == _HC1882(VER1))

#define IS_HC1882S_SUPPORT (CHIP_ID(CID) == HC1882S)
#define IS_HC1882SE0_SUPPORT (CID == _HC1882S(VER0))
#define IS_HC1882SE1_SUPPORT (CID == _HC1882S(VER1))

/*
#define IS_HC1892L_SUPPORT                    (CHIP_ID(CID) == HC1892L)
#define IS_HC1892LE0_SUPPORT                  (CID == _HC1892L(VER0))
#define IS_HC1892LE1_SUPPORT                  (CID == _HC1892L(VER1))
*/
#define IS_HC1892_SUPPORT (CHIP_ID(CID) == HC1892)
#define IS_HC1892E0_SUPPORT (CID == _HC1892(VER0))
#define IS_HC1892E1_SUPPORT (CID == _HC1892(VER1))

#define IS_HC1892S_SUPPORT (CHIP_ID(CID) == HC1892S)
#define IS_HC1892SE0_SUPPORT (CID == _HC1892S(VER0))
#define IS_HC1892SE1_SUPPORT (CID == _HC1892S(VER1))

#define IS_HC1722_SUPPORT (CHIP_ID(CID) == HC1722)
#define IS_HC1722E0_SUPPORT (CID == _HC1722(VER0))
#define IS_HC1722E1_SUPPORT (CID == _HC1722(VER1))

#define IS_HC1732_SUPPORT (CHIP_ID(CID) == HC1732)
#define IS_HC1732E0_SUPPORT (CID == _HC1732(VER0))
#define IS_HC1732E1_SUPPORT (CID == _HC1732(VER1))

#define IS_HC1752_SUPPORT (CHIP_ID(CID) == HC1752)
#define IS_HC1752E0_SUPPORT (CID == _HC1752(VER0))
#define IS_HC1752E1_SUPPORT (CID == _HC1752(VER1))

#define IS_HC1762_SUPPORT (CHIP_ID(CID) == HC1762)
#define IS_HC1762E0_SUPPORT (CID == _HC1762(VER0))
#define IS_HC1762E1_SUPPORT (CID == _HC1762(VER1))

#define IS_HC1772_SUPPORT (CHIP_ID(CID) == HC1772)
#define IS_HC1772E0_SUPPORT (CID == _HC1772(VER0))
#define IS_HC1772E1_SUPPORT (CID == _HC1772(VER1))

#define IS_HC1782_SUPPORT (CHIP_ID(CID) == HC1782)
#define IS_HC1782E0_SUPPORT (CID == _HC1782(VER0))
#define IS_HC1782E1_SUPPORT (CID == _HC1782(VER1))

#define IS_HC1702_SUPPORT (CHIP_ID(CID) == HC1702)
#define IS_HC1702E0_SUPPORT (CID == _HC1702(VER0))
#define IS_HC1702E1_SUPPORT (CID == _HC1702(VER1))

#define IS_HC1703_SUPPORT (CHIP_ID(CID) == HC1703)
#define IS_HC1703E0_SUPPORT (CID == _HC1703(VER0))

#define IS_HC1703L_SUPPORT (CHIP_ID(CID) == HC1703L)
#define IS_HC1703LE0_SUPPORT (CID == _HC1703L(VER0))

#define IS_HC1705_SUPPORT (CHIP_ID(CID) == HC1705)
#define IS_HC1705E0_SUPPORT (CID == _HC1705(VER0))

#define IS_HC1705I_SUPPORT (CHIP_ID(CID) == HC1705I)
#define IS_HC1705IE0_SUPPORT (CID == _HC1705I(VER0))

#define IS_HC1705L_SUPPORT (CHIP_ID(CID) == HC1705L)
#define IS_HC1705LE0_SUPPORT (CID == _HC1705L(VER0))

#define IS_HC1705K_SUPPORT (CHIP_ID(CID) == HC1705K)
#define IS_HC1705KE0_SUPPORT (CID == _HC1705K(VER0))

#define IS_HC1715_SUPPORT (CHIP_ID(CID) == HC1715)
#define IS_HC1715E0_SUPPORT (CID == _HC1715(VER0))

#define IS_HC1723_SUPPORT (CHIP_ID(CID) == HC1723)
#define IS_HC1723E0_SUPPORT (CID == _HC1723(VER0))

#define IS_HC1723I_SUPPORT (CHIP_ID(CID) == HC1723I)
#define IS_HC1723IE0_SUPPORT (CID == _HC1723I(VER0))

#define IS_HC1725_SUPPORT (CHIP_ID(CID) == HC1725)
#define IS_HC1725E0_SUPPORT (CID == _HC1725(VER0))

#define IS_HC1725S_SUPPORT (CHIP_ID(CID) == HC1725S)
#define IS_HC1725SE0_SUPPORT (CID == _HC1725S(VER0))

#define IS_HC1753_SUPPORT (CHIP_ID(CID) == HC1753 || CHIP_ID(CID) == HC1753_FPU)
#define IS_HC1753E0_SUPPORT (CID == _HC1753(VER0))

#define IS_HC1753S_SUPPORT (CHIP_ID(CID) == HC1753S)
#define IS_HC1753SE0_SUPPORT (CID == _HC1753S(VER0))

#define IS_HC1706_SUPPORT (CHIP_ID(CID) == HC1706)
#define IS_HC1706E0_SUPPORT (CID == _HC1706(VER0))

#define IS_HC1706K_SUPPORT (CHIP_ID(CID) == HC1706K)
#define IS_HC1706KE0_SUPPORT (CID == _HC1706K(VER0))

#define IS_HC1706H_SUPPORT (CHIP_ID(CID) == HC1706H)
#define IS_HC1706HE0_SUPPORT (CID == _HC1706H(VER0))

#define IS_HC1706K_ES_SUPPORT (CHIP_ID(CID) == HC1706K_ES)
#define IS_HC1706K_ESE0_SUPPORT (CID == _HC1706K_ES(VER0))

#define IS_HC1785_SUPPORT (CHIP_ID(CID) == HC1785)
#define IS_HC1785E0_SUPPORT (CID == _HC1785(VER0))

#define IS_HC1726_SUPPORT (CHIP_ID(CID) == HC1726)
#define IS_HC1726E0_SUPPORT (CID == _HC1726(VER0))

#define IS_HC1783S_SUPPORT (CHIP_ID(CID) == HC1783S || CHIP_ID(CID) == HC1783S_FPU)
#define IS_HC1783SE0_SUPPORT (CID == _HC1783S(VER0))

#define IS_HC1802E1_AND_LATER_SUPPORT ((CHIP_ID(CID) == HC1802) && (CHIP_VER(CID) >= VER1))

#define IS_HC1822E1_AND_LATER_SUPPORT ((CHIP_ID(CID) == HC1822) && (CHIP_VER(CID) >= VER1))

#define IS_HC1852E1_AND_LATER_SUPPORT ((CHIP_ID(CID) == HC1852) && (CHIP_VER(CID) >= VER1))

#define IS_HC1852SE1_AND_LATER_SUPPORT ((CHIP_ID(CID) == HC1852S) && (CHIP_VER(CID) >= VER1))

#define IS_HC1882E1_AND_LATER_SUPPORT ((CHIP_ID(CID) == HC1882) && (CHIP_VER(CID) >= VER1))

#define IS_HC1882SE1_AND_LATER_SUPPORT ((CHIP_ID(CID) == HC1882S) && (CHIP_VER(CID) >= VER1))

#define IS_HC1892LE1_AND_LATER_SUPPORT ((CHIP_ID(CID) == HC1892L) && (CHIP_VER(CID) >= VER1))

#define IS_HC1892E1_AND_LATER_SUPPORT ((CHIP_ID(CID) == HC1892) && (CHIP_VER(CID) >= VER1))

#define IS_HC1892SE1_AND_LATER_SUPPORT ((CHIP_ID(CID) == HC1892S) && (CHIP_VER(CID) >= VER1))

#define IS_HC1722E1_AND_LATER_SUPPORT ((CHIP_ID(CID) == HC1722) && (CHIP_VER(CID) >= VER1))

#define IS_HC1732E1_AND_LATER_SUPPORT ((CHIP_ID(CID) == HC1732) && (CHIP_VER(CID) >= VER1))

#define IS_HC1752E1_AND_LATER_SUPPORT ((CHIP_ID(CID) == HC1752) && (CHIP_VER(CID) >= VER1))

#define IS_HC1762E1_AND_LATER_SUPPORT ((CHIP_ID(CID) == HC1762) && (CHIP_VER(CID) >= VER1))

#define IS_HC1772E1_AND_LATER_SUPPORT ((CHIP_ID(CID) == HC1772) && (CHIP_VER(CID) >= VER1))

#define IS_HC1782E1_AND_LATER_SUPPORT ((CHIP_ID(CID) == HC1782) && (CHIP_VER(CID) >= VER1))

#define IS_HC1702E1_AND_LATER_SUPPORT ((CHIP_ID(CID) == HC1702) && (CHIP_VER(CID) >= VER1))

#define IS_HC1800_SERIES_SUPPORT                                                               \
	((CHIP_ID(CID) == HC1802) || (CHIP_ID(CID) == HC1822) || (CHIP_ID(CID) == HC1852) ||   \
	 (CHIP_ID(CID) == HC1852S) || (CHIP_ID(CID) == HC1882) || (CHIP_ID(CID) == HC1882S) || \
	 (CHIP_ID(CID) == HC1892) || (CHIP_ID(CID) == HC1892S))
/*(CHIP_ID(CID) == HC1892L)*/

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* CHIP_ID_H_ */
