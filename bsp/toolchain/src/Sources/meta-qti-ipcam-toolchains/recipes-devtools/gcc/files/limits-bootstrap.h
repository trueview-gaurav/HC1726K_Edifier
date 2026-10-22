#ifndef __LIMITS_BOOTSTRAP_H__
#define __LIMITS_BOOTSTRAP_H__

/*
 * Minimal limits.h for bootstrap sysroots.
 * Goal: provide enough constants for native tools + gcc bootstrap
 * without depending on host /usr/include.
 */

/* Basic */
#ifndef CHAR_BIT
# define CHAR_BIT 8
#endif

/* ---------- GCC builtin-style max macros (fallbacks if missing) ---------- */
#ifndef __USHRT_MAX__
# define __USHRT_MAX__  ((unsigned short)~0U)
#endif
#ifndef __UINT_MAX__
# define __UINT_MAX__   (~0U)
#endif

/* long/ulong depend on LP64 */
#if defined(__LP64__) || defined(_LP64)
# ifndef __ULONG_MAX__
#  define __ULONG_MAX__ (~0UL)
# endif
# ifndef __LONG_MAX__
#  define __LONG_MAX__  ((long)(__ULONG_MAX__ >> 1))
# endif
#else
# ifndef __ULONG_MAX__
#  define __ULONG_MAX__ 4294967295UL
# endif
# ifndef __LONG_MAX__
#  define __LONG_MAX__  2147483647L
# endif
#endif

#ifndef __LONG_MIN__
# define __LONG_MIN__ (-__LONG_MAX__ - 1L)
#endif

#ifndef __ULONG_LONG_MAX__
# define __ULONG_LONG_MAX__ (~0ULL)
#endif
#ifndef __LONG_LONG_MAX__
# define __LONG_LONG_MAX__  ((long long)(__ULONG_LONG_MAX__ >> 1))
#endif
#ifndef __LONG_LONG_MIN__
# define __LONG_LONG_MIN__ (-__LONG_LONG_MAX__ - 1LL)
#endif

/* ---------- Standard names expected by lots of packages ---------- */
#ifndef USHRT_MAX
# define USHRT_MAX __USHRT_MAX__
#endif
#ifndef UINT_MAX
# define UINT_MAX  __UINT_MAX__
#endif
#ifndef ULONG_MAX
# define ULONG_MAX __ULONG_MAX__
#endif
#ifndef LONG_MAX
# define LONG_MAX  __LONG_MAX__
#endif
#ifndef LONG_MIN
# define LONG_MIN  __LONG_MIN__
#endif
#ifndef ULLONG_MAX
# define ULLONG_MAX __ULONG_LONG_MAX__
#endif
#ifndef LLONG_MAX
# define LLONG_MAX __LONG_LONG_MAX__
#endif
#ifndef LLONG_MIN
# define LLONG_MIN __LONG_LONG_MIN__
#endif

/* PATH_MAX: many native tools (acl, coreutils bits) expect it */
#ifndef PATH_MAX
# include <linux/limits.h>   /* provided by linux-libc-headers */
#endif
#ifndef PATH_MAX
# define PATH_MAX 4096       /* fallback */
#endif

#endif /* __LIMITS_BOOTSTRAP_H__ */

