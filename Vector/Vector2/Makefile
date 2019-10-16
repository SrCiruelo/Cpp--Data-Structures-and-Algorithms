all: main.o Vector2.o ../Vector3/Vector3.o ../Vector4/Vector4.o
	g++ -std=c++11 main.o Vector2.o  ../Vector3/Vector3.o ../Vector4/Vector4.o  -o program.exe
main.o: Vector2.hpp main.cpp
	g++ -std=c++11 main.cpp -c -o main.o
Vector2.o: Vector2.hpp Vector2.cpp
	g++ -std=c++11 Vector2.cpp -c -o Vector2.o
clean:
	del *.o
