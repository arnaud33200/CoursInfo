cc = g++
source = main.cc  point.cc  polygone.cc
objet = $(source:.cc=.o)

#########################################################

poly : $(objet)
	$(cc) $^ -o $@

main.o : main.cc  point.h polygone.h
	$(cc) -c $<

point.o : point.cc  point.h
	$(cc) -c $<

polygone.o : polygone.cc  polygone.h point.h
	$(cc) -c $<


########### CLEAR ###########

clear : 
	rm -vr *~ *.o


########### MRPROPER ###########

mrproper : 
	rm -vr *~ *.o poly
