#include <iostream>
void print_arr(int* arr,std::size_t arr_size){
  for(int i{0};i<arr_size;++i){
    std::cout<<arr[i]<< "  ";
  }
  std::cout<<std::endl;
}
void count_sort(int* arr,std::size_t arr_size){
  if(arr_size == 0)return;
  int* end = arr + arr_size;
  //find the largest element
  int smallest = sizeof(int);
  int largest = 0;
  for(int* it{arr};it != end; ++it){//O(n)
    if((*it)>largest){
      largest = (*it);
    }
    else if((*it)<smallest){
      smallest = (*it);
    }
  }
  std::size_t count_arr_size = largest - smallest + 1;
  if(count_arr_size == 0)return;
  int* count_arr = new int[count_arr_size]();
  for(int* it{arr};it != end; ++it){//O(n)
    ++count_arr[(*it)-smallest];
  }
  int* count_arr_end = count_arr + count_arr_size;
  for(int* it{count_arr+1};it != count_arr_end; ++it){//O(n)
    *it += *(it-1);
  }
  int* tmp = new int[arr_size];
  for(int* it{arr};it != end; ++it){//O(n)
    tmp[count_arr[*it - smallest]-1] = *it;
    --count_arr[*it - smallest];
  }
  print_arr(tmp,arr_size);
  delete[] count_arr;
  delete[] tmp;
}

 
int main(int argv,char** argc) {

  int arr[] = {2,32,1,1,23,32,232};
  print_arr(arr,7);
  count_sort(arr,7);
  return 0;
}
