#include "s21_test.h"

TEST(TestConstructors, TestCopy_1) {
  S21Matrix original(2, 4);

  for (int i = 0; i < original.GetRows(); ++i) {
    for (int j = 0; j < original.GetCols(); ++j) {
      original(i, j) = static_cast<double>(i + j);
    }
  }

  S21Matrix copy(original);

  ASSERT_EQ(copy.GetRows(), original.GetRows());
  ASSERT_EQ(copy.GetCols(), original.GetCols());

  for (int i = 0; i < original.GetRows(); ++i) {
    for (int j = 0; j < original.GetCols(); ++j) {
      EXPECT_DOUBLE_EQ(copy(i, j), original(i, j));
    }
  }
}

TEST(TestConstructors, TestCopy_2) {
  S21Matrix matrix1(2, 4);

  for (int i = 0; i < matrix1.GetRows(); ++i) {
    for (int j = 0; j < matrix1.GetCols(); ++j) {
      matrix1(i, j) = static_cast<double>(i + j);
    }
  }

  S21Matrix copy_matrix(matrix1);

  ASSERT_EQ(matrix1.GetRows(), 2);
  ASSERT_EQ(matrix1.GetCols(), 4);
  ASSERT_EQ(copy_matrix.GetRows(), 2);
  ASSERT_EQ(copy_matrix.GetCols(), 4);

  for (int i = 0; i < copy_matrix.GetRows(); ++i) {
    for (int j = 0; j < copy_matrix.GetCols(); ++j) {
      EXPECT_DOUBLE_EQ(copy_matrix(i, j), matrix1(i, j));
    }
  }
}

TEST(TestConstructors, TestCopy_3) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 0.005;
  matrix(0, 1) = 100.8999;
  matrix(1, 0) = 50.775;
  matrix(1, 1) = 46.789;

  S21Matrix matrix_2{matrix};

  EXPECT_EQ(2, matrix_2.GetRows());
  EXPECT_EQ(2, matrix_2.GetCols());
  EXPECT_TRUE(matrix == matrix_2);

  S21Matrix matrix_3 = matrix;

  EXPECT_TRUE(matrix_3 == matrix_2);
}