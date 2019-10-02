all: main.o LinkedList.o
	g++ LinkedList.o main.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

LinkedList.o: LinkedList.cpp LinkedList.hpp
	g++ -c LinkedList.cpp -o LinkedList.o

clean:
	del /S *.o
