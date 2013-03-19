###############################################################################
#
# GENERAL
#

INCLUDES	=	-I.
LIBRARIES	=	-ldl -lm
CFLAGS		=	$(INCLUDES) -Wall -Werror -O3 -fPIC
CXXFLAGS	=	$(CFLAGS)
PLUGINS		=	plugin.so #changer !!
CC		=	cc

###############################################################################
#
# RULES TO BUILD PLUGINS FROM C OR C++ CODE
#

vocalremove.so:	vocalremove.c
	$(CC) $(CFLAGS) -o vocalremove.o -c vocalremove.c
	$(LD) -o vocalremove.so vocalremove.o -shared


###############################################################################
#
# TARGETS
#

targets:	$(PLUGINS)

