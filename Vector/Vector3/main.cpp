#include "Vector3.hpp"
#include "../Vector2/Vector2.hpp"
#include "../Vector4/Vector4.hpp"

int main(int argv,char** argc){
  Vector3 a;
  Vector3 b{23,1,0};
  Vector3 c{2,4,3};
  Vector3 d{4,5,72};
  Vector3 e{4,5,72};
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
  Vector2 k{b};
  Vector4 p{e};
  std::cout<<k<<"\n"<<p<<std::endl;
  return 0;
}
