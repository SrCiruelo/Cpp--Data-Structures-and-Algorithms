#include "Array.hpp"
#include <stdexcept>
#include <algorithm>

Array::Array():count{0},elements{nullptr}{};

void Array::push_back(Object* a){
  ++count;
  if(count == 1){
    elements = new Object*[1];
    elements[0] = a;
  }
  else{
    Object** tmp = new Object*[count];
    for(size_t i{0};i<count-1;++i){
      tmp[i] = elements[i];
    }
    delete[] elements;
    elements = tmp;
    elements[count-1] = a;
  }
};

Object* Array::get(size_t index){
  if(index >= count){
    throw std::out_of_range{"Index greater than count"};
  }
  return elements[index];
};
void Array::bubble_sort(){
  Object** end = elements + count;
  bool has_swaped{true};
  while(has_swaped)
  {
    has_swaped = false;
    for(Object** it{elements}; it!=end;++it){
      if((*(it+1))->less_than(*it)){
	  std::swap(*it,*(it+1));
	  has_swaped = true;
	};
    }
  }
}
void Array::sort(){

  bubble_sort();
};
