/*-
 * $Id$
 *
 * This example shows how to call a library function
 * using dynamic linking.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test-callout.h"

size_t strlen_w(const unsigned short *s) {
	size_t length = 0;
	strlen_w_callout(s, &length);
	return length;
}

unsigned short * strcpy_w(unsigned short * dst, const char *src) {
	unsigned short *ptr = dst;
	while ((*dst++ = *src++)) {
		// empty
	}
	return ptr;
}

ZWARRAYP zwarrayp_new(const char *c) {
	ZWARRAYP zwarrayp = (ZWARRAYP) malloc(sizeof(struct zwarray));
	zwarrayp->len = strlen(c);
	return zwarrayp;
}

size_t strlen_zwarrayp(const ZWARRAYP s) {
	size_t length = 0;
	strlen_s_callout(s, &length);
	return length;
}

int main (const int argc, const char *argv[]) {
	const char * c = "123456789";
	unsigned short * s = (unsigned short *) malloc(sizeof(unsigned short) * (strlen(c) + 1));
	strcpy_w(s, c);

	printf("%u\n", (unsigned int) strlen_w(s));
	printf("%u\n", (unsigned int) strlen(c));

	ZWARRAYP zwarrayp = zwarrayp_new(c);
	printf("%u\n", (unsigned int) strlen_zwarrayp(zwarrayp));

	size_t length;
	strlen_c_callout(argc == 1 ? c : argv[1], &length);
	printf("%u\n", (unsigned int) length);

	return 0;
}
