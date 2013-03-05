
exo1:
	bison -v -d exo1.y
	lex exo1.l
	gcc exo1.tab.c lex.yy.c -lfl
	./a.out < test

exo2:
	bison -v -d exo2.y
	lex exo2.l
	gcc exo2.tab.c lex.yy.c -lfl
	./a.out < test

clean:
	rm -v lex.yy.c *.tab.c *.tab.h *.output a.out