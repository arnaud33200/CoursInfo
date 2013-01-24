cc = g++
source = Circle.cc  Forme.cc  Line.cc  main.cc  Rectangle.cc  Square.cc
objet = $(source:.cc=.o)

#########################################################

bibu : $(objet)
	$(cc) $^ -o $@

Circle.o : Circle.cc 
	$(cc) -c $<

Forme.o : Forme.cc 
	$(cc) -c $<

Line.o : Line.cc 
	$(cc) -c $<

main.o : main.cc 
	$(cc) -c $<

Rectangle.o : Rectangle.cc 
	$(cc) -c $<

Square.o : Square.cc 
	$(cc) -c $<


########### CLEAR ###########

clear : 
	rm -vr *~ *.o


########### MRPROPER ###########

mrproper : 
	rm -vr *~ *.o bibu
