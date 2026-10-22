/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */
#ifndef VERSTR_H_
#define VERSTR_H_

#warning "[Warning] verstr.h is depreciated. Please do not include this file."

#define LIBNAME DRV_NAME
#define VERSION_STRING ("@(#) LIBNAME:[" LIBNAME "] Build Time:[" __DATE__ ", " __TIME__ "]")

static char s_szCommonVersion[] __attribute__((used)) = VERSION_STRING;

#endif /* !TOKYO_VERSTR_H_ */
