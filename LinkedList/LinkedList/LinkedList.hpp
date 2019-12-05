#include <cstddef>
#include <initializer_list>
#include <stdexcept>

#include <iostream>

template <typename O>
class LinkedList{
private:
  struct Node{
    O val;
    Node* next;
    Node* prev;
  };
  Node* last;
  Node* first;
  Node* end_node;
  size_t count;
  
public:
  class iterator{
    Node* current_ptr;    
  public:
    iterator();
    iterator(Node*);
    iterator(const iterator&);
    iterator& operator=(const iterator&);
    iterator& operator++();
    iterator& operator--();
    iterator operator++(int);
    iterator operator--(int);
    bool operator!=(const iterator&);
    bool operator==(const iterator&);
    friend bool LinkedList::del(iterator);
    O& operator*();
  };
  LinkedList();
  LinkedList(std::initializer_list<O>);
  LinkedList(const LinkedList&);
  LinkedList(LinkedList&&);
  ~LinkedList();
  O& get(std::size_t);
  O& operator[](size_t i);
  LinkedList& operator=(const LinkedList&);
  LinkedList& operator=(LinkedList&&);
  bool del(iterator);
  size_t Count() const;
  void push_back(O);
  void insert(O,size_t);
  iterator find(const O&);
  iterator begin() const;
  iterator end() const;
};


template <typename O>
LinkedList<O>::LinkedList():count{0},first{nullptr},last{nullptr},end_node{nullptr}{};

template <typename O>
LinkedList<O>::LinkedList(const LinkedList& a) :count{a.count}{
  if(count==0)return;
  Node* a_current = a.first;
  first = last = new Node;
  end_node = new Node;
  end_node->next = nullptr;
  first -> val = a_current->val;
  Node* my_current = first;
  while(a_current!=a.last){
    my_current->next = new Node;
    my_current->next->prev = my_current;
    my_current = my_current->next;
    a_current = a_current->next;
    my_current->val = a_current->val;
  }
  last = my_current;
  last->next = end_node;
  end_node->prev = last;
}

template <typename O>
LinkedList<O>::LinkedList(LinkedList&& a) :first{a.first},last{a.last},count{a.count},end_node{a.end_node}{
  a.count = 0;
  a.first = nullptr;
  a.last = nullptr;
  a.end_node = nullptr;
}

template <typename O>
LinkedList<O>& LinkedList<O>::operator=(const LinkedList& a){
  if(a.count==0 && count==0)return *this;
  size_t i{0};
  Node* current{first};
  Node* a_current{a.first};
  for(;i<count && i<a.count;++i){
    current->val = a_current->val;
    current = current->next;
    a_current = a_current->next;
  }
  if(i<count){
    last = current->prev;
    last->next = end_node;
    end_node->prev = last;
    count = i;
    for(;i<count;++i){
      current= current->next;
      delete current->prev;
    }
    delete current;
  }
  else{
    if(end_node==nullptr){
      end_node = new Node;
      end_node->next = nullptr;
      end_node->val = 0;
    }
    for(;i<a.count;++i){
      current-> val = a_current->val;
      current->next = new Node;
      current->next->prev = current;
      current = current->next;
      a_current = a_current->next;
    }
    last = current->prev;
    last->next = end_node;
    end_node->prev = last;
    count = a.count;
  }
  return *this;
}

template <typename O>
LinkedList<O>& LinkedList<O>::operator=(LinkedList&& a){
  first = a.first;
  last = a.last;
  count = a.count;
  end_node = a.end_node;
  a.count = 0;
  a.first = nullptr;
  a.last = nullptr;
  a.end_node = nullptr;
  return *this;
}

template <typename O>
size_t LinkedList<O>::Count() const{return count;}

