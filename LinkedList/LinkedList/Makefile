all: main.o LinkedList.o
	g++ -std=c++11 LinkedList.o main.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp -o main.o

LinkedList.o: LinkedList.cpp LinkedList.hpp
	g++ -std=c++11 -c LinkedList.cpp -o LinkedList.o

clean:
	del /S *.o
