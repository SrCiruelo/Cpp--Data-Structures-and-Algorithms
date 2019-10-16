all: main.o Vector4.o ../Vector3/Vector3.o ../Vector2/Vector2.o 
	g++ -std=c++11 main.o Vector4.o ../Vector3/Vector3.o ../Vector2/Vector2.o  -o program.exe
main.o: Vector4.hpp main.cpp
	g++ -std=c++11 main.cpp -c -o main.o
Vector4.o: Vector4.hpp Vector4.cpp ../Vector3/Vector3.hpp
	g++ -std=c++11 Vector4.cpp  -c -o Vector4.o
clean:
	del *.o
