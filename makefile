OBJ = main.o Table.o Row.o Type.o IntegerType.o FloatType.o StringType.o CurrencyType.o
CC = g++
CFLAGS = -g -Wall -pedantic

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

main.o: main.cpp
	$(CC) -c ./main.cpp

Table.o: Table.cpp Table.hh
	$(CC) -c ./Table.cpp
Row.o: Row.cpp Row.hh
	$(CC) -c ./Row.cpp
Type.o: Type.cpp Type.hh
	$(CC) -c ./Type.cpp
IntegerType.o: IntegerType.cpp IntegerType.hh
	$(CC) -c ./IntegerType.cpp
FloatType.o: FloatType.cpp FloatType.hh
	$(CC) -c ./FloatType.cpp
StringType.o: StringType.cpp StringType.hh
	$(CC) -c ./StringType.cpp
CurrencyType.o: CurrencyType.cpp CurrencyType.hh
	$(CC) -c ./CurrencyType.cpp