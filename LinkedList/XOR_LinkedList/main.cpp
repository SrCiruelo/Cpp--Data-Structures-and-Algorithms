#include <iostream>
#include "XOR_LinkedList.hpp"

template <typename T>
void print_lst(XOR_LinkedList<T> lst){

  for(int i{0};i<lst.Count();++i){
    std::cout<<lst.get(i)<<" ";
  }
};

int main(){
  XOR_LinkedList<int> lst0;
  lst0.push_back(33);
  lst0.push_back(892);
  lst0.push_back(24);
  lst0.push_back(98);
  lst0.push_back(322);
  std::cout<<lst0.get(4)<<std::endl;
  std::cout<<lst0.get(0)<<std::endl;
  std::cout<<lst0.get(1)<<std::endl;
  std::cout<<lst0.get(2)<<std::endl;
  std::cout<<lst0.get(3)<<std::endl;
  std::cout<<lst0.get(4)<<std::endl;
  std::cout<<lst0.Count()<<std::endl;
  XOR_LinkedList<char> lst1 = {'A','E','@','3'};
  std::cout<<lst1.get(0)<<std::endl;
  std::cout<<lst1.get(1)<<std::endl;
  std::cout<<lst1.get(2)<<std::endl;
  std::cout<<lst1.get(3)<<std::endl;
  return 0;
};
