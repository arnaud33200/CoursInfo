# ------------------------------------------
# la compilation

CXXFLAGS=-Wall -pedantic

codage: codage.cc

# ------------------------------------------
# les tests

tests: resultats-1 resultats-2

resultats-1: codage jeu-test-1
	./codage < jeu-test-1 > resultats-1

resultats-2: codage jeu-test-2
	./codage < jeu-test-2 > resultats-2

# ------------------------------------------
# les corvees

clean:
	rm -f *~

mrproper: clean
	rm -f codage resultats-*

