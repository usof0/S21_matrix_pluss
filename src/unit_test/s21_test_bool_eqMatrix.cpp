#include "s21_test.h"

TEST(TestEqMatrix, TestEqMatrix_1) {
  S21Matrix matrix_1{2, 2};
  S21Matrix matrix_2{2, 2};
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(1, 0) = 3;
  matrix_1(1, 1) = 4;
  matrix_2(0, 0) = 1;
  matrix_2(0, 1) = 2;
  matrix_2(1, 0) = 3;
  matrix_2(1, 1) = 4;
  EXPECT_TRUE(matrix_1 == matrix_2);
}

TEST(TestEqMatrix, TestEqMatrix_2) {
  S21Matrix matrix_1{2, 2};
  S21Matrix matrix_2{2, 2};
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(1, 0) = 3;
  matrix_1(1, 1) = 5;
  matrix_2(0, 0) = 1;
  matrix_2(0, 1) = 2;
  matrix_2(1, 0) = 3;
  matrix_2(1, 1) = 4;
  EXPECT_FALSE(matrix_1 == matrix_2);
}

TEST(TestEqMatrix, TestEqMatrix_3) {
  S21Matrix matrix_1{1, 1};
  S21Matrix matrix_2{1, 1};

  matrix_1(0, 0) = -1;
  matrix_2(0, 0) = 2;
  EXPECT_FALSE(matrix_1 == matrix_2);
}

TEST(TestEqMatrix, TestEqMatrix_4) {
  S21Matrix matrix_1{2, 3};
  S21Matrix matrix_2{5, 5};
  EXPECT_FALSE(matrix_1 == matrix_2);
}

TEST(TestEqMatrix, TestEqMatrix_5) {
  EXPECT_ANY_THROW((S21Matrix{0, 0}.EqMatrix(S21Matrix{0, 0})));
}
TEST(TestEqMatrix, TestEqMatrix_6) {
  S21Matrix matrix_1{10, 10};
  S21Matrix matrix_2{3, 5};
  EXPECT_FALSE(matrix_1 == matrix_2);
}

TEST(TestEqMatrix, TestEqMatrix_7) {
  EXPECT_ANY_THROW((S21Matrix{0, 10}.EqMatrix(S21Matrix{10, 10})));
}

TEST(TestEqMatrix, TestEqMatrix_8) {
  EXPECT_ANY_THROW((S21Matrix{5, 5}.EqMatrix(S21Matrix{0, 0})));
}

TEST(TestEqMatrix, TestEqMatrix_9) {
  EXPECT_ANY_THROW((S21Matrix{-5, 5}.EqMatrix(S21Matrix{5, 5})));
}

TEST(TestEqMatrix, TestEqMatrix_10) {
  EXPECT_ANY_THROW((S21Matrix{15, 15}.EqMatrix(S21Matrix{0, -1})));
}
