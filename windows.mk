#
# $Id$
#
# vim:ft=make:
#

ifndef GLOBALS_HOME
$(error GLOBALS_HOME is undefined)
endif # GLOBALS_HOME

.PHONY: all
all:

.PHONY: clean
clean:
	$(RM) *.dll *.exe
