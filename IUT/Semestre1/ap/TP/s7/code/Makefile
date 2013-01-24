CC=g++ 

OBJECTS= Tableau.o Main.o

TARGET= tabTest

$(TARGET) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

Tableau.o : Tableau.cc Tableau.h
	$(CC) -c Tableau.cc

Main.o : Main.cc Tableau.h
	$(CC) -c Main.cc

clean :
	rm -f *~ *.o $(TARGET)
# DO NOT DELETE
