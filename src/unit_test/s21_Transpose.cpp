#include "s21_test.h"

TEST(TestTranspose, TestTranspose_1) {
  S21Matrix matrix(3, 3);

  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(0, 2) = 3.0;
  matrix(1, 0) = 4.0;
  matrix(1, 1) = 5.0;
  matrix(1, 2) = 6.0;
  matrix(2, 0) = 7.0;
  matrix(2, 1) = 8.0;
  matrix(2, 2) = 9.0;

  S21Matrix expected(3, 3);
  expected(0, 0) = 1.0;
  expected(0, 1) = 4.0;
  expected(0, 2) = 7.0;
  expected(1, 0) = 2.0;
  expected(1, 1) = 5.0;
  expected(1, 2) = 8.0;
  expected(2, 0) = 3.0;
  expected(2, 1) = 6.0;
  expected(2, 2) = 9.0;

  for (int i = 0; i < matrix.GetRows(); i++) {
    for (int j = 0; j < matrix.GetCols(); j++) {
      EXPECT_NEAR(matrix.Transpose()(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestTranspose, TestTranspose_2) {
  const int size = 15;
  S21Matrix matrix(size, size);

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      matrix(i, j) = i * size + j + 1;
    }
  }

  S21Matrix expected(size, size);
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      expected(j, i) = matrix(i, j);
    }
  }

  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      EXPECT_NEAR(matrix.Transpose()(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestTranspose, TestTranspose_3) {
  S21Matrix matrix(2, 3);

  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(0, 2) = 3.0;
  matrix(1, 0) = 4.0;
  matrix(1, 1) = 5.0;
  matrix(1, 2) = 6.0;

  S21Matrix expected(3, 2);
  expected(0, 0) = 1.0;
  expected(0, 1) = 4.0;
  expected(1, 0) = 2.0;
  expected(1, 1) = 5.0;
  expected(2, 0) = 3.0;
  expected(2, 1) = 6.0;

  S21Matrix transposed = matrix.Transpose();

  for (int i = 0; i < transposed.GetRows(); i++) {
    for (int j = 0; j < transposed.GetCols(); j++) {
      EXPECT_NEAR(transposed(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestTranspose, TestTransposeException_1) {
  EXPECT_ANY_THROW(S21Matrix(0, 0).Transpose());
}

TEST(TestTranspose, TestTransposeException_2) {
  EXPECT_ANY_THROW(S21Matrix(4, 0).Transpose());
}

TEST(TestTranspose, TestTransposeException_3) {
  EXPECT_ANY_THROW(S21Matrix(5, -1).Transpose());
}