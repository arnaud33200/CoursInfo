CC= g++

FILE= main.cc view.cc verif.cc saisir.cc end.cc

TARGET= morpion

SOURCES= $(FILE:.cc=.o)

$(TARGET): $(SOURCES)
		$(CC) $^ -o $@
		
main.o: main.cc view.hh verif.hh saisir.hh const.hh
		$(CC) -c main.cc 
		
view.o: view.cc view.hh const.hh
		$(CC) -c view.cc
		
verif.o: verif.cc verif.hh const.hh
		$(CC) -c $<
		
saisir.o: saisir.cc saisir.hh verif.hh const.hh
		$(CC) -c $<
		
end.o: end.cc end.hh verif.hh const.hh
		$(CC) -c $(@:.o=.cc)


# CLEAN

clean:
		rm *~ *.o
