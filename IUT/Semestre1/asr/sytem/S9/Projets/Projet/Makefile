#
# Utilisation d'une bibliothèque
#

source = projet.cc
bin    = $(source:.cc=)

# le répertoire qui contient les entetes

CPPFLAGS = -I../MyLib/include

# repertoire et nom de la bibliothèque
# (sans le préfixe lib ni le suffixe .a)

LDLIBS   = -L ../MyLib/lib -lmylib

CXXFLAGS = -Wall -pedantic

########################################"
all: $(bin)


%: %.o
	$(LINK.cc)  -o $@ $^ $(LDLIBS)

clean:
	rm -f *.o *~

mrproper: clean
	rm -f $(bin)

depend:
	makedepend $(CPPFLAGS) $(source)

########################################
# DO NOT DELETE

projet.o: ../MyLib/include/mylib.h
