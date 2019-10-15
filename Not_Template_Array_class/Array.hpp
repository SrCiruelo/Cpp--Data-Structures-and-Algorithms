#include "Object.hpp"
#include <cstdlib>

class Array{
private:
  Object** elements;
  size_t count;
  void bubble_sort();
public:
  Array();
  void push_back(Object*);
  Object* get(size_t index);
  ~Array() = default;
  void sort();
};
