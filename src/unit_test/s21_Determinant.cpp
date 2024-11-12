#include "s21_test.h"

TEST(TestDeteminant, TestDeterminant_1) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 0;
  matrix(0, 1) = 1;
  matrix(0, 2) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;
  matrix(1, 2) = 5;
  matrix(2, 0) = 1;
  matrix(2, 1) = 1;
  matrix(2, 2) = 3;

  double expected = -6;
  double result = matrix.Determinant();

  EXPECT_DOUBLE_EQ(result, expected);
}
TEST(TestDeteminant, TestDeterminant_2) {
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

  double expected = 6;
  double result = matrix.Determinant();

  EXPECT_DOUBLE_EQ(result, expected);
}

TEST(TestDeteminant, Determinant_3) {
  S21Matrix matrix(3, 3);

  double result = 0;
  double x = 5.56780;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix(i, j) = x;
      x += 1.0;
    }
  }
  result = matrix.Determinant();
  EXPECT_NEAR(0, result, 1e-6);
}

TEST(TestDeterminant, TestDeterminantException_1) {
  S21Matrix matrix(2, 3);
  EXPECT_ANY_THROW(matrix.Determinant());
}
