CC=gcc -L/usr/X11R6/lib -lglut
File=main.c
Object=$(File:.c=.o)

Q1 : $(Object)
	$(CC) $^ -o $@

main.o : main.c
	$(CC) -c $<

clean :
	rm -vfr *.o
