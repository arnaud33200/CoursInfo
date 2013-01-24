CC=g++ -I/usr/include/SDL -L/usr/lib -lSDLmain -lSDL -lSDL_image -lSDL_ttf

TARGET= diamant
SOURCES= main.cc init.cc image.cc game.cc menu.cc solution.cc
OBJETS= $(SOURCES:.cc=.o)

$(TARGET) : $(OBJETS)
		$(CC) $^ -o $@
		
main.o : main.cc init.hh image.hh const.hh game.hh menu.hh
		$(CC) -c $<
		
init.o : init.cc init.hh const.hh
		$(CC) -c $<
		
image.o : image.cc image.hh
		$(CC) -c $<
		
game.o: game.cc game.hh ressources.hh const.hh solution.hh
		$(CC) -c $<
		
menu.o : menu.cc menu.hh ressources.hh image.hh const.hh
		$(CC) -c $<
		
solution.o: solution.cc solution.hh const.hh
		$(CC) -c $<

# CLEAN

clean:
		rm -v *~ *.o
