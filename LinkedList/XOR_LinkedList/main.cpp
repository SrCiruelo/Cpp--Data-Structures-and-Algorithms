#include <iostream>
#include "XOR_LinkedList.hpp"

template <typename T>
void print_lst(XOR_LinkedList<T> lst){
  for(size_t i{0};i<lst.Count();++i){
    std::cout<<lst.get(i)<<"  ";
  }
  std::cout<<std::endl;
};

int main(){
  XOR_LinkedList<int> lst0;
  lst0.push_back(33);
  lst0.push_back(892);
  lst0.push_back(24);
  lst0.push_back(98);
  lst0.push_back(322);
  XOR_LinkedList<char> lst1 = {'A','E','@','3'};
  print_lst(lst0);
  print_lst(lst1);
  return 0;
};
