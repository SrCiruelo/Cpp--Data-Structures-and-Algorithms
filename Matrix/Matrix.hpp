class Matrix{
  std::size_t rows;
  std::size_t cols;
  std::size_t size;
  float* arr;
public:
  Matrix() = delete;
  Matrix(std::size_t,std::size_t);
  Matrix(const Matrix&);
  Matrix(Matrix&&);
  float get(std::size_t);
  float get(std::size_t,std::size_t);
  void  set(std::size_t);
  void set(std::size_t,std::size_t);
  std::size_t get_cols();
  std::size_t get_rows();
  std::size_t get_size();
  Matrix& operator=(const Matrix&);
  Matrix& operator=(Matrix&&);
  Matrix operator+(float);
  Matrix operator+(Matrix);
  Matrix operator-(float);
  Matrix operator-(Matrix);
  Matrix operator/(float);
  Matrix operator*(float);
  Matrix operator*(Matrix);
  Matrix transpose();
  float Det();
  Matrix Inverse();
  ~Matrix();
};
//Añadir += -= *=
/*Matrix operator+(float,Matrix);
Matrix operator-(float,Matrix);
Matrix operator*(float,Matrix);
Matrix operator/(float,Matrix);*/
