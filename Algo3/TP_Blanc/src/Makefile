CFLAGS=-g -Wall

all: test_create test_destroy test_insert test_coupe test_delete test_union test_cheap_splay test_splay

test_create: test_create.c splay.h splay.c
	gcc $(CFLAGS) test_create.c splay.c prof_splay.o -o test_create

test_destroy: test_destroy.c splay.h splay.c
	gcc $(CFLAGS) test_destroy.c splay.c prof_splay.o -o test_destroy

test_insert: test_insert.c splay.h splay.c
	gcc $(CFLAGS) test_insert.c splay.c prof_splay.o -o test_insert

test_coupe: test_coupe.c splay.h splay.c
	gcc $(CFLAGS) test_coupe.c splay.c prof_splay.o -o test_coupe

test_delete: test_delete.c splay.h splay.c
	gcc $(CFLAGS) test_delete.c splay.c prof_splay.o -o test_delete

test_union: test_union.c splay.h splay.c
	gcc $(CFLAGS) test_union.c splay.c prof_splay.o -o test_union

test_cheap_splay: test_cheap_splay.c splay.h splay.c
	gcc $(CFLAGS) test_cheap_splay.c splay.c prof_splay.o -o test_cheap_splay

test_splay: test_splay.c splay.h splay.c
	gcc $(CFLAGS) test_splay.c splay.c prof_splay.o -o test_splay


src.tgz: Makefile test_cheap_splay.c test_create.c test_destroy.c test_splay.c splay.c test_coupe.c test_delete.c test_insert.c test_union.c splay.h ../sujet.pdf
	gcc -c -Wall prof_splay.c
	mkdir src
	cp  Makefile test_cheap_splay.c test_create.c test_destroy.c test_splay.c splay.c test_coupe.c test_delete.c test_insert.c test_union.c splay.h prof_splay.o src
	tar -zcf src.tgz src
	\rm -r src

clean:
	-rm -f *~ test_create test_destroy test_insert test_coupe test_delete test_union test_cheap_splay test_splay src.tgz
