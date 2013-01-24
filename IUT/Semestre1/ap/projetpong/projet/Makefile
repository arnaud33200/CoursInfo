CCSDL=g++ -I/usr/include/SDL -L/usr/lib -lSDLmain -lSDL -lSDL_image -lSDL_ttf
CC=g++
OBJETS= move.o main.o
TARGET= pong

$(TARGET) : $(OBJETS)
		$(CCSDL) $(OBJETS) -o $(TARGET)
		
move.o : move.cc move.h const.h
		$(CCSDL) -c move.cc
		
main.o : main.cc move.h const.h
		$(CCSDL) -c main.cc

clean :
	rm -f *~ *.o
	
