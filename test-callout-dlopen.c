/*-
 * $Id$
 *
 * This example shows how to call a library function
 * using dlopen()/dlsym().
 */

#include <stdio.h>
#include <dlfcn.h>
#include <libgen.h>

int main (const int argc, char *argv[]) {
	const char *executable_path = dirname(argv[0]);
	char library_path[1024];
#ifdef _WIN32
	sprintf(library_path, "%s\\test-callout.dll", executable_path);
#else // _WIN32
#ifdef __APPLE__
	sprintf(library_path, "%s/libtest-callout.dylib", executable_path);
#else // __APPLE__
	sprintf(library_path, "%s/libtest-callout.so", executable_path);
#endif // __APPLE__
#endif // _WIN32

	void *handle = dlopen(library_path, RTLD_NOW);
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
