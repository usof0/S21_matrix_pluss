#include "./s21_matrix_oop.h"

// constructors:

S21Matrix::S21Matrix() : rows_(3), cols_(3) {
  matrix_ = new double[rows_ * cols_]();
};

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ <= 0 || cols_ <= 0) {
    throw "Invalid matrix!";
  }
  matrix_ = new double[rows_ * cols_]();
};

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  if (rows_ <= 0 || cols_ <= 0) {
    throw "Invalid matrix!";
  }
  matrix_ = new double[rows_ * cols_]();
  if (matrix_ && other.matrix_) {
    std::copy_n(&other.matrix_[0], rows_ * cols_, &matrix_[0]);
  }
};

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_) {
  if (rows_ <= 0 || cols_ <= 0) {
    throw "Invalid matrix!";
  }
  matrix_ = new double[rows_ * cols_]();
  if (matrix_ && other.matrix_) {
    std::copy_n(&other.matrix_[0], rows_ * cols_, &matrix_[0]);
  }
  if (other.matrix_) other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
};

S21Matrix::~S21Matrix() {
  if (matrix_) {
    delete[] matrix_;
    matrix_ = nullptr;
  }
};

// mutators:

int S21Matrix::GetRows() { return this->rows_; }

int S21Matrix::GetCols() { return this->cols_; }

// accessors:

void S21Matrix::SetRows(int new_rows) {
  if (new_rows < 1) {
    throw std::out_of_range("S21Matrix: rows can't be set to 0 or less");
  }
  if (new_rows == rows_) {
    return;
  }
  S21Matrix new_matrix(new_rows, cols_);
  std::copy_n(matrix_, std::min(new_rows, rows_) * cols_, new_matrix.matrix_);
  rows_ = new_rows;
  std::swap(matrix_, new_matrix.matrix_);
}

void S21Matrix::SetCols(int new_cols) {
  if (new_cols < 1) {
    throw std::out_of_range("S21Matrix: cols can't be set to 0 or less");
  }
  if (new_cols == cols_) {
    return;
  }

  S21Matrix new_matrix(rows_, new_cols);

  int cols = std::min(new_cols, cols_);

  for (int i = 0; i != rows_; ++i) {
    for (int j = 0; j != cols; ++j) {
      new_matrix.matrix_[i * new_cols + j] = matrix_[i * cols_ + j];
    }
  }

  cols_ = new_cols;
  std::swap(matrix_, new_matrix.matrix_);
}

// Matrix operations:

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }

  long size = static_cast<long>(rows_) * cols_;

  for (long i = 0; i < size; i++) {
    if (matrix_[i] != other.matrix_[i]) {
      return false;
    }
  }

  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("S21Matrix: matrices of different dimensions");
  }

  long size = static_cast<long>(rows_) * cols_;

  for (long i = 0; i < size; i++) {
    matrix_[i] += other.matrix_[i];
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("S21Matrix: matrices of different dimensions");
  }

  long size = static_cast<long>(rows_) * cols_;

  for (long i = 0; i < size; i++) {
    matrix_[i] -= other.matrix_[i];
  }
}

void S21Matrix::MulNumber(const double num) {
  long size = static_cast<long>(rows_) * cols_;

  for (long i = 0; i < size; i++) {
    matrix_[i] *= num;
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument(
        "S21Matrix: can't multiply matrices with such dimensions");
  }

  double* result = new double[static_cast<long>(rows_) * other.cols_]{};

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        result[i * other.cols_ + j] +=
            matrix_[i * cols_ + k] * other.matrix_[k * other.cols_ + j];
      }
    }
  }

  cols_ = other.cols_;
  matrix_ = result;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result(j, i) = matrix_[i * cols_ + j];
    }
  }

  return result;
}

void S21Matrix::GetMinor(const double* matrix, int num_cols, double* minor,
                         int given_row, int given_col) {
  int i = 0;

  for (int row = 0; row < num_cols; row++) {
    if (row == given_row) continue;
    for (int col = 0; col < num_cols; col++) {
      if (col == given_col) continue;
      minor[i] = matrix[row * num_cols + col];
      i++;
    }
  }
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::logic_error("S21Matrix: not a square matrix");
  }

  if (rows_ == 1) return matrix_[0];
  if (rows_ == 2) return matrix_[0] * matrix_[3] - matrix_[1] * matrix_[2];

  double determinant = 0;
  S21Matrix minor(rows_ - 1, cols_ - 1);

  int sign = 1;
  for (int i = 0; i < rows_; i++) {
    GetMinor(matrix_, rows_, minor.matrix_, 0, i);
    determinant += sign * matrix_[i] * minor.Determinant();
    sign = -sign;
  }

  return determinant;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::logic_error("S21Matrix: not a square matrix");
  }

  S21Matrix complements(rows_, cols_);

  if (rows_ == 1) {
    complements.matrix_[0] = 1;
    return complements;
  }

  S21Matrix minor(rows_ - 1, cols_ - 1);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      GetMinor(matrix_, rows_, minor.matrix_, i, j);
      complements(i, j) = ((i + j) % 2 == 0 ? 1 : -1) * minor.Determinant();
    }
  }

  return complements;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_) {
    throw std::logic_error("S21Matrix: not a square matrix");
  }

  double det = this->Determinant();
  if (det == 0) {
    throw std::logic_error(
        "S21Matrix: matrix is singular (det = 0), no inverse.");
  }

  S21Matrix complements = this->CalcComplements();

  S21Matrix complements_T = complements.Transpose();

  S21Matrix inverse(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      inverse(i, j) = complements_T(i, j) / det;
    }
  }

  return inverse;
}

// Matrix operators:

double& S21Matrix::operator()(int row, int col) {
  if (row < 0 || col < 0 || row > rows_ - 1 || col > cols_ - 1) {
    throw std::out_of_range("S21Matrix: matrix indices out of range");
  }

  return matrix_[row * cols_ + col];
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(double num) {
  this->MulNumber(num);
  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix sum = *this;
  sum += other;
  return sum;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix sum = *this;
  sum -= other;
  return sum;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix sum = *this;
  sum *= other;
  return sum;
}

S21Matrix S21Matrix::operator*(double num) {
  S21Matrix sum = *this;
  sum *= num;
  return sum;
}

bool S21Matrix::operator==(const S21Matrix& other) {
  return this->EqMatrix(other);
}

bool S21Matrix::operator!=(const S21Matrix& other) {
  return !this->EqMatrix(other);
}
