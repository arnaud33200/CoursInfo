CC=g++ 

OBJECTS= sort.o main.o

TARGET= sortTest

$(TARGET) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

sort.o : sort.cc sort.h
	$(CC) -c sort.cc

main.o : main.cc sort.h
	$(CC) -c main.cc

clean :
	rm -f *~ *.o $(TARGET)
