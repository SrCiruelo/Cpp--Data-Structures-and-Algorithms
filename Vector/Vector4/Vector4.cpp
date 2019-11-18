#include "Vector4.hpp"
#include "../Vector3/Vector3.hpp"
#include "../Vector2/Vector2.hpp"

Vector4::Vector4():x{0},y{0},z{0},w{0}{}

Vector4::Vector4(float x,float y,float z,float w):x{x},y{y},z{z},w{w}{};

Vector4::Vector4(Vector4& other):x{other.x},y{other.y},z{other.z},w{other.w}{};

Vector4::Vector4(Vector4&& other):x{other.x},y{other.y},z{other.z},w{other.w}
{
  other.x = 0;
  other.y = 0;
  other.z = 0;
  other.w = 0;
};

Vector4& Vector4::operator=(const Vector4& other){
  x = other.x;
  y = other.y;
  z = other.z;
  w = other.w;
  return *this;
}

Vector4& Vector4::operator=(Vector4&& other){
  x = other.x;
  y = other.y;
  z = other.z;
  w = other.w;
  other.x = 0;
  other.y = 0;
  other.z = 0;
  other.w = w;
  return *this;
}

bool Vector4::operator==(const Vector4& other) const{
  return other.x==x && other.y==y && other.z==z && other.w==other.w;
}

bool Vector4::operator!=(const Vector4& other) const{
  return (other.x!=x || other.y!=y || other.z!=z || other.w!=w);
}

Vector4 Vector4::operator+(const Vector4& other) const{
  return Vector4{x + other.x,other.y + y,other.z + z,w + other.w};
}

Vector4 Vector4::operator-(const Vector4& other)const{
  return Vector4{x - other.x,y - other.y,z - other.z,w - other.w};
}


Vector4 Vector4::operator*(float other) const{
  Vector4 tmp{x*other,y*other,z*other,w*other};
  return tmp;
};

Vector4& Vector4::operator+=(const Vector4& other){
  x += other.x;
  y += other.y;
  z += other.z;
  w += other.w;
  return *this;
}

Vector4& Vector4::operator-=(const Vector4& other){
  x -= other.x;
  y -= other.y;
  z -= other.z;
  w -= other.w;
  return *this;
}

Vector4& Vector4::operator*=(float other){
  x *= other;
  y *= other;
  z *= other;
  w *= other;
  return *this;
}

Vector4::operator Vector3() const{
  Vector3 tmp{x,y,z};
  return tmp;
}

Vector4::operator Vector2() const{
  Vector2 tmp{x,y};
  return tmp;
}

Vector4 operator*(float a,const Vector4& vec){
  return vec*a;
}

std::ostream& operator<<(std::ostream& out, const Vector4& f)
{
  return out << f.x << " " << f.y << " "<< f.z << " "<< f.w;
}
