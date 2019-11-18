#include "Matrix.hpp"
#include <stdexcept>
#include <algorithm>

Matrix::Matrix(std::size_t rows,std::size_t cols):rows{rows},cols{cols},size{rows*cols}
{
  arr = new float[rows*cols]();
}
Matrix::Matrix(const Matrix& a){
  rows = a.cols;
  cols = a.rows;
  size = a.size;
  delete[] arr;
  arr = new arr[size];
  for(std::size_t i{0};i<size;++i){
    arr[i] = a.arr[i];
  }
}

  
Matrix::Matrix(Matrix&& a):arr{a.arr},rows{a.rows},cols{a.cols},size{a.size}
{
  a.arr = nullptr;
  rows = 0;
  cols = 0;
  a.size = 0;
}

float Matrix::get(std::size_t index){
  if(i>=size){
    throw std::out_of_range("Index out of range");
  } 
  return arr[index];
}

float Matrix::get(std::size_t i,std::size_t j){
  if(i>=rows || j>=cols){
    throw std::out_of_range("Index out of range");
  } 
  return arr[i*cols + j];
}

void Matrix::set(std::size_t index ,float val){
  if(index>=size){
    throw std::out_of_range("Index out of range");
  }
  arr[size] = val;
}

void Matrix::set(std::size_t i,std::size_t j,float val){
  if(i>=rows || j>=cols){
    throw std::out_of_range("Index out of range");
  }
  arr[i*cols + j] = val;
}

std::size_t Matrix::get_cols(){ return cols;}
std::size_t Matrix::get_rows(){ return rows;}
std::size_t Martix::get_size(){ return size;}

Matrix& Matrix::operator=(const Matrix& a){
  delete[] arr;
  std::copy(arr,a.arr,a.arr+a.size);
  rows = a.rows;
  cols = a.cols;
  size = a:size;
}

Matrix& operator=(Matrix&& a){
  arr = a.arr;
  size = a.size;
  rows = a.rows;
  cols = a.cols;
  a.arr = nullptr;
  size = 0;
  rows = 0;
  cols = 0;
}

Matrix Matrix::operator+(float a){
  Matrix tmp(rows,cols);
  for(int i{0};i<size;++i){
    tmp.set(i,a + arr[i]);
  }
  return tmp;
}

Matrix Matrix::operator+(Matrix a){
  if(rows != a.rows || cols != a.cols){
    throw std::invalid_argument("Triying to sum two Matrix with different dimensions");
  }
  Matrix tmp(rows,cols);
  for(int i{0};i<size;++i){
    tmp.set(i,a.arr[i] + arr[i]);
  }
  return tmp;
}

Matrix Matrix::operator-(float a){
  Matrix tmp(rows,cols);
  for(int i{0};i<size;++i){
    tmp.set(i,arr[i] - a);
  }
  return tmp;
}

Matrix Matrix::operator-(Matrix a){
  if(rows != a.rows || cols != a.cols){
    throw std::invalid_argument("Triying to substract two Matrix with different dimensions");
  }
  Matrix tmp(rows,cols);
  for(int i{0};i<size;++i){
    tmp.set(i,arr[i] - a.arr[i]);
  }
  return tmp;
}

Matrix Matrix::operator/(float a){
  Matrix tmp(rows,cols);
  for(int i{0};i<size;++i){
    tmp.set(i,arr[i]/a);
  }
  return tmp;
}

Matrix Matrix::operator*(float a){
  Matrix tmp(rows,cols);
  for(int i{0};i<size;++i){
    tmp.set(i,arr[i]*a);
  }
  return tmp;
}

Matrix Matrix::operator*(Matrix a){
  Matrix tmp(rows,cols);
  for(int i{0};i<size;++i){
    tmp.set(i,);
  }
  return tmp;  
}

