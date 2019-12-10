#include "..\LinkedList\LinkedList\LinkedList.hpp"
#include <functional>
#include <iostream>

//Knuth hashing used
constexpr std::size_t hash_number = 2654435769;
//Needs to be a multiple of 2
constexpr std::size_t number_of_buckets = 16;
//p = log2(16)            this number cannot be calculated without a library so we do it by hand as this is constexpr
constexpr std::size_t p= 4;
//hash_number should be and odd number between 2^(r-1) and 2^r where r = sqr(number_of_buckets)
template <typename T>
class Hash_map{
  LinkedList<T>* buckets;
  std::size_t count;
  std::size_t hash(std::size_t);
  std::size_t knuth(std::size_t,std::size_t);
  
public:
   class iterator{
     const LinkedList<T>* buckets;
     typename LinkedList<T>::iterator current_it;
     std::size_t current_bucket;
  public:
    iterator();
     iterator(const typename LinkedList<T>::iterator&,std::size_t current_bucket,const LinkedList<T>* buckets);
    iterator(const iterator&);
    iterator& operator=(const iterator&);
    iterator& operator++();
    iterator& operator--();
    iterator operator++(int);
    iterator operator--(int);
    bool operator!=(const iterator&);
    bool operator==(const iterator&);
    friend bool Hash_map::del(const iterator&);
    T& operator*();
  };
  Hash_map();
  Hash_map(const Hash_map&);
  Hash_map(Hash_map&&);
  Hash_map& operator=(const Hash_map&);
  Hash_map& operator=(Hash_map&&);
  bool add(T val);
  bool del(T val);
  bool del(const iterator&);
  bool search(T val);
  //change current search to find and define search with iterators
  iterator begin();
  iterator end();
  std::size_t Count();
  ~Hash_map();
};


template<typename T>
Hash_map<T>::Hash_map():count{0}{
  buckets = new LinkedList<T>[number_of_buckets]();
}

template<typename T>
Hash_map<T>::Hash_map(const Hash_map& a){
  buckets = new LinkedList<T>[number_of_buckets]();
  for(int i=0;i<number_of_buckets;++i){
    buckets[i] = a.buckets[i];
  }
  count = a.count;
}

template<typename T>
Hash_map<T>::Hash_map(Hash_map&& a){
  buckets = a.buckets;
  count = a.count;
  a.count = 0;
  a.buckets = nullptr;
}

template<typename T>
Hash_map<T>& Hash_map<T>::operator=(const Hash_map& a){
  buckets = new LinkedList<T>[number_of_buckets]();
  for(int i=0;i<number_of_buckets;++i){
    buckets[i] = a.buckets[i];
  }
  count = a.count;
}

template<typename T>
Hash_map<T>& Hash_map<T>::operator=(Hash_map&& a){
  buckets = a.buckets;
  count = a.count;
  a.count = 0;
  a.buckets = nullptr;
}

template<typename T>
std::size_t Hash_map<T>::knuth(std::size_t x,std::size_t p){
  //This is only for 32 bits number
  return (x*hash_number)>>(32-p);
}

template<typename T>
std::size_t Hash_map<T>::hash(std::size_t val){
  return knuth(val,p);
}

template<typename T>
bool Hash_map<T>::add(T val){
  std::hash<T> prehash;
  std::size_t my_hash{hash(prehash(val))};
  typename LinkedList<T>::iterator it = buckets[my_hash].find(val);
  if(it!= buckets[my_hash].end()){
    return false;
  }
  buckets[my_hash].push_back(val);
  ++count;
  return true;
}

template<typename T>
bool Hash_map<T>::del(T val){
  std::hash<T> prehash;
  std::size_t my_hash{hash(prehash(val))};
  typename LinkedList<T>::iterator it = buckets[my_hash].find(val);
  if(it  != buckets[my_hash].end()){
    buckets[my_hash].del(it);
    --count;
    return true;
  }
  return false;
}

template<typename T>
bool Hash_map<T>::search(T val){
  std::hash<T> prehash;
  std::size_t my_hash{hash(prehash(val))};
  typename LinkedList<T>::iterator it = buckets[my_hash].find(val);
  return it!= buckets[my_hash].end();
}

template<typename T>
Hash_map<T>::~Hash_map(){
  delete[] buckets;
}

