#include "Matrix.hpp"
#include <iostream>
#include <stdexcept>

int main(int argv,char** argc){
  Matrix tmp0(2,4);
  Matrix tmp1(4,2);
  for(int i{0};i<tmp0.get_size();++i){
    tmp0.set(i,i);
    tmp1.set(i,i);
  }
  std::cout<<"this is a"<<std::endl;
  std::cout<<tmp0<<std::endl;
  std::cout<<"this is b"<<std::endl;
  std::cout<<tmp1<<std::endl;
  std::cout<<"/2\n"<<(tmp0/2)<<std::endl;
  std::cout<<"*2\n"<<(tmp1*2)<<std::endl;
  std::cout<<"+22\n"<<(tmp0+22)<<std::endl;
  std::cout<<"-22\n"<<(tmp1-22)<<std::endl;
  try{
    std::cout<<"a+b\n"<<(tmp0+tmp1)<<std::endl;
  }
  catch(std::invalid_argument a){
    std::cout<<a.what()<<std::endl;
  }
  try{
    std::cout<<"a-b\n"<<(tmp0-tmp1)<<std::endl;
  }
  catch(std::invalid_argument a){
    std::cout<<a.what()<<std::endl;
  }
  std::cout<<"a+a\n"<<(tmp0+tmp0)<<std::endl;
  std::cout<<"a-a\n"<<(tmp0-tmp0)<<std::endl;
  std::cout<<"----------------------"<<std::endl;
  std::cout<<tmp0<<std::endl;
  std::cout<<"  *"<<std::endl;
  std::cout<<tmp1<<std::endl; 
  std::cout<<"----------------------"<<std::endl;
  std::cout<<(tmp0*tmp1)<<std::endl;
  std::cout<<"----------------------"<<std::endl;
  std::cout<<"a transpose\n"<<tmp0.transpose()<<std::endl;
  std::cout<<"a^t == a "<<(tmp0.transpose() == tmp1)<<std::endl;
  std::cout<<"a == a "<<(tmp0==tmp0)<<std::endl;

  try{
    std::cout<<"Det of a"<<(tmp0.Det())<<std::endl;
  }
  catch(std::runtime_error a){
    std::cout<<std::endl;
    std::cout<<a.what()<<std::endl;
  }
  Matrix tmp2(3,3);
  for(int i{0};i<tmp2.get_size();++i){
    tmp2.set(i,i);
  }
  std::cout<<"this is c:: "<<std::endl;
  std::cout<<tmp2<<std::endl;
  std::cout<<"Det of c =>  "<<tmp2.Det();
  return 0;
}


