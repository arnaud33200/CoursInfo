#---------------------------------------------------------
# Exemple systeme : DEKKER version 1                     |
# makefile pour generer les executables DEKKER et P_DEK  |
#---------------------------------------------------------

all	: dekker p_dek
#pour dekker:
#------------

dekker : dekker.o
	gcc -o dekker dekker.o
dekker.o: dekker.c
	gcc -c dekker.c

#pour p_dek:
#-----------

p_dek  : p_dek.o
	gcc -o p_dek p_dek.o
p_dek.o : p_dek.c
	gcc -c p_dek.c

clean	: 
	rm -f *~ *.o 
