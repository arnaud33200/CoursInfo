cc = g++

### RATIONNEL ###

sourcerationnel = rationnel.cc main.cc outil.cc
objetrationnel = $(sourcerationnel:.cc=.o)

rationnel : $(objetrationnel)
		$(cc) $^ -o $@

### COMPLEXE ###

sourcecomplexe = testecomplexe.cc complexe.cc
objetcomplexe = $(sourcecomplexe:.cc=.o)

complexe : $(objetcomplexe)
		$(cc) $^ -o $@

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

rationnel.o : rationnel.cc rationnel.h outil.h
		$(cc) -c $<
		
main.o : main.cc rationnel.h outil.h
		$(cc) -c $<
		
outil.o : outil.cc outil.h
		$(cc) -c $<
		
testecomplexe.o : testecomplexe.cc complexe.h
		$(cc) -c $<
			
		
complexe.o : complexe.cc complexe.h
		$(cc) -c $<
		

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

clean :
		rm -vr *.o
