CC=g++ -I/usr/include/SDL -L/usr/lib -lSDLmain -lSDL -lSDL_image -lSDL_ttf

TARGET= diamond_hunter
SOURCES= main.cc init.cc image.cc game.cc menu.cc change.cc verif.cc action.cc gameover.cc
OBJETS= $(SOURCES:.cc=.o)

$(TARGET) : $(OBJETS)
		$(CC) $^ -o ../$@
		
main.o : main.cc init.hh image.hh game.hh menu.hh gameover.hh
		$(CC) -c $<
		
init.o : init.cc init.hh 
		$(CC) -c $<
		
image.o : image.cc image.hh
		$(CC) -c $<
		
game.o: game.cc game.hh 
		$(CC) -c $<
		
menu.o : menu.cc menu.hh image.hh 
		$(CC) -c $<
		
change.o: change.cc change.hh verif.hh
		$(CC) -c $<
		
verif.o: verif.cc verif.hh
		$(CC) -c $<
		
action.o: action.cc action.hh struct.hh image.hh
		$(CC) -c $<
		
gameover.o: gameover.cc gameover.hh image.hh
		$(CC) -c $<

# CLEAN

clean:
		rm -v *~ *.o
