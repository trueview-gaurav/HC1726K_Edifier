#ifndef _UCLIBC_YOCTO_BOOTSTRAP_H
#define _UCLIBC_YOCTO_BOOTSTRAP_H 1

#ifndef __ASSEMBLER__
/* --------------------------------------------------------------------
 * Fallbacks for -nostdinc builds:
 * Do NOT include any headers here (uclibc's limits.h uses include_next and
 * linux/limits.h, which may be unavailable in the bootstrap sysroot).
 * Use GCC built-ins instead.
 * -------------------------------------------------------------------- */

/* Provide fundamental typedefs early for -nostdinc builds. */
//# include <stddef.h>   // size_t
//# include <stdint.h>   // uint32_t etc (safe)
/* uClibc internal program name (defined in __uClibc_main.c) */
extern const char *__uclibc_progname;

/* ---------- preprocessor-safe limit macros (must work in #if) ---------- */
/* Always prefer GCC built-in numeric literals. */


#ifndef CHAR_BIT
# ifdef __CHAR_BIT__
#  define CHAR_BIT __CHAR_BIT__
# endif
#endif

/* int/uint */
#ifndef UINT_MAX
# ifdef __UINT_MAX__
#  define UINT_MAX __UINT_MAX__
# elif defined(__INT_MAX__)
   /* derive from signed max (GCC always has __INT_MAX__) */
#  define UINT_MAX (__INT_MAX__ * 2U + 1U)
# else
#  define UINT_MAX (~0U)
# endif
#endif

#ifndef INT_MAX
# ifdef __INT_MAX__
#  define INT_MAX __INT_MAX__
# endif
#endif
#ifndef INT_MIN
# ifdef __INT_MAX__
#  define INT_MIN (-__INT_MAX__ - 1)
# endif
#endif

#ifndef USHRT_MAX
# ifdef __USHRT_MAX__
#  define USHRT_MAX __USHRT_MAX__
# elif defined(__SHRT_MAX__)
#  define USHRT_MAX (__SHRT_MAX__ * 2U + 1U)
# else
#  define USHRT_MAX 65535U
# endif
#endif

#ifndef USHRT_MAX
# ifdef __USHRT_MAX__
#  define USHRT_MAX __USHRT_MAX__
# else
#  define USHRT_MAX 65535U
# endif
#endif

#ifndef SHRT_MAX
# ifdef __SHRT_MAX__
#  define SHRT_MAX __SHRT_MAX__
# endif
#endif
#ifndef SHRT_MIN
# ifdef __SHRT_MAX__
#  define SHRT_MIN (-__SHRT_MAX__ - 1)
# endif
#endif

/* long/ulong */
#ifndef ULONG_MAX
# ifdef __ULONG_MAX__
#  define ULONG_MAX __ULONG_MAX__
# elif defined(__LONG_MAX__)
   /* derive from signed max; NO casts/type keywords (must work in #if) */
#  define ULONG_MAX (__LONG_MAX__ * 2UL + 1UL)
# elif defined(LONG_MAX)
#  define ULONG_MAX (LONG_MAX * 2UL + 1UL)
# else
#  define ULONG_MAX (~0UL)
# endif
#endif

#ifndef LONG_MAX
# ifdef __LONG_MAX__
#  define LONG_MAX __LONG_MAX__
# elif defined(__SIZEOF_LONG__) && defined(__CHAR_BIT__)
   /* works for 32/64-bit long; no casts; ok for preprocessor too */
#  define LONG_MAX ((1L << (__SIZEOF_LONG__ * __CHAR_BIT__ - 1)) - 1L)
# else
   /* last resort (ARM 32-bit long) */
#  define LONG_MAX 2147483647L
# endif
#endif

#ifndef LONG_MIN
# define LONG_MIN (-LONG_MAX - 1L)
#endif

/* long long / unsigned long long */
#ifndef LLONG_MAX
# ifdef __LONG_LONG_MAX__
#  define LLONG_MAX __LONG_LONG_MAX__
# endif
#endif

#ifndef ULLONG_MAX
# ifdef __ULLONG_MAX__
#  define ULLONG_MAX __ULLONG_MAX__
# elif defined(__LONG_LONG_MAX__)
   /* pure numeric, no type keywords */
#  define ULLONG_MAX (__LONG_LONG_MAX__ * 2ULL + 1ULL)
# endif
#endif

/* ptrdiff_t */
#ifndef PTRDIFF_MAX
# ifdef __PTRDIFF_MAX__
#  define PTRDIFF_MAX __PTRDIFF_MAX__
# elif defined(__INT_MAX__)
#  define PTRDIFF_MAX __INT_MAX__
# endif
#endif

/* size_t */
#ifdef SIZE_MAX
# undef SIZE_MAX
#endif
#ifdef __SIZE_MAX__
# define SIZE_MAX __SIZE_MAX__
#else
  /* last resort: assume ILP32 unless proven otherwise */
# ifdef __SIZEOF_POINTER__
#  if __SIZEOF_POINTER__ == 4
#   define SIZE_MAX 0xffffffffU
#  elif __SIZEOF_POINTER__ == 8
#   define SIZE_MAX 0xffffffffffffffffULL
#  endif
# else
#  define SIZE_MAX 0xffffffffU
# endif
#endif

/* intmax_t */
#ifndef INTMAX_MAX
# ifdef __INTMAX_MAX__
#  define INTMAX_MAX __INTMAX_MAX__
# elif defined(LLONG_MAX)
#  define INTMAX_MAX LLONG_MAX
# elif defined(__LONG_MAX__)
#  define INTMAX_MAX __LONG_MAX__
# endif
#endif

#ifndef CHAR_MIN
# ifdef __CHAR_UNSIGNED__          /* e.g. -funsigned-char */
#  define CHAR_MIN 0
# else
#  define CHAR_MIN SCHAR_MIN
# endif
#endif

#ifndef CHAR_MAX
# ifdef __CHAR_UNSIGNED__
#  ifndef UCHAR_MAX
#   ifdef __SCHAR_MAX__
#    define UCHAR_MAX (__SCHAR_MAX__ * 2 + 1)
#   endif
#  endif
#  define CHAR_MAX UCHAR_MAX
# else
#  define CHAR_MAX SCHAR_MAX
# endif
#endif

#ifndef SCHAR_MAX
# ifdef __SCHAR_MAX__
#  define SCHAR_MAX __SCHAR_MAX__
# else
#  define SCHAR_MAX 127
# endif
#endif

#ifndef SCHAR_MIN
/* signed char is two's complement on all supported targets here */
# define SCHAR_MIN (-SCHAR_MAX - 1)
#endif

/* --------------------------------------------------------------------- */

#endif /* !__ASSEMBLER__ */

#endif /* _UCLIBC_YOCTO_BOOTSTRAP_H */
