#include "Vector3.hpp"
#include "../Vector2/Vector2.hpp"
#include "../Vector4/Vector4.hpp"

Vector3::Vector3():x{0},y{0},z{0}{}

Vector3::Vector3(float x,float y,float z):x{x},y{y},z{z}{};

Vector3::Vector3(Vector3& other):x{other.x},y{other.y},z{other.z}{};

Vector3::Vector3(Vector3&& other):x{other.x},y{other.y},z{other.z}
{
  other.x = 0;
  other.y = 0;
  other.z = 0;
};

Vector3& Vector3::operator=(const Vector3& other){
  x = other.x;
  y = other.y;
  z = other.z;
  return *this;
}

Vector3& Vector3::operator=(Vector3&& other){
  x = other.x;
  y = other.y;
  z = other.z;
  other.x = 0;
  other.y = 0;
  other.z = 0;
  return *this;
}

bool Vector3::operator==(const Vector3& other) const{
  return other.x==x && other.y==y && other.z==z;
}

bool Vector3::operator!=(const Vector3& other) const{
  return (other.x!=x || other.y!=y || other.z!=z);
}

Vector3 Vector3::operator+(const Vector3& other) const{
  return Vector3{x + other.x,other.y + y,other.z + z};
}

Vector3 Vector3::operator-(const Vector3& other)const{
  return Vector3{x - other.x,y - other.y,z - other.z};
}


Vector3 Vector3::operator*(float other) const{
  Vector3 tmp{x*other,y*other,z*other};
  return tmp;
};

Vector3& Vector3::operator+=(const Vector3& other){
  x += other.x;
  y += other.y;
  z += other.z;
  return *this;
}

Vector3& Vector3::operator-=(const Vector3& other){
  x -= other.x;
  y -= other.y;
  z -= other.z;
  return *this;
}

Vector3& Vector3::operator*=(float other){
  x *= other;
  y *= other;
  z *= other;
  return *this;
}

Vector3::operator Vector2() const{
  return Vector2{x,y};
}

Vector3::operator Vector4() const{
  return Vector4{x,y,z,0};
}

Vector3 operator*(float a,const Vector3& vec){
  return vec*a;
}

std::ostream& operator<<(std::ostream& out, const Vector3& f)
{
  return out << f.x << " " << f.y << " "<< f.z;
}
