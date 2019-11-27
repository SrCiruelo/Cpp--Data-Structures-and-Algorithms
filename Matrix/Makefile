all: main.cpp Matrix.hpp Matrix.o
	g++ -std=c++11 main.cpp Matrix.o -o program.exe
Matrix.o: Matrix.hpp Matrix.cpp
	g++ -std=c++11 -c Matrix.cpp -o Matrix.o
