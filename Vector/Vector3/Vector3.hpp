#pragma once
#include <iostream>
class Vector4;
class Vector2;

class Vector3{
public:
  float x;
  float y;
  float z;
  Vector3();
  Vector3(float,float,float);
  Vector3(Vector3&);
  Vector3(Vector3&&);
  Vector3& operator=(const Vector3&);
  Vector3& operator=(Vector3&&);
  bool operator==(const Vector3&) const;
  bool operator!=(const Vector3&) const;
  Vector3 operator+(const Vector3&) const;
  Vector3 operator-(const Vector3&) const;
  Vector3 operator*(float) const;
  Vector3& operator+=(const Vector3&);
  Vector3& operator-=(const Vector3&);
  Vector3& operator*=(float);
  operator Vector2() const;
  operator Vector4() const;
  ~Vector3() = default;
  
};

Vector3 operator*(float,const Vector3&);
std::ostream& operator<<(std::ostream&, const Vector3&);
