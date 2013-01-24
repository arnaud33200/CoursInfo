CC=g++ -Wall

OBJECTS= Point.o Boite.o main.o 

essai : $(OBJECTS)
	$(CC) $(OBJECTS) -o essai


Point.o : Point.cc Point.h 
	$(CC) -c Point.cc

Boite.o : Boite.cc Boite.h Point.h 
	$(CC) -c Boite.cc

main.o : main.cc Boite.h Point.h
	$(CC) -c main.cc

clean :
	rm -f *~ *.o essai
