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
all: test-callout-dynamic test-callout-dlopen

libtest-callout.so: test-callout.o
	$(CC) -shared -o $@ $<

test-callout-dynamic: test-callout-dynamic.o libtest-callout.so
	$(CC) -L. -ltest-callout -o $@ $<

test-callout-dlopen: test-callout-dlopen.o
	$(CC) -o $@ $<

.PHONY: clean
clean:
	$(RM) *.o *.so test-callout-dynamic test-callout-dlopen
