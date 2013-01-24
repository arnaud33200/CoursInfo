# fichier Makefile pour Oeuvre2...

CC=g++ -Wall

art	: util.o Date.o Oeuvre.o Peinture.o main.o Plastique.o
	$(CC) util.o Date.o Oeuvre.o Peinture.o Plastique.o main.o -o $@

util.o : util.cc util.h
	$(CC) -c $<

Date.o : Date.cc Date.h util.h
	$(CC) -c $<

Oeuvre.o	:	Oeuvre.cc	Oeuvre.h util.h
	$(CC) -c Oeuvre.cc

Peinture.o	:	Peinture.cc 	Peinture.h	Oeuvre.h util.h
	$(CC) -c Peinture.cc

Plastique.o : Plastique.cc Plastique.h Oeuvre.h util.h
	$(CC) -c $<

main.o	:	main.cc	Peinture.h	Oeuvre.h util.h
	$(CC) -c main.cc
	

clean	:
	rm -f *.o *~ art

open :
	geany *.cc *.h Makefile &
