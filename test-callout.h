/*-
 * $Id$
 */

#ifndef D_770936_CALLOUT
#define D_770936_CALLOUT

#define ZF_DLL

#include <cdzf.h>
#include <callin.h>

int strlen_c_callout(const char *s, size_t *length);

int strlen_w_callout(const unsigned short *s, size_t *length);

int strlen_s_callout(const ZWARRAYP s, size_t *length);

int strlen_lstrp_callout(const CACHE_EXSTRP s, size_t *length);

#endif // D_770936_CALLOUT
