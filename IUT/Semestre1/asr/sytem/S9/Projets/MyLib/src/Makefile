#
# Fabrication d'une bibliothèque statique
# à partir de deux modules objet.
#

sources = carre.cc cube.cc
objects  = $(sources:.cc=.o)

# la bibliothèque à fabriquer. Son nom doit
# commencer par lib

library = ../lib/libmylib.a

# le répertoire avec le .h de la bibliothèque

include_dir = ../include
CPPFLAGS = -I$(include_dir)


CXXFLAGS = -Wall

#############################################

all: $(library)

$(library): $(objects)
	ar rcs $@ $^

# les fichiers objets sont fabriqués 
# selon les règles implicites

#############################################

depend:
	makedepend -I$(include_dir) $(sources)

clean:
	rm -f *~ *.bak \#* 

mrproper: clean
	rm -f *.o $(library)

#############################################
# DO NOT DELETE

carre.o: ../include/mylib.h
cube.o: ../include/mylib.h
