CC=g++ 

OBJECTS= util.o Rationnel.o TesteRationnel.o 

essai : $(OBJECTS)
	$(CC) $(OBJECTS) -o essai


util.o : util.cc util.h 
	$(CC) -c util.cc

Rationnel.o : Rationnel.cc Rationnel.h util.h 
	$(CC) -c Rationnel.cc

TesteRationnel.o : TesteRationnel.cc Rationnel.h
	$(CC) -c TesteRationnel.cc

clean :
	rm -f *~ *.o essai