template<typename T>
Hash_map<T>::iterator::iterator():current_bucket{0},buckets{nullptr}{
  typename LinkedList<T>::iterator tmp();
  current_it = tmp;
}

template<typename T>
Hash_map<T>::iterator::iterator(const typename LinkedList<T>::iterator& it ,std::size_t current_bucket,const LinkedList<T>* buckets): current_it{it},current_bucket{current_bucket},buckets{buckets}{};

template<typename T>
Hash_map<T>::iterator::iterator(const Hash_map<T>::iterator& a):current_it{a.current_it},current_bucket{a.current_bucket}, buckets{a.buckets}{};

template<typename T>
typename Hash_map<T>::iterator& Hash_map<T>::iterator::operator=(const Hash_map<T>::iterator& a){
  current_it= a.current_it;
  current_bucket = a.current_bucket;
  buckets = a.buckets;
  return *this;
}

template<typename T>
typename Hash_map<T>::iterator& Hash_map<T>::iterator::operator++(){
  typename LinkedList<T>::iterator tmp_it = this->current_it;
  ++tmp_it;
  if(tmp_it==buckets[current_bucket].end()){
    //Find next bucket and last bucket
    std::size_t i{current_bucket+1};
    std::size_t next_non_empty_bucket{current_bucket};
    for(;i<number_of_buckets &&
	  buckets[i].Count()==0;
	++i);
    if(i!=number_of_buckets)next_non_empty_bucket = i;  
    std::size_t last_bucket{next_non_empty_bucket};
    for(std::size_t i{next_non_empty_bucket+1};i<number_of_buckets;++i){
      if(buckets[i].Count()!=0)last_bucket=i;
    }
    if(current_bucket==last_bucket)current_it = buckets[last_bucket].end();
    else{
      current_bucket = next_non_empty_bucket;
      current_it = buckets[current_bucket].begin();
    }
  }
  else{
    ++current_it;
  }
  return *this;
}


template<typename T>
typename Hash_map<T>::iterator& Hash_map<T>::iterator::operator--(){
  //NOT IMPLEMENTED
  return *this;
}

template<typename T>
typename Hash_map<T>::iterator Hash_map<T>::iterator::operator++(int){
  typename Hash_map<T>::iterator tmp(*this);
  ///NOT IMPLEMENTED
  return tmp;
}


template<typename T>
typename Hash_map<T>::iterator Hash_map<T>::iterator::operator--(int){
  typename Hash_map<T>::iterator tmp(*this);
  //NOT IMPLEMENTED
  return tmp;
}
template<typename T>
bool Hash_map<T>::iterator::operator!=(const Hash_map<T>::iterator& a){
  return current_it!=a.current_it;
}

template<typename T>
bool Hash_map<T>::iterator::operator==(const Hash_map<T>::iterator& a){
  return current_it==a.current_it;
}

template<typename T>
T& Hash_map<T>::iterator::operator*(){
  return *current_it;
}

template<typename T>
bool Hash_map<T>::del(const Hash_map<T>::iterator& a){
  if(buckets[a.current_bucket].del(a.current_it)){
    --count;
    return true;
  }
  std::cout<<"no reaction"<<std::endl;
  return false;
}

template<typename T>
typename Hash_map<T>::iterator Hash_map<T>::begin(){
  if(count==0){
    throw std::runtime_error("No elements in the Hash_map");
  }
  std::size_t i{0};
  for(;i<number_of_buckets && buckets[i].Count()==0;++i);
  typename Hash_map<T>::iterator tmp(buckets[i].begin(),i,buckets);
  return tmp;
}

template<typename T>
typename Hash_map<T>::iterator Hash_map<T>::end(){
  if(count==0){
    throw std::runtime_error("No elements in the Hash_map");
  }
  std::size_t i{number_of_buckets-1};
  for(;i!=SIZE_MAX && buckets[i].Count()==0;--i);
  typename Hash_map<T>::iterator tmp(buckets[i].end(),i,buckets);
  return tmp;
}
//we can implement a better way of finding last buckets but you are not supposed to iterate
//Through Hash_maps it is just an implementation in case you need something like iterators

template<typename T>
std::size_t Hash_map<T>::Count(){return count;}
