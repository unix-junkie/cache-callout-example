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
all: libtest-callout.bundle test-callout-dynamic test-callout-dlopen

libtest-callout.dylib: test-callout.o
	$(CC) -dynamiclib -o $@ $<

libtest-callout.bundle: test-callout.o
	$(CC) -bundle -o $@ $<

test-callout-dynamic: test-callout-dynamic.o libtest-callout.dylib
	$(CC) -L. -ltest-callout -o $@ $<
	install_name_tool -change libtest-callout.dylib @executable_path/libtest-callout.dylib $@

test-callout-dlopen: test-callout-dlopen.o
	$(CC) -o $@ $<

.PHONY: clean
clean:
	$(RM) *.o *.so *.dylib *.bundle test-callout-dynamic test-callout-dlopen
