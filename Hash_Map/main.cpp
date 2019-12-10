#include <iostream>
#include <string>
#include "Hash_map.hpp"

int main(int argv,char** argc){
  Hash_map<int> my_map;
  my_map.add(3);
  my_map.add(7);
  my_map.add(40);
  std::cout<<(my_map.search(7))<<std::endl;
  std::cout<<(my_map.search(7))<<std::endl;
  std::cout<<(my_map.search(40))<<std::endl;
  std::cout<<(my_map.search(4))<<std::endl;
  Hash_map<std::string> my_map0;
  my_map0.add("hola");
  my_map0.add("que pasa chaval");
  my_map0.add("eh eh eh");
  std::cout<<(my_map0.search("hola"))<<std::endl;
  std::cout<<(my_map0.search("que pasa chaval"))<<std::endl;
  std::cout<<(my_map0.search("eh eh eh"))<<std::endl;
  std::cout<<(my_map0.search("UwU"))<<std::endl;

  Hash_map<std::string>::iterator it = my_map0.begin();
  while(it!=my_map0.end()){
    std::cout<<"escribiendo  ";
    std::cout<<(*it)<<std::endl;
    ++it;
  }
  it--;
  std::cout<<(*(it++))<<std::endl;
  my_map0.del(it);
  it = my_map0.begin();
  std::cout<<"erased item"<<std::endl;
  while(it!=my_map0.end()){
    std::cout<<"escribiendo  ";
    std::cout<<(*it)<<std::endl;
    ++it;
  }
  std::cout<<"Finished without problem"<<std::endl;
  return 0;
}
