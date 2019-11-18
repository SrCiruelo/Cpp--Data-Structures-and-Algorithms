#include "Vector2.hpp"
#include "../Vector3/Vector3.hpp"
#include "../Vector4/Vector4.hpp"

Vector2::Vector2():x{0},y{0}{}

Vector2::Vector2(float x,float y):x{x},y{y}{};

Vector2::Vector2(Vector2& other):x{other.x},y{other.y}{};

Vector2::Vector2(Vector2&& other):x{other.x},y{other.y}
{
  other.x = 0;
  other.y = 0;
};

Vector2& Vector2::operator=(const Vector2& other){
  x = other.x;
  y = other.y;
  return *this;
}

Vector2& Vector2::operator=(Vector2&& other){
  x = other.x;
  y = other.y;
  other.x = 0;
  other.y = 0;
  return *this;
}

bool Vector2::operator==(const Vector2& other) const{
  return other.x==x && other.y==y;
}

bool Vector2::operator!=(const Vector2& other) const{
  return (other.x!=x || other.y!=y);
}

Vector2 Vector2::operator+(const Vector2& other) const{
  return Vector2{x + other.x,other.y + y};
}

Vector2 Vector2::operator-(const Vector2& other)const{
  return Vector2{x - other.x,y - other.y};
}


Vector2 Vector2::operator*(float other) const{
  Vector2 tmp{x*other,y*other};
  return tmp;
};

Vector2& Vector2::operator+=(const Vector2& other){
  x += other.x;
  y += other.y;
  return *this;
}

Vector2& Vector2::operator-=(const Vector2& other){
  x -= other.x;
  y -= other.y;
  return *this;
}

Vector2& Vector2::operator*=(float other){
  x *= other;
  y *= other;
  return *this;
}

Vector2::operator Vector3() const{
  return Vector3{x,y,0};
}

Vector2::operator Vector4() const{
  return Vector4{x,y,0,0};
}

Vector2 operator*(float a,const Vector2& vec){
  return vec*a;
}

std::ostream& operator<<(std::ostream& out, const Vector2& f)
{
  return out << f.x << " " << f.y;
}
