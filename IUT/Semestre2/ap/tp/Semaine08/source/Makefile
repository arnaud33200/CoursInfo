cc = g++
source = Circle.cc Copie de main.cc LineBrok.cc Line.cc main.cc Point.cc Rectangle.cc Screen.cc Shape.cc Square.cc Triangle.cc util.cc 
LDFLAGS = 
objet = $(source:.cc=.o)

#########################################################

bite : $(objet)
	$(cc) $(LDFLAGS) $^ -o $@

Circle.o : Circle.cc Screen.h Point.h Circle.h
	$(cc) -c $<

Copie de main.o : Copie de main.cc Screen.h Point.h Shape.h Line.h LineBrok.h Rectangle.h Square.h Triangle.h Circle.h util.h
	$(cc) -c $<

LineBrok.o : LineBrok.cc Screen.h Point.h Line.h LineBrok.h
	$(cc) -c $<

Line.o : Line.cc Screen.h Point.h Line.h
	$(cc) -c $<

main.o : main.cc Screen.h Point.h Shape.h Line.h LineBrok.h Rectangle.h Square.h Triangle.h Circle.h util.h
	$(cc) -c $<

Point.o : Point.cc Point.h
	$(cc) -c $<

Rectangle.o : Rectangle.cc Screen.h Point.h Rectangle.h
	$(cc) -c $<

Screen.o : Screen.cc Screen.h Point.h
	$(cc) -c $<

Shape.o : Shape.cc Shape.h
	$(cc) -c $<

Square.o : Square.cc Screen.h Point.h Square.h
	$(cc) -c $<

Triangle.o : Triangle.cc Screen.h Point.h Triangle.h
	$(cc) -c $<

util.o : util.cc Point.h util.h
	$(cc) -c $<


########### CLEAN ###########

clean : 
	rm -vf *~ *.o


########### MRPROPER ###########

mrproper : 
	rm -vr *~ *.o bite


########### OPEN ###########

open : 
	geany *.cc *.h Makefile &
