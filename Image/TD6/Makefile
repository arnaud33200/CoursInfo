CC = g++
CFLAGS = -g -Wall
LDFLAGS = -L/usr/X11R6/lib -lm -lGL -lglut -lGLU -ltiff -lGLEW
TARGETS= td6_exo1 td6_exo2 td6_exo3 td6_exo4 td6_exo5 td6_exo6

all: $(TARGETS)

$(TARGETS): 
	$(CC) $(CFLAGS) $@.c  $(LDFLAGS)  -o $@

clean:
	rm -f $(TARGETS)
