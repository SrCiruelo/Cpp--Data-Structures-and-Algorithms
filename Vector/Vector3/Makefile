all: main.o Vector3.o ../Vector4/Vector4.o ../Vector2/Vector2.o
	g++ -std=c++11 main.o Vector3.o  ../Vector4/Vector4.o ../Vector2/Vector2.o -o program.exe
main.o: Vector3.hpp main.cpp
	g++ -std=c++11 main.cpp -c -o main.o
Vector3.o: Vector3.hpp Vector3.cpp
	g++ -std=c++11 Vector3.cpp -c -o Vector3.o
clean:
	del *.o
