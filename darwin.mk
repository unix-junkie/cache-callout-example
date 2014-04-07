#!/usr/bin/env make -f
#
# $Id$
#
# vim:ft=make:
#

ifndef GLOBALS_HOME
$(error GLOBALS_HOME is undefined)
endif # GLOBALS_HOME

CFLAGS = -Wall -Wextra -g
CPPFLAGS = -I${GLOBALS_HOME}/dev/cpp/include

.PHONY: all
all: lib770936-callout.bundle 770936 770936-dlopen

lib770936-callout.dylib: 770936-callout.o
	$(CC) -dynamiclib -o $@ $<

lib770936-callout.bundle: 770936-callout.o
	$(CC) -bundle -o $@ $<

770936: 770936.o lib770936-callout.dylib
	$(CC) -L. -l770936-callout -o $@ $<
	install_name_tool -change lib770936-callout.dylib @executable_path/lib770936-callout.dylib $@

770936-dlopen: 770936-dlopen.o
	$(CC) -o $@ $<

.PHONY: clean
clean:
	$(RM) *.o *.so *.dylib *.bundle 770936 770936-dlopen
