#include "s21_test.h"

TEST(TestCalcComplements, TestCalcComplements_1) {
  S21Matrix matrix(3, 3);

  matrix(0, 0) = 3;
  matrix(0, 1) = 4;
  matrix(0, 2) = 5;
  matrix(1, 0) = 0;
  matrix(1, 1) = 1;
  matrix(1, 2) = 2;
  matrix(2, 0) = 1;
  matrix(2, 1) = 1;
  matrix(2, 2) = 3;

  S21Matrix expected(3, 3);
  expected(0, 0) = 1;
  expected(0, 1) = 2;
  expected(0, 2) = -1;
  expected(1, 0) = -7;
  expected(1, 1) = 4;
  expected(1, 2) = 1;
  expected(2, 0) = 3;
  expected(2, 1) = -6;
  expected(2, 2) = 3;

  for (int i = 0; i < matrix.GetRows(); i++) {
    for (int j = 0; j < matrix.GetCols(); j++) {
      EXPECT_NEAR(matrix.CalcComplements()(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestCalcComplements, TestCalcComplements_2) {
  S21Matrix matrix(3, 3);

  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 0;
  matrix(1, 1) = 4;
  matrix(1, 2) = 2;
  matrix(2, 0) = 5;
  matrix(2, 1) = 2;
  matrix(2, 2) = 1;

  S21Matrix expected(3, 3);
  expected(0, 0) = 0;
  expected(0, 1) = 10;
  expected(0, 2) = -20;
  expected(1, 0) = 4;
  expected(1, 1) = -14;
  expected(1, 2) = 8;
  expected(2, 0) = -8;
  expected(2, 1) = -2;
  expected(2, 2) = 4;

  for (int i = 0; i < matrix.GetRows(); i++) {
    for (int j = 0; j < matrix.GetCols(); j++) {
      EXPECT_NEAR(matrix.CalcComplements()(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestCalcComplements, TTestCalcComplements_1) {
  S21Matrix test_matrix(2, 3);
  EXPECT_ANY_THROW(test_matrix.Determinant());
}