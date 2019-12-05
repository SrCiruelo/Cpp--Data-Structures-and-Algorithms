#include "LinkedList.hpp"
#include <iostream>

template <typename T>
void print_LinkedList(LinkedList<T> lst){
  for(int i=0;i<lst.Count();++i){
    std::cout<<lst.get(i)<<"  ";
  }
  std::cout<<std::endl;
  return;
}

template <typename T>
void print_LinkedList_it(LinkedList<T> lst){
  std::cout<<"Iterators:: ";
  typename LinkedList<T>::iterator it = lst.begin();
  while(it!=lst.end()){
    std::cout<<(*it)<<"  ";
    ++it;
  }
  std::cout<<std::endl;
  return;
}

template <typename T>
LinkedList<T> get_list(){
  LinkedList<T> lst = {1,2,3,4,5,6,7,8,9,10};
  return lst;
}
int main(int argv,char** argc){
  LinkedList<int> lst = {1,2,3,4,5,6,7,8,9,10};
  print_LinkedList<int>(lst);
  LinkedList<int> lst0(lst);
  print_LinkedList<int>(lst0);
  std::cout<<(*lst0.end())<<std::endl;
  LinkedList<int> lst2(get_list<int>());
  print_LinkedList<int>(lst2);
  LinkedList<int>::iterator it = lst2.begin();
  std::cout<<"Iterators:: ";
  while(it!=lst2.end()){
    std::cout<<(*it)<<"  ";
    ++it;
  }
  std::cout<<std::endl;
  lst2.del(--it);
  std::cout<<"Delete last ::"<<std::endl;
  print_LinkedList_it<int>(lst2);
  std::cout<<"Lst2=lst0 ::"<<std::endl;
  lst2 = lst0;
  print_LinkedList_it<int>(lst2);
  std::cout<<"Delete first ::"<<std::endl;
  lst2.del(lst2.begin());
  print_LinkedList_it<int>(lst2);
  std::cout<<"lst0=lst2::"<<std::endl;
  lst0 = lst2;
  print_LinkedList_it<int>(lst0);
  LinkedList<int> lst3 = {1};
  lst2 = lst3;
  print_LinkedList_it<int>(lst2);
  lst3 = lst;
  print_LinkedList_it<int>(lst3);
  return 0;
}
























