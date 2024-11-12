#ifndef S21_MATRIX_OOP
#define S21_MATRIX_OOP
#include <algorithm>
#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_;
  double* matrix_;

 public:
  // Constructors & Destructor
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  // accessors & mutators :
  int GetRows();
  int GetCols();
  void SetRows(int new_rows);
  void SetCols(int new_cols);

  // Matrix operations:
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  double Determinant();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

  // Matrix operators:
  double& operator()(int row, int col);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(double num);
  S21Matrix operator+(const S21Matrix& rhs);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(double num);
  bool operator==(const S21Matrix& other);
  bool operator!=(const S21Matrix& other);

  // Other methods..
  void GetMinor(const double* matrix, int num_cols, double* minor,
                int given_row, int given_col);
};

#endif