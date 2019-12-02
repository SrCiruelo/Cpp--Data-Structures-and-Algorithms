#include "Matrix.hpp"
#include <stdexcept>
#include <algorithm>


Matrix::Matrix(std::size_t rows,std::size_t cols):rows{rows},cols{cols},size{rows*cols}
{
  arr = new float[rows*cols]();
}
Matrix::Matrix(const Matrix& a){
  rows = a.rows;
  cols = a.cols;
  size = a.size;
  delete[] arr;
  arr = new float[size];
  for(std::size_t i{0};i<size;++i){
    arr[i] = a.arr[i];
  }
}

  
Matrix::Matrix(Matrix&& a):arr{a.arr},rows{a.rows},cols{a.cols},size{a.size}
{
  a.arr = nullptr;
  a.rows = 0;
  a.cols = 0;
  a.size = 0;
}

float Matrix::get(std::size_t index){
  if(index>=size){
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
  arr[index] = val;
}

void Matrix::set(std::size_t i,std::size_t j,float val){
  if(i>=rows || j>=cols){
    throw std::out_of_range("Index out of range");
  }
  arr[i*cols + j] = val;
}

std::size_t Matrix::get_cols(){ return cols;}
std::size_t Matrix::get_rows(){ return rows;}
std::size_t Matrix::get_size(){ return size;}

Matrix& Matrix::operator=(const Matrix& a){
  delete[] arr;
  std::copy(arr,a.arr,a.arr+a.size);
  rows = a.rows;
  cols = a.cols;
  size = a.size;
  return *this;
}

Matrix& Matrix::operator=(Matrix&& a){
  arr = a.arr;
  size = a.size;
  rows = a.rows;
  cols = a.cols;
  a.arr = nullptr;
  a.size = 0;
  a.rows = 0;
  a.cols = 0;
  return *this;
}

Matrix Matrix::operator+(float a){
  Matrix tmp(rows,cols);
  for(std::size_t i{0};i<size;++i){
    tmp.set(i,a + arr[i]);
  }
  return tmp;
}

Matrix Matrix::operator+(const Matrix& a){
  if(rows != a.rows || cols != a.cols){
    throw std::invalid_argument("Triying to sum two Matrix with different dimensions");
  }
  Matrix tmp(rows,cols);
  for(std::size_t i{0};i<size;++i){
    tmp.set(i,a.arr[i] + arr[i]);
  }
  return tmp;
}

Matrix Matrix::operator-(float a){
  Matrix tmp(rows,cols);
  for(std::size_t i{0};i<size;++i){
    tmp.set(i,arr[i] - a);
  }
  return tmp;
}

Matrix Matrix::operator-(const Matrix& a){
  if(rows != a.rows || cols != a.cols){
    throw std::invalid_argument("Triying to substract two Matrix with different dimensions");
  }
  Matrix tmp(rows,cols);
  for(std::size_t i{0};i<size;++i){
    tmp.set(i,arr[i] - a.arr[i]);
  }
  return tmp;
}

Matrix Matrix::operator/(float a){
  Matrix tmp(rows,cols);
  for(std::size_t i{0};i<size;++i){
    tmp.set(i,arr[i]/a);
  }
  return tmp;
}

Matrix Matrix::operator*(float a){
  Matrix tmp(rows,cols);
  for(std::size_t i{0};i<size;++i){
    tmp.set(i,arr[i]*a);
  }
  return tmp;
}

Matrix Matrix::operator*(const Matrix& a){
  if(cols != a.rows){
    throw std::invalid_argument("Colums of left operand is not the same as the right operand rows");
  }
  Matrix tmp(rows,a.cols);
  for(std::size_t x{0};x<tmp.size;++x){
    tmp.arr[x] = 0;
    std::size_t i = x%rows;
    std::size_t j = x/a.cols;
    for(std::size_t y{0};y<cols;++y){
      tmp.arr[x] += arr[j*a.rows+y]*a.arr[i + y*a.cols];
    }
  }
  return tmp;  
}

bool  Matrix::operator==(const Matrix& a){
  if(cols != a.cols || rows != a.rows){
    return false;
  }
  std::size_t i{0};
  for(;i<size && arr[i] == a.arr[i];++i);
  return i==size;
}
float Matrix::det_recursive(std::size_t val_index
			    ,std::size_t actual_dimension){
  std::size_t current_index = rows-actual_dimension;
  current_index += current_index*cols;
  if(actual_dimension==2){
    return arr[current_index]*arr[current_index + cols  + 1]
      - arr[current_index+1]*arr[current_index+cols];
  }
  float result{0};
  for(std::size_t i{0};i<actual_dimension;++i){
    result += (i,actual_dimension-1);
  }
  return result;
}
float Matrix::Det(){
  //Here a function that reduce our array should be very useful
  if(cols!=rows){
    throw std::runtime_error("Trying to calculate Determinant from a non square matrix");
  }
  
  return ;
}
//Wasn't neccessary doing this function a friend
std::ostream& operator<<(std::ostream& out,const Matrix& o){
  char top_left_corner = 218;
  char top_right_corner = 191;
  char bottom_left_corner = 192;
  char bottom_right_corner = 217;
  char vertical_bar = 124;
  out << top_left_corner << " ";
  for(std::size_t i{0};i<o.cols;++i){
    out << o.arr[i] << " ";
  }
  out << top_right_corner;
  out<<"\n";
  for(std::size_t i{1};i<o.rows-1;++i){
    out<<vertical_bar<<" ";
    for(std::size_t j{0};j<o.cols;++j){
      out << o.arr[i*o.cols + j] << " ";
    }
    out<<vertical_bar<<"\n";
  }
  out <<bottom_left_corner<< " ";
  for(std::size_t i{0};i<o.cols;++i){
    out << o.arr[i + (o.rows-1)*o.cols] << " ";
  }
  out << bottom_right_corner;
  return out;
}


Matrix::~Matrix(){
  delete[] arr;
}

Matrix Matrix::transpose(){
  Matrix tmp{cols,rows};
  for(std::size_t x{0};x<size;++x){
    std::size_t i = x%rows;
    std::size_t j = x/rows;
    tmp.arr[x] = arr[i*cols + j];
  }
  return tmp;
}

