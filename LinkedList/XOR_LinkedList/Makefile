all: main.o XOR_LinkedList.o
	g++ XOR_LinkedList.o main.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

XOR_LinkedList.o: XOR_LinkedList.cpp XOR_LinkedList.hpp
	g++ -c XOR_LinkedList.cpp -o XOR_LinkedList.o

clean:
	del /S *.o
