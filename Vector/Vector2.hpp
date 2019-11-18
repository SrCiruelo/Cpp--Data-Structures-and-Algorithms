#include <iostream>

class Vector2{
public:
  float x;
  float y;
  Vector2()=default;
  Vector2(float,float);
  Vector2(Vector2&);
  Vector2(Vector2&&);
  Vector2& operator=(const Vector2&);
  bool operator==(const Vector2&);
  bool operator!=(const Vector2&);
  Vector2 operator+(const Vector2&);
  Vector2 operator-(const Vector2&);
  Vector2 operator*(float);
  Vector2& operator+=(const Vector2&);
  Vector2& operator-=(const Vector2&);
};

Vector2 operator*(float,const Vector2&);
std::ostream& operator<<(std::ostream&, const Vector2&);
