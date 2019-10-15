#pragma once
class Object{
public:
  virtual  const  char* to_string() const = 0;
  virtual const char* get_class_name() const = 0;
  virtual bool less_than(const Object*) = 0;
};
