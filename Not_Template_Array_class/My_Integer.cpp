#include "My_Integer.hpp"
#include <string>

My_Integer::My_Integer():val{0}{}

My_Integer::My_Integer(int val):val{val}{};

const char* My_Integer::to_string() const{
  //Slow implementation but easy
  std::string s = std::to_string(val);
  const char* arr = s;
  return arr;
};

const char* My_Integer::get_class_name() const{
  std::string s = "My_Integer";
  const char* arr = s.c_str();
  return arr;
};
bool My_Integer::less_than(const Object* a){
  const My_Integer* b = dynamic_cast<const My_Integer*>(a);
    return val < b->val;
}
