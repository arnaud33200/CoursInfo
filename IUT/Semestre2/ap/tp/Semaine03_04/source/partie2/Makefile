CC=g++ -Wall
OBJECTS1= Point.o Cercle.o main.o
OBJECTS2= Point.o mainpoint.o
EXE=progcercle mainpoint

all : $(EXE) 

progcercle : $(OBJECTS1)
	$(CC) $(OBJECTS1) -o progcercle

mainpoint : $(OBJECTS2)
	$(CC) $(OBJECTS2) -o mainpoint

main.o : main.cc Cercle.h Point.h 
	$(CC) -c main.cc

mainpoint.o : mainpoint.cc Point.h 
	$(CC) -c mainpoint.cc

Point.o : Point.cc Point.h 
	$(CC) -c Point.cc

Cercle.o : Cercle.cc Cercle.h Point.h 
	$(CC) -c Cercle.cc


clean :
	rm -vf *~ *.o; echo ""
