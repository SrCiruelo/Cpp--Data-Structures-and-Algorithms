#include "LinkedList.hpp"
#include <stdexcept>

template <typename O>
LinkedList<O>::LinkedList():count{0}{};

template <typename O>
size_t LinkedList<O>::Count(){return count;}

template <typename O>
void LinkedList<O>::push_back(O val){
  if(count==0){
    first = new Node<O>;
    first -> val = val;
    last = first;
  }
  else{
    Node<O>* tmp = new Node<O>;
    tmp -> val = val;
    last -> next = tmp;
    tmp -> prev = last;
    last = tmp;
  }
  ++count;
};

template <typename O>
LinkedList<O>::LinkedList(std::initializer_list<O> lst){
  count = 0;
  typename std::initializer_list<O>::iterator it = lst.begin();
  for(  ;it != lst.end();++it){
    push_back(*it);
  }
};

template <typename O>
O& LinkedList<O>::get(size_t index){
  if(index>count-1){
    throw std::out_of_range{"Index greater than count"};
  }
  Node<O>* pointer{first};
  for(size_t i{0};i<index;++i){
    pointer = pointer->next;
  }
  return pointer->val;
};
template <typename O>
O& LinkedList<O>::operator[](size_t index){
  if(index>count-1){
    throw std::out_of_range{"Index greater than count"};
  }
  Node<O>* pointer{first};
  for(size_t i{0};i<index;++i){
    pointer = pointer->next;
  }
  return pointer->val;
};

template <typename O>
void LinkedList<O>::insert(O val,size_t index){
  if(index>count-1){
    throw std::out_of_range{"Index greater than count"};
  }
  if(index==count-1)
  {
      push_back(val);
      return;
  }
  Node<O>* pointer_0{first};
  for(size_t i{0};i<index;++i){
    pointer_0 = pointer_0->next;
  }
  Node<O>* pointer_1{pointer_0->next}; 
  Node<O>* tmp = new Node<O>;
  tmp -> val = val;
  pointer_0 -> next = tmp;
  tmp -> prev = pointer_0;
  pointer_1 -> prev = tmp;
  tmp -> next = pointer_1;
  ++count;
};

template <typename O>
LinkedList<O>::~LinkedList(){
  Node<O>* pointer0{first};
  Node<O>* pointer1{first};
  for(size_t i{0};i<count;++i){
    pointer1 = pointer0->next;
    delete pointer0;
    pointer0 = pointer1;
  }
}

template class LinkedList<int>;
template class LinkedList<char>;
