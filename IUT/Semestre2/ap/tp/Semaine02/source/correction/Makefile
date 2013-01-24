CC=g++ 

OBJECTS= Point.o Polygone.o TestePolygone.o 

essai : $(OBJECTS)
	$(CC) $(OBJECTS) -o essai


Point.o : Point.cc Point.h 
	$(CC) -c Point.cc

Polygone.o : Polygone.cc Polygone.h Point.h 
	$(CC) -c Polygone.cc

TestePolygone.o : TestePolygone.cc Polygone.h Point.h
	$(CC) -c TestePolygone.cc

clean :
	rm -f *~ *.o essai
