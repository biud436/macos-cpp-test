CC=g++
CFLAGS=-g -Wall
OBJS=main.o
TARGET=app

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

clean: 
	rm -f *.o
	rm -f $(TARGET)

main.o: main.cpp
