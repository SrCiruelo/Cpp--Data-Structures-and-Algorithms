#include <iostream>

void insertion_sort(int* arr,std::size_t arr_size){
  int* end = arr + arr_size;
 for(int* it0{arr+1};it0 != end;++it0)
 {
  int* it1{it0};
  for(;it1 != arr && *(it1-1) > (*it1);--it1)
  {
    std::swap(*it1,*(it1-1));
  }
 }
}

void print_arr(int* arr,std::size_t arr_size){
  for(int i{0};i<arr_size;++i){
    std::cout<<arr[i]<< "  ";
  }
  std::cout<<std::endl;
}
 
int main(int argv,char** argc) {

  int arr[] = {2,32,1,1,23,32,232};
  print_arr(arr,7);
  insertion_sort(arr,7);
  print_arr(arr,7);
  return 0;
}
