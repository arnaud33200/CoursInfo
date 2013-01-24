CC=g++ 

OBJECTS= morpion.o main.o

TARGET= morpion

$(TARGET) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

morpion.o : morpion.cc morpion.h
	$(CC) -c morpion.cc

main.o : main.cc morpion.h
	$(CC) -c main.cc

clean :
	rm -f *~ *.o $(TARGET)
