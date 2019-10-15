#pragma once
#include "Object.hpp"

class My_Integer:public Object{
private:
  
public:
  int val;
  My_Integer();
  My_Integer(int);
  const char* to_string() const;
  const char* get_class_name() const;
  bool less_than(const Object*);
};
