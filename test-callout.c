/*-
 * $Id$
 */

#include <string.h>

#include "test-callout.h"

int strlen_c_callout(const char *s, size_t *length) {
	*length = strlen(s);
	return 0;
}

int strlen_w_callout(const unsigned short *s, size_t *length) {
	const unsigned short *s2 = s;
	while (*s2) {
		s2++;
	}
	*length = s2 - s;
	return 0;
}

int strlen_s_callout(const ZWARRAYP s, size_t *length) {
	*length = s->len;
	return 0;
}

int strlen_lstrp_callout(const CACHE_EXSTRP s, size_t *length) {
	*length = s->len;
	CACHEEXSTRKILL(s);
	return 0;
}

/* -
 * See cdzf.h for possible second argument values
 */
ZFBEGIN

ZFENTRY("strlen", ((char[3]) {DPCHAR, 'P'} /* same as "cP" */), strlen_c_callout)
ZFENTRY("strlen_w", ((char[3]) {DPWCHAR, 'P'} /* same as "wP" */), strlen_w_callout)
ZFENTRY("strlen_s", ((char[3]) {DPCWSTR, 'P'} /* same as "sP" */), strlen_s_callout)

ZFENTRY("strlen_j", ((char[3]) {DLSTR, 'P'} /* same as "jP" */), strlen_lstrp_callout)
ZFENTRY("strlen_m", ((char[3]) {DTLSTR, 'P'} /* same as "mP" */), strlen_lstrp_callout)
ZFENTRY("strlen_n", ((char[3]) {DWLSTR, 'P'} /* same as "nP" */), strlen_lstrp_callout)
ZFENTRY("strlen_r", ((char[3]) {DTWLSTR, 'P'} /* same as "rP" */), strlen_lstrp_callout)

ZFEND
