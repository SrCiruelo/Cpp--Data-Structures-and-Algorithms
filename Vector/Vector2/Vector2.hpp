#pragma once
#include <iostream>
class Vector3;
class Vector4;

class Vector2{
public:
  float x;
  float y;
  Vector2();
  Vector2(float,float);
  Vector2(Vector2&);
  Vector2(Vector2&&);
  Vector2& operator=(const Vector2&);
  Vector2& operator=(Vector2&&);
  bool operator==(const Vector2&) const;
  bool operator!=(const Vector2&) const;
  Vector2 operator+(const Vector2&) const;
  Vector2 operator-(const Vector2&) const;
  Vector2 operator*(float) const;
  Vector2& operator+=(const Vector2&);
  Vector2& operator-=(const Vector2&);
  Vector2& operator*=(float);
  operator Vector3() const;
  operator Vector4() const;
};

Vector2 operator*(float,const Vector2&);
std::ostream& operator<<(std::ostream&, const Vector2&);
