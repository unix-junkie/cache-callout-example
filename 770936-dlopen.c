/*-
 * $Id$
 *
 * This example shows how to call a library function
 * using dlopen()/dlsym().
 */

#include <stdio.h>
#include <dlfcn.h>

int main (const int argc, const char *argv[]) {
	void *handle = dlopen("/Users/ashcheglov/Documents/wrc/770936/lib770936-callout.dylib", RTLD_NOW);
	if (!handle) {
		printf("%s\n", dlerror());
		return 1;
	}
	printf("Library loaded successfully.\n");

	int (*strlen_c)(const char *, size_t *) = dlsym(handle, "strlen_c_callout");
	if (!strlen_c) {
		printf("%s\n", dlerror());
	} else {
		size_t length;
		strlen_c(argc == 1 ? "123456" : argv[1], &length);
		printf("%u\n", (unsigned int) length);
	}

	if (dlclose(handle)) {
		printf("%s\n", dlerror());
		return 1;
	}
	printf("Library unloaded successfully.\n");

	return 0;
}
