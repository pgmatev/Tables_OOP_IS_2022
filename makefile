OBJ = main.o Vector.hh String.o Table.o Row.o Type.o IntegerType.o
CC = g++
CFLAGS = -g -Wall -pedantic

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

main.o: main.cpp
	$(CC) -c ./main.cpp
String.o: String.cpp String.hh
	$(CC) -c ./String.cpp
Table.o: Table.cpp Table.hh
	$(CC) -c ./Table.cpp
Row.o: Row.cpp Row.hh
	$(cc) -c ./Row.cpp
Type.o: Type.cpp Type.hh
	$(CC) -c ./Type.cpp
IntegerType.o: IntegerType.cpp IntegerType.hh
	$(CC) -c ./IntegerType.cpp