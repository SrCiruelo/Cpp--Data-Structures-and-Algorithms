#include "Vector2.hpp"
#include "../Vector3/Vector3.hpp"
#include "../Vector4/Vector4.hpp"

int main(int argv,char** argc){
  Vector2 a;
  Vector2 b{23,1};
  Vector2 c{2,4};
  Vector2 d{4,5};
  Vector2 e{4,5};
  std::cout<<a<<std::endl;
  std::cout<<b<<std::endl;
  std::cout<<c<<std::endl;
  a = d + e;
  std::cout<<a<<std::endl;
  a *= 4.0f;
  std::cout<<a<<std::endl;
  a += c;
  std::cout<<a<<std::endl;
  a -= b;
  std::cout<<a<<std::endl;
  a = d - e;
  std::cout<<a<<std::endl;
  std::cout<<"d==e :: "<<(d==e)<<std::endl;
  std::cout<<"b!=e :: "<<(b!=e)<<std::endl;
  Vector3 g{b};
  Vector4 h{d};
  std::cout<<g<<std::endl;
  std::cout<<h<<std::endl;
  return 0;
}
