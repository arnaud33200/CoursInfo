# Makefile
CFLAGS=-g -Wall

all: test_avl_recursif perf_avl_recursif test_avl_iteratif perf_avl_iteratif

test_avl_recursif: test_avl.c avl.h avl_recursif.c
	gcc $(CFLAGS) test_avl.c avl_recursif.c -o test_avl_recursif

perf_avl_recursif: perf_avl.c avl.h avl_recursif.c
	gcc $(CFLAGS) perf_avl.c avl_recursif.c -o perf_avl_recursif

test_avl_iteratif: test_avl.c avl.h avl_iteratif.c
	gcc $(CFLAGS) test_avl.c avl_iteratif.c stack.c -o test_avl_iteratif

perf_avl_iteratif: perf_avl.c avl.h avl_iteratif.c
	gcc $(CFLAGS) perf_avl.c avl_iteratif.c stack.c -o perf_avl_iteratif

clean:
	rm -f *.o *~ test_avl_recursif perf_avl_recursif test_avl_iteratif perf_avl_iteratif
