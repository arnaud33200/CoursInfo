
exo1:
	bison -v -d exo1.y
	lex exo1.l
	gcc exo1.tab.c lex.yy.c -lfl
	./a.out < test
