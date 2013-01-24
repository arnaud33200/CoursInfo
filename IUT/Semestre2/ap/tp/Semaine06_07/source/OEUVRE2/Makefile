cc = g++
source = Date.cc  Ecrit.cc  main.cc  Oeuvre.cc  Peinture.cc  Plastique.cc  util.cc
objet = $(source:.cc=.o)

#########################################################

art : $(objet)
	$(cc) $^ -o $@

Date.o : Date.cc  Date.h util.h
	$(cc) -c $<

Ecrit.o : Ecrit.cc  Oeuvre.h Date.h util.h Ecrit.h
	$(cc) -c $<

main.o : main.cc  Peinture.h Plastique.h
	$(cc) -c $<

Oeuvre.o : Oeuvre.cc  Oeuvre.h Date.h util.h
	$(cc) -c $<

Peinture.o : Peinture.cc  Peinture.h Oeuvre.h Date.h util.h
	$(cc) -c $<

Plastique.o : Plastique.cc  Plastique.h Oeuvre.h Date.h util.h
	$(cc) -c $<

util.o : util.cc  util.h
	$(cc) -c $<


########### CLEAR ###########

clear : 
	rm -vr *~ *.o


########### MRPROPER ###########

mrproper : 
	rm -vr *~ *.o art
