all: main.o My_Integer.o Array.o
	g++ -std=c++11 main.o My_Integer.o Array.o -o program.exe
main.o: main.cpp Array.hpp My_Integer.hpp
	g++ -std=c++11 -c main.cpp
My_Integer.o: My_Integer.cpp My_Integer.hpp Object.hpp
	g++ -std=c++11 -c My_Integer.cpp
Array.o: Object.hpp Array.cpp Array.hpp
	g++ -std=c++11 -c Array.cpp
clean:
	del /S *.o
