all: main.o Vector.o
	g++ -std=c++11 main.o Vector.o -o program.exe
main.o: Vector.hpp Vector_main.cpp
	g++ -std=c++11 Vector_main.cpp -c -o main.o
Vector.o: Vector2/Vector2.hpp Vector2/Vector2.cpp Vector2/Vector2.o Vector3/Vector3.hpp Vector3/Vector3.cpp Vector3/Vector3.o Vector4/Vector4.hpp Vector4/Vector4.cpp Vector4/Vector4.o
	g++ -std=c++11 Vector.cpp -c -o Vector.o
