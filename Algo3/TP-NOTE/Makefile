CFLAGS=-Wall -g

all: test_create test_destroy test_get_min test_insert test_remove_min test_merge test_heap2_recursif test_heap2_iteratif

test_create: test_create.c prof_heap1.o heap1.h heap1.c
	gcc $(CFLAGS) test_create.c heap1.c prof_heap1.o -o test_create

test_get_min: test_get_min.c prof_heap1.o heap1.h heap1.c
	gcc $(CFLAGS) test_get_min.c heap1.c prof_heap1.o -o test_get_min

test_insert: test_insert.c prof_heap1.o heap1.h heap1.c
	gcc $(CFLAGS) test_insert.c heap1.c prof_heap1.o -o test_insert

test_remove_min: test_remove_min.c prof_heap1.o heap1.h heap1.c
	gcc $(CFLAGS) test_remove_min.c heap1.c prof_heap1.o -o test_remove_min

test_merge: test_merge.c prof_heap1.o heap1.h heap1.c
	gcc $(CFLAGS) test_merge.c heap1.c prof_heap1.o -o test_merge

test_destroy: test_destroy.c prof_heap1.o heap1.h heap1.c
	gcc $(CFLAGS) test_destroy.c heap1.c prof_heap1.o -o test_destroy

test_heap2_recursif: test_heap2_recursif.c prof_heap2_recursif.o heap2.h heap2_recursif.c
	gcc $(CFLAGS) test_heap2_recursif.c heap2_recursif.c prof_heap2_recursif.o -o test_heap2_recursif

test_heap2_iteratif: test_heap2_iteratif.c prof_heap2_iteratif.o stack.c heap2.h heap2_iteratif.c
	gcc $(CFLAGS) test_heap2_iteratif.c heap2_iteratif.c stack.c prof_heap2_iteratif.o -o test_heap2_iteratif

src.tgz: Makefile test_create.c test_destroy.c test_get_min.c test_insert.c test_remove_min.c\
		heap1.c heap2_recursif.c heap2_iteratif.c test_merge.c test_heap2_recursif.c\
		test_heap2_iteratif.c prof_heap1.o\
		prof_heap2_recursif.o prof_heap2_iteratif.o heap1.h heap2.h stack.h stack.c ../2013_algo3_tp_note.pdf
	mkdir src
	gcc -c prof_heap1.c
	gcc -c prof_heap2_recursif.c
	gcc -c prof_heap2_iteratif.c
	cp  Makefile *.h test*.c heap*.c prof*.o stack.c ../2013_algo3_tp_note.pdf src
	tar -zcf src.tgz src
	\rm -r src

clean:
	-rm -f *~ test_create test_destroy test_insert test_remove_min test_get_min test_heap2_recursif\
	       test_heap2_iteratif test_merge

mrproper: clean
	-rm *.o
