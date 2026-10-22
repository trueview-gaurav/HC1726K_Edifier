#ifndef M_EARLY_DETECT_MEM_H
#define M_EARLY_DETECT_MEM_H

#ifdef _MSC_VER
__declspec(align(4))
#else
__attribute__((aligned(4)))
#endif
static const unsigned char m_early_detect_param_bin[] = { 0x00 };

#ifdef _MSC_VER
__declspec(align(4))
#else
__attribute__((aligned(4)))
#endif
static const unsigned char m_early_detect_bin[] = { 0x00 };

#endif // M_EARLY_DETECT_MEM_H
