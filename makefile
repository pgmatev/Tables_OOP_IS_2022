OBJ = main.o Vector.hh String.o
CC = g++
CFLAGS = -g -Wall -pedantic

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

main.o: main.cpp
	$(CC) -c ./main.cpp
String.o: String.cpp String.hh
	$(CC) -c ./String.cpp