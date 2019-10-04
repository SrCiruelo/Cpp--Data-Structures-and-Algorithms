all: main.o XOR_LinkedList.o
	g++ -std=c++11 XOR_LinkedList.o main.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp -o main.o

XOR_LinkedList.o: XOR_LinkedList.cpp XOR_LinkedList.hpp
	g++ -std=c++11 -c XOR_LinkedList.cpp -o XOR_LinkedList.o

clean_unix:
	rm *.o
clean_win:
	del /S *.o
