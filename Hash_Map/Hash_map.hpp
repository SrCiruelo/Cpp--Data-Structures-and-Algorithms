#include "../LinkedList/XOR_LinkedList"

template <std::size_t bucket_size,typename T>
class Hash_map{
  XOR_LinkedList<T>* buckets;

public:
  Hash_map();
  Hash_map(const Hash_map&);
  Hash_map(Hash_map&&);
  Hash_map& operator=(const Hash_map&);
  Hash_map& operator=(Hash_map&&);
  void add(T val);
  void delete(T val);
  T& search(T val);
  
};


template<std::size_t bucket_size,typename T>
Hash_map<T>::Hash_map(){
  buckets = new XOR_LinkedList<T*>[bucket_size]();
}

template<std::size_t bucket_size,typename T>
Hash_map<T>::Hash_map(const Hash_map& a){
  buckets = new XOR_LinkedList<T*>[bucket_size]();
  for(int i=0;i<bucket_size;++i){
    buckets[i] = a.buckets[i];
  }
}

template<std::size_t bucket_size,typename T>
Hash_map<T>::Hash_map(Hash_map&& a){
  buckets = a.buckets;
  a.buckets = nullptr;
}