template <typename O>
void LinkedList<O>::push_back(O val){
  if(count==0){
    first = new Node;
    first -> val = val;
    last = first;
    first -> prev = nullptr;
    end_node = new Node();
    end_node->next = nullptr;
    end_node->prev = first;
    first -> next = end_node;
  }
  else{
    Node* tmp = new Node;
    tmp -> val = val;
    last -> next = tmp;
    tmp -> prev = last;
    last = tmp;
    last ->next = end_node;
    end_node->prev = last;
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
  Node* pointer{first};
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
  Node* pointer{first};
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
  Node* pointer_0{first};
  for(size_t i{0};i<index;++i){
    pointer_0 = pointer_0->next;
  }
  Node* pointer_1{pointer_0->next}; 
  Node* tmp = new Node;
  tmp -> val = val;
  pointer_0 -> next = tmp;
  tmp -> prev = pointer_0;
  pointer_1 -> prev = tmp;
  tmp -> next = pointer_1;
  ++count;
};

template <typename O>
LinkedList<O>::~LinkedList(){
  Node* pointer0{first};
  Node* pointer1{first};
  for(size_t i{0};i<count;++i){
    pointer1 = pointer0->next;
    delete pointer0;
    pointer0 = pointer1;
  }
}

template <typename O>
typename LinkedList<O>::iterator LinkedList<O>::find(const O& val){
  LinkedList<O>::iterator i = begin();
  for(;i!=end() && (*i)!=val;++i){
  }
  return i;
}


template <typename O>
 LinkedList<O>::iterator::iterator():current_ptr{nullptr}{};

template <typename O>
 LinkedList<O>::iterator::iterator( LinkedList<O>::Node* a):current_ptr{a}{};

template <typename O>
 LinkedList<O>::iterator::iterator(const iterator& a):current_ptr{a.current_ptr}{};

template <typename O>
typename LinkedList<O>::iterator&  LinkedList<O>::iterator::operator=(const iterator& a){
  current_ptr = a.current_ptr;
  return *this;
}

template <typename O>
typename LinkedList<O>::iterator&  LinkedList<O>::iterator::operator++(){
  if(current_ptr==nullptr)throw std::runtime_error("iterator not initialized");
  if(current_ptr->next != nullptr)
    current_ptr = current_ptr->next;
  return *this;
}

template <typename O>
typename LinkedList<O>::iterator&  LinkedList<O>::iterator::operator--(){
    if(current_ptr==nullptr)throw std::runtime_error("iterator not initialized");
  if(current_ptr->prev != nullptr)
    current_ptr = current_ptr->prev;
  return *this;
}

template <typename O>
typename LinkedList<O>::iterator  LinkedList<O>::iterator::operator++(int){
    if(current_ptr==nullptr)throw std::runtime_error("iterator not initialized");
  if(current_ptr->next != nullptr){
    LinkedList<O>::iterator tmp = *this;
    current_ptr = current_ptr->next;
    return tmp;
  }
  else{
    return *this;
  }
}

template <typename O>
typename LinkedList<O>::iterator  LinkedList<O>::iterator::operator--(int){
  if(current_ptr==nullptr) throw std::runtime_error("iterator not initialized");
  if(current_ptr->prev != nullptr){
    LinkedList<O>::iterator tmp = *this;
    current_ptr = current_ptr->prev;
    return tmp;
  }
  else{
    return *this;
  }
}

template <typename O>
O& LinkedList<O>::iterator::operator*(){
    if(current_ptr==nullptr)throw std::runtime_error("iterator not initialized");
  return current_ptr->val;
}

template <typename O>
bool  LinkedList<O>::iterator::operator==(const  LinkedList<O>::iterator& a){
  return current_ptr==a.current_ptr;
}

template <typename O>
bool  LinkedList<O>::iterator::operator!=(const  LinkedList<O>::iterator& a){
  return current_ptr!=a.current_ptr;
}

template <typename O>
typename LinkedList<O>::iterator LinkedList<O>::begin() const{
  return LinkedList<O>::iterator(first);
}

template <typename O>
typename LinkedList<O>::iterator LinkedList<O>::end() const{
  return LinkedList<O>::iterator(end_node);
}

//No checking ins this function is done so user can input an iterator from other list
template <typename O>
bool LinkedList<O>::del(LinkedList<O>::iterator it){
  Node* tmp = it.current_ptr;
  if(count!=1){
    if(tmp->next==end_node){
      last = last->prev;
      last->next = end_node;
    }
    else if(tmp->prev==nullptr){
      first = first->next;
      first->prev = nullptr;
    }
    else{
      tmp -> prev -> next = tmp->next;
      tmp -> next -> prev = tmp->prev;
    }
  }
  --count;
  delete tmp;
  return true;
}
