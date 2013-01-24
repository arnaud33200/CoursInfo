CC= g++

sources= rechercher2.cc change.cc

recherche: $(sources:.cc=.o)
	$(CC) $^ -o $@

rechercher2.o: rechercher2.cc change.hh
	$(CC) -c $<

change.o: change.cc change.hh
	$(CC) -c $<