#include "LinkedList.hpp"
#include <cstddef>

template <typename O>
LinkedList<O>::LinkedList():count{0}{};

template <typename O>
LinkedList<O>::push_back(O val){
  if(count==0){
    first = new Node<O>;
    first -> val = val;
    last = first;
  }
  else{
    Node* tmp = new Node<O>;
    tmp -> val = val;
    last -> next = tmp;
    tmp -> prev = last;
    last = tmp;
  }
}
template <typename O>
LinkedList<O>::LinkedList(std::initializer_list<O> lst){
  std::initializer_list<O>::iterator it = lst.begin();
  for(  ;
	it != lst.end();++it){
    push_back(*it);
  }
}
template <typename O>
O& LinkedList<O>::get(size_t){

}
template <typename O>
LinkedList<O>::push_back(O){

};

template <typename O>
LinkedList<O>::insert(O){

};
