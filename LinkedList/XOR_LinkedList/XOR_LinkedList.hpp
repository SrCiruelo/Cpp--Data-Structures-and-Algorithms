#include <stdexcept>
#include <cstddef>
#include <initializer_list>
#include <iostream>

template <typename O>
class XOR_LinkedList{
private:

  struct Node{
    O val;
    Node* xorptr;
  };
  Node* last;
  Node* first;
  size_t count;
  Node* XOR( Node*, Node*) const;
  
public:
  class iterator{
    Node* current_ptr;
    iterator();
    iterator(const iterator&);
    iterator& operator=(const iterator&);
    iterator& operator++();
    iterator& operator--();
    iterator operator++(int);
    iterator operator--(int);
    O& operator*();
  };

  XOR_LinkedList();
  XOR_LinkedList(std::initializer_list<O>);
  XOR_LinkedList(const XOR_LinkedList&);
  XOR_LinkedList(XOR_LinkedList&&);
  XOR_LinkedList& operator=(const XOR_LinkedList&);
  XOR_LinkedList& operator=(XOR_LinkedList&&);
  ~XOR_LinkedList();
  O& get(std::size_t) const;
  O& operator[](size_t i);
  size_t Count();
  void push_back(O);
  void insert(O,size_t);
  void del(size_t);
  size_t find(O);
};



template <typename O>
XOR_LinkedList<O>::XOR_LinkedList():count{0},first{nullptr},last{nullptr}{};

template <typename O>
size_t XOR_LinkedList<O>::Count(){return count;}

template <typename O>
typename XOR_LinkedList<O>::Node* XOR_LinkedList<O>::XOR( Node* a, Node* b) const {
  return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}


template <typename O>
void XOR_LinkedList<O>::push_back(O val){
  if(count==0){
    first = new Node;
    first -> val = val;
    first -> xorptr = nullptr;
    last = first;
  }
  else{
    Node* tmp = new Node;
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
O& XOR_LinkedList<O>::get(size_t index)const{
  if(index>count-1){
    throw std::out_of_range{"Index greater than count"};
  }
   Node* pointer0{first};
   Node* pointer1{nullptr};
  for(size_t i{0};i<index;++i){
     Node* tmp_pointer{pointer0};
    pointer0 = XOR(pointer0->xorptr,pointer1);
    pointer1 = tmp_pointer;
  }
  return pointer0->val;
};

template <typename O>
XOR_LinkedList<O>::XOR_LinkedList(const XOR_LinkedList<O>& lst) :count{0},first{nullptr},last{nullptr}{
  for(size_t i{0};i<lst.count;++i){
    push_back(lst.get(i));
  }
}

template <typename O>
XOR_LinkedList<O>::XOR_LinkedList(XOR_LinkedList<O>&& lst) :count{lst.count},first{lst.first},last{lst.last}
{
  lst.first = nullptr;
  lst.last = nullptr;
  lst.count = 0;
}

template <typename O>
XOR_LinkedList<O>& XOR_LinkedList<O>::operator=(const XOR_LinkedList<O>& lst){
  for(size_t i{0};i<lst.count;++i){
    push_back(lst.get(i));
  }
  return *this;
}

template <typename O>
XOR_LinkedList<O>& XOR_LinkedList<O>::operator=(XOR_LinkedList<O>&& lst){
  first = lst.first;
  last = lst.last;
  count = lst.count;
  lst.first = nullptr;
  lst.last = nullptr;
  lst.count = 0;
  return *this;
}

template <typename O>
O& XOR_LinkedList<O>::operator[](size_t index){
  if(index>count-1){
    throw std::out_of_range{"Index greater than count"};
  }
  Node* pointer0{first};
  Node* pointer1{nullptr};
  for(size_t i{0};i<index;++i){
    Node* tmp_pointer{pointer0};
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
  Node* pointer0{first};
  Node* pointer1{nullptr};
  for(size_t i{0};i<index;++i){
    Node* tmp_pointer{pointer0};
    pointer0 = XOR(pointer0->xorptr,pointer1);
    pointer1 = tmp_pointer;
  } 
  Node* tmp = new Node;
  tmp -> val = val;
  tmp -> xorptr = XOR(pointer0,pointer1);
  pointer0 -> xorptr = XOR(XOR(pointer0->xorptr,pointer1),tmp);
  pointer1 -> xorptr = XOR(XOR(pointer1->xorptr,pointer0),tmp);
  ++count;
};

template <typename O>
XOR_LinkedList<O>::~XOR_LinkedList(){
  if(Count()==0){
    return;
  }
  if(Count()==1){
    delete first;
    return;
  }
  Node* pointer0{first->xorptr};
  Node* pointer1{first};
  for(size_t i{0};i<Count()-2;++i){
    Node* tmp_pointer{pointer0};
    pointer0 = XOR(pointer0->xorptr,pointer1);
    pointer1 = tmp_pointer;
    delete (XOR(pointer1->xorptr,pointer0));
  }
  delete pointer0;
  delete pointer1;
}

template <typename O>
size_t XOR_LinkedList<O>::find(O val){
  size_t i{0};
  for(;i<count && get(i)!=val;++i);
  if(i==count)return i;
  return -1;
}

template <typename O>
void XOR_LinkedList<O>::del(size_t index){
  if(index>count-1){
    throw std::out_of_range{"Index greater than count"};
  }
  if(index==0){
    Node* my_node = first->xorptr;
    my_node->xorptr = XOR(my_node->xorptr,first);
    delete first;
    first = my_node;
    --count;
    return;
  }
  if(index==count-1){
    Node* my_node = last->xorptr;
    my_node->xorptr = XOR(my_node->xorptr,last);
    delete last;
    last = my_node;
    --count;
    return;
  }
  Node* current = first->xorptr;
  Node* last = first;
  for(size_t i{0};i<index-1;++i){
    Node* tmp_pointer = current;
    current = XOR(current->xorptr,last);
    last = tmp_pointer;
  }
  Node* next = XOR(current->xorptr,last);
  last->xorptr = XOR(XOR(current,last->xorptr),next);
  next->xorptr = XOR(XOR(current,next->xorptr),last);
  delete current;
  --count;
}

template <typename O>
XOR_LinkedList<O>::iterator iterator():current_ptr{first}{};

template <typename O>
XOR_LinkedList<O>::iterator iterator(const iterator& a):a{a.current_ptr}{};

template <typename O>
XOR_LinkedList<O>::iterator operator=(const iterator& a){
  current_ptr = a.current_ptr;
}

template <typename O>
XOR_LinkedList<O>::iterator operator++(){
  if(current_ptr->next != nullptr)
    current_ptr = current_ptr->next;
}

template <typename O>
XOR_LinkedList<O>::iterator operator++(){
  if(current_ptr->last != nullptr)
    current_ptr = current_ptr->last;
}

template <typename O>
XOR_LinkedList<O>::iterator operator++(int){
  if(current_ptr->last != nullptr){
    XOR_LinkedList<O>::iterator tmp = *this;
    current_ptr = current_ptr->next;
  }
  else{
    return *this;
  }
}
