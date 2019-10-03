#include "XOR_LinkedList.hpp"
#include <stdexcept>
#include <iostream>


template <typename O>
XOR_LinkedList<O>::XOR_LinkedList():count{0}{};

template <typename O>
size_t XOR_LinkedList<O>::Count(){return count;}

template <typename O>
typename XOR_LinkedList<O>::template Node<O>* XOR_LinkedList<O>::XOR(Node<O>* a,Node<O>* b){
  return (Node<O>*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

template <typename O>
void XOR_LinkedList<O>::push_back(O val){
  if(count==0){
    first = new Node<O>;
    first -> val = val;
    first -> xorptr = nullptr;
    last = first;
  }
  else{
    Node<O>* tmp = new Node<O>;
    tmp -> val = val;
    last -> xorptr = XOR(tmp,last->xorptr);
    tmp -> xorptr = last;
    last = tmp;
  }
  ++count;
};

template <typename O>
XOR_LinkedList<O>::XOR_LinkedList(std::initializer_list<O> lst){
  count = 0;
  typename std::initializer_list<O>::iterator it = lst.begin();
  for(  ;it != lst.end();++it){
    push_back(*it);
  }
};

template <typename O>
O& XOR_LinkedList<O>::get(size_t index){
  if(index>count-1){
    throw std::out_of_range{"Index greater than count"};
  }
  Node<O>* pointer0{first};
  Node<O>* pointer1{nullptr};
  for(size_t i{0};i<index;++i){
    Node<O>* tmp_pointer{pointer0};
    pointer0 = XOR(pointer0->xorptr,pointer1);
    pointer1 = tmp_pointer;
  }
  return pointer0->val;
};
template <typename O>
O& XOR_LinkedList<O>::operator[](size_t index){
  if(index>count-1){
    throw std::out_of_range{"Index greater than count"};
  }
  Node<O>* pointer0{first};
  Node<O>* pointer1{nullptr};
  for(size_t i{0};i<index;++i){
    Node<O>* tmp_pointer{pointer0};
    pointer0 = XOR(pointer0->xorptr,pointer1);
    pointer1 = tmp_pointer;
  }
  return pointer0->val;
};

template <typename O>
void XOR_LinkedList<O>::insert(O val,size_t index){
  if(index>count-1){
    throw std::out_of_range{"Index greater than count"};
  }
  if(index==count-1){
    push_back(val);
    return;
  }
  Node<O>* pointer0{first};
  Node<O>* pointer1{nullptr};
  for(size_t i{0};i<index;++i){
    Node<O>* tmp_pointer{pointer0};
    pointer0 = XOR(pointer0->xorptr,pointer1);
    pointer1 = tmp_pointer;
  } 
  Node<O>* tmp = new Node<O>;
  tmp -> val = val;
  tmp -> xorptr = XOR(pointer0,pointer1);
  pointer0 -> xorptr = XOR(XOR(pointer0->xorptr,pointer1),tmp);
  pointer1 -> xorptr = XOR(XOR(pointer1->xorptr,pointer0),tmp);
  ++count;
};

template <typename O>
XOR_LinkedList<O>::~XOR_LinkedList(){
  Node<O>* pointer0{first};
  Node<O>* pointer1{nullptr};
  size_t i{0};
  for(;i<2;++i){
    Node<O>* tmp_pointer{pointer0};
    pointer0 = XOR(pointer0->xorptr,pointer1);
    pointer1 = tmp_pointer;
    std::cout<<(pointer1->val)<<std::endl;
  }
  for(;i<Count()-1;++i){
    Node<O>* tmp_pointer{pointer0};
    pointer0 = XOR(pointer0->xorptr,pointer1);
    pointer1 = tmp_pointer;
    std::cout<<((XOR(pointer0->xorptr,pointer1))->val)<<std::endl;
    delete (XOR(pointer0->xorptr,pointer1));
  }
  delete pointer0;
  delete pointer1;
}

template class XOR_LinkedList<int>;
template class XOR_LinkedList<char>;
