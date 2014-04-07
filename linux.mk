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
all: 770936 770936-dlopen

lib770936-callout.so: 770936-callout.o
	$(CC) -dynamiclib -o $@ $<

770936: 770936.o lib770936-callout.so
	$(CC) -L. -l770936-callout -o $@ $<

770936-dlopen: 770936-dlopen.o
	$(CC) -o $@ $<

.PHONY: clean
clean:
	$(RM) *.o *.so 770936 770936-dlopen
