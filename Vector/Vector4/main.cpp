#include "Vector4.hpp"
#include "../Vector3/Vector3.hpp"

int main(int argv,char** argc){
  Vector4 a;
  Vector4 b{23,1,0,23};
  Vector4 c{2,4,3,1100};
  Vector4 d{4,5,72,32};
  Vector4 e{4,5,72,32};
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
  Vector3 j{b};
  std::cout<<j<<std::endl;
  return 0;
}
