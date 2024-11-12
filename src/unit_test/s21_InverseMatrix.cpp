#include "s21_test.h"

TEST(TestInverseMatrix, TestInverseMatrix_1) {
  S21Matrix matrix(3, 3);

  matrix(0, 0) = 2;
  matrix(0, 1) = 5;
  matrix(0, 2) = 7;
  matrix(1, 0) = 6;
  matrix(1, 1) = 3;
  matrix(1, 2) = 4;
  matrix(2, 0) = 5;
  matrix(2, 1) = -2;
  matrix(2, 2) = -3;

  S21Matrix expected(3, 3);
  expected(0, 0) = 1;
  expected(0, 1) = -1;
  expected(0, 2) = 1;
  expected(1, 0) = -38;
  expected(1, 1) = 41;
  expected(1, 2) = -34;
  expected(2, 0) = 27;
  expected(2, 1) = -29;
  expected(2, 2) = 24;

  for (int i = 0; i < matrix.GetRows(); i++) {
    for (int j = 0; j < matrix.GetCols(); j++) {
      EXPECT_NEAR(matrix.InverseMatrix()(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestInverseMatrix, TestInverseMatrix_2) {
  S21Matrix matrix(2, 2);

  matrix(0, 0) = 0;
  matrix(0, 1) = 2;
  matrix(1, 0) = 1;
  matrix(1, 1) = 3;

  S21Matrix expected(2, 2);
  expected(0, 0) = -1.5;
  expected(0, 1) = 1;
  expected(1, 0) = 0.5;
  expected(1, 1) = 0;

  for (int i = 0; i < matrix.GetRows(); i++) {
    for (int j = 0; j < matrix.GetCols(); j++) {
      EXPECT_NEAR(matrix.InverseMatrix()(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestInverseMatrix, TestInverseMatrixException_1) {
  S21Matrix test_matrix(2, 3);
  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
}

TEST(TestInverseMatrix, TestInverseMatrixException_2) {
  EXPECT_ANY_THROW(S21Matrix(0, 0));
}