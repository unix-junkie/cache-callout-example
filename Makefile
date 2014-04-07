GLOBALS_HOME = /opt/intersystems/cache/2014.1.0

CFLAGS = -Wall -Wextra -g
CPPFLAGS = -I$(GLOBALS_HOME)/dev/cpp/include

.PHONY: all
all: lib770936-callout.dylib lib770936-callout.bundle 770936 770936-dlopen

lib770936-callout.dylib: 770936-callout.o
	$(CC) -dynamiclib -o $@ $<

lib770936-callout.bundle: 770936-callout.o
	$(CC) -bundle -o $@ $<

770936: 770936.o
	$(CC) -L. -l770936-callout -o $@ $<

770936-dlopen: 770936-dlopen.o
	$(CC) -o $@ $<

.PHONY: clean
clean:
	$(RM) *.o *.so *.dylib *.bundle 770936 770936-dlopen
