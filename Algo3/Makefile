CFLAGS=-g -Wall

all: test_stack_list perf_stack_list # test_stack_array perf_stack_array test_stack_list_array perf_stack_list_array

test_stack_list: test_stack.c stack.h stack_list.c list.h
	gcc $(CFLAGS) test_stack.c stack_list.c -o test_stack_list

test_stack_array: test_stack.c stack.h stack_array.c
	gcc $(CFLAGS) test_stack.c stack_array.c -o test_stack_array

test_stack_list_array: test_stack_list_array.c stack.h stack_list_array.c
	gcc $(CFLAGS) test_stack_list_array.c stack_list_array.c -o test_stack_list_array

perf_stack_list: perf_stack.c stack.h stack_list.c
	gcc $(CFLAGS) perf_stack.c stack_list.c -o perf_stack_list

perf_stack_array: perf_stack.c stack.h stack_array.c
	gcc $(CFLAGS) perf_stack.c stack_array.c -o perf_stack_array

perf_stack_list_array: perf_stack.c stack.h stack_list_array.c
	gcc $(CFLAGS) perf_stack.c stack_list_array.c -o perf_stack_list_array

clean:
	-rm -f *.o *~ 
	-rm perf_stack_list perf_stack_array perf_stack 
	-rm test_stack_list test_stack_array
