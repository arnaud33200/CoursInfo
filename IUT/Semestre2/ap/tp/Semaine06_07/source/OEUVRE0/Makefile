# fichier Makefile pour Oeuvre0...

CC=g++ -Wall

art	:	util.o Oeuvre.o Peinture.o main.o
	$(CC) util.o Oeuvre.o Peinture.o main.o -o $@

util.o : util.cc util.h
	$(CC) -c $<

Oeuvre.o	:	Oeuvre.cc	Oeuvre.h util.h
	$(CC) -c Oeuvre.cc

Peinture.o	:	Peinture.cc 	Peinture.h	Oeuvre.h util.h
	$(CC) -c Peinture.cc

main.o	:	main.cc	Peinture.h	Oeuvre.h util.h
	$(CC) -c main.cc

clean	:
	rm -f *.o *~ art
