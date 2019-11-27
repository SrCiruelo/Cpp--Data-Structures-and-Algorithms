#include <iostream>

class Matrix{
  std::size_t rows;
  std::size_t cols;
  std::size_t size;
  float* arr;
  float det_recursive(float,std::size_t);
public:
  Matrix() = delete;
  Matrix(std::size_t,std::size_t);
  Matrix(const Matrix&);
  Matrix(Matrix&&);
  float get(std::size_t);
  float get(std::size_t,std::size_t);
  void set(std::size_t,float);
  void set(std::size_t,std::size_t,float);
  std::size_t get_cols();
  std::size_t get_rows();
  std::size_t get_size();
  Matrix& operator=(const Matrix&);
  Matrix& operator=(Matrix&&);
  Matrix operator+(float);
  Matrix operator+(const Matrix&);
  Matrix operator-(float);
  Matrix operator-(const Matrix&);
  Matrix operator/(float);
  Matrix operator*(float);
  Matrix operator*(const Matrix&);
  bool operator==(const Matrix&);
  Matrix transpose();
  float Det();
  //Matrix Inverse();
  friend std::ostream& operator<<(std::ostream& out,const Matrix& o);
  ~Matrix();
};
//Añadir += -= *= - 
/*Matrix operator+(float,Matrix);
Matrix operator-(float,Matrix);
Matrix operator*(float,Matrix);
Matrix operator/(float,Matrix);*/

