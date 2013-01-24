cc = g++
source = Boite.cc  main.cc  Point.cc
objet = $(source:.cc=.o)

#########################################################

essai : $(objet)
	$(cc) $^ -o $@

Boite.o : Boite.cc 
	$(cc) -c $<

main.o : main.cc  Point.h Boite.h
	$(cc) -c $<

Point.o : Point.cc  Point.h
	$(cc) -c $<


########### CLEAR ###########

clear : 
	rm -vf *~ *.o


########### MRPROPER ###########

mrproper : 
	rm -vf *~ *.o essai
