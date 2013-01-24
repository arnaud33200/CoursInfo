CC=gcc -L/usr/X11R6/lib -lglut -lGLU
File=tuto1.c
Object=$(File:.c=.o)

Q1 : $(Object)
	$(CC) $^ -o $@

tuto1.o : tuto1.c
	$(CC) -c $<

clean :
	rm -vfr *.o
