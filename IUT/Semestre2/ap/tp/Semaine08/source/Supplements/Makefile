CC=g++ -Wall

OBJECTS= Point.o Screen.o Shape.o Line.o LineBrok.o Rectangle.o Square.o Triangle.o Circle.o util.o DessinShapes.o main.o

testShape : $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

Point.o : Point.cc Point.h
	$(CC) -c Point.cc

Screen.o : Screen.cc Screen.h Point.h
	$(CC) -c Screen.cc

Shape.o : Shape.cc Shape.h Screen.h
	$(CC) -c Shape.cc

Line.o : Line.cc Line.h Shape.h Point.h Screen.h
	$(CC) -c Line.cc

LineBrok.o : LineBrok.cc LineBrok.h Line.h Point.h Screen.h
	$(CC) -c LineBrok.cc

Rectangle.o : Rectangle.cc Rectangle.h Shape.h Point.h Screen.h
	$(CC) -c Rectangle.cc

Square.o : Square.cc Square.h Rectangle.h Point.h
	$(CC) -c Square.cc

Triangle.o : Triangle.cc Triangle.h Shape.h Point.h Screen.h
	$(CC) -c Triangle.cc

Circle.o : Circle.cc Circle.h Shape.h Point.h Screen.h
	$(CC) -c Circle.cc

util.o : util.cc util.h Point.h
	$(CC) -c util.cc

DessinShapes.o : DessinShapes.cc DessinShapes.h Shape.h Screen.h
	$(CC) -c DessinShapes.cc

main.o 	: main.cc Shape.h Line.h LineBrok.h Rectangle.h Square.h Triangle.h Circle.h Point.h Screen.h util.h DessinShapes.h
	$(CC) -c main.cc

clean :
	rm -f *~ *.o testShape

open :
	geany *.cc *.h Makefile &