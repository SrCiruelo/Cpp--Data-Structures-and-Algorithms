#include "Vector2.hpp"
#include <utility>

Vector2::Vector2(float x,float y):x{x},y{y}{};

Vector2::Vector2(Vector2& other):x{other.x},y{other.y}{};

Vector2::Vector2(Vector2&& other)
  :x{std::exchange(other.x,0)},y{std::exchange(other.y,0)}{}

Vector2& Vector2::operator=(const Vector2& other){
  x = std::exchange(other.x,0);
  y = std::exchange(other.y,0);
  return *this;
}

bool Vector2::operator==(const Vector2& other){
  return other.x==x && other.y==y;
}

bool Vector2::operator!=(const Vector2& other){
  return (other.x!=x || other.y!=y);
}

Vector2 Vector2::operator+(const Vector2& other){
  return Vector2{x + other.x,other.y + y};
}

Vector2 Vector2::operator-(const Vector2& other){
  return Vector2{x - other.x,y - other.y};
}

Vector2 Vector2::operator*(float other){
  return Vector2{x*other,y*other};
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

Vector2 operator*(float a,const Vector2& vec){
  return vec*a;
}

std::ostream& operator<<(std::ostream& out, const Vector2& f)
{
  return out << f.x << " " << f.y;
}
