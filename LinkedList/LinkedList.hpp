#include <cstddef>
#include <initializer_list>

template <typename O>
class LinkedList{
private:
  template<typename T>
  struct Node{
    T val;
    Node* next;
    Node* prev;
  };
  Node<O>* last;
  Node<O>* first;
  size_t count;
public:
  LinkedList();
  LinkedList(std::initializer_list<O>);
  ~LinkedList();
  O& get(std::size_t);
  void push_back(O);
  void insert(O);
};
