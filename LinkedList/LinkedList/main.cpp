#include <iostream>
#include "XOR_LinkedList.hpp"

template <typename T>
void print_lst(LinkedList<T> lst){
  for(int i{0};i<lst.Count();++i){
    std::cout<<lst.get(i)<<" ";
  }
  std::cout<<std::endl;
}

int main(){
  LinkedList<int> lst0;
  lst0.push_back(33);
  lst0.push_back(892);
  lst0.push_back(24);
  lst0.push_back(98);
  lst0.push_back(322);
  std::cout<<lst0.get(4)<<std::endl;
  print_lst(lst0);
  LinkedList<char> lst1 = {'A','E','@','3'};
  print_lst(lst1);
  return 0;
};
