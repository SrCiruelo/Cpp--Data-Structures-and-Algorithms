#pragma once
#include <iostream>
class Vector3;
class Vector2;

class Vector4{
public:
  float x;
  float y;
  float z;
  float w;
  Vector4();
  Vector4(float,float,float,float);
  Vector4(Vector4&);
  Vector4(Vector4&&);
  Vector4& operator=(const Vector4&);
  Vector4& operator=(Vector4&&);
  bool operator==(const Vector4&) const;
  bool operator!=(const Vector4&) const;
  Vector4 operator+(const Vector4&) const;
  Vector4 operator-(const Vector4&) const;
  Vector4 operator*(float) const;
  Vector4& operator+=(const Vector4&);
  Vector4& operator-=(const Vector4&);
  Vector4& operator*=(float);
  operator Vector3() const;
  operator Vector2() const;
  ~Vector4() = default;
  
};

Vector4 operator*(float,const Vector4&);
std::ostream& operator<<(std::ostream&, const Vector4&);


