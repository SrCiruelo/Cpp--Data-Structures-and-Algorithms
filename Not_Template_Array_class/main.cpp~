#include "My_Integer.hpp"
#include "Array.hpp"
 #include <iostream>

void print_arr(Array my_arr,size_t count){
  for(size_t i{0};i<count;++i){
    My_Integer* a = dynamic_cast<My_Integer*>(my_arr.get(i));
    std::cout<<a->val<<std::endl;
  };
};

int main(int argv,char** argc){
  Array my_arr;
  My_Integer a{2};
  My_Integer b{3};
  My_Integer c{12};
  My_Integer d;
  my_arr.push_back(&a);
  my_arr.push_back(&b);
  my_arr.push_back(&c);
  my_arr.push_back(&d);
  print_arr(my_arr,4);
  std::cout<<b.to_string()<<std::endl;
  return 0;
};
