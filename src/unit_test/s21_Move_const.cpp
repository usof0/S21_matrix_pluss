#include "s21_test.h"

TEST(TestConstructors, TestMove_1) {
  S21Matrix matrix1(2, 4);
  S21Matrix move_matrix(std::move(matrix1));

  ASSERT_EQ(matrix1.GetRows(), 0);
  ASSERT_EQ(matrix1.GetCols(), 0);
  ASSERT_EQ(move_matrix.GetRows(), 2);
  ASSERT_EQ(move_matrix.GetCols(), 4);
}

TEST(TestConstructors, TestMove_2) {
  S21Matrix matrix1(7, 7);
  S21Matrix move_matrix(std::move(matrix1));

  ASSERT_EQ(matrix1.GetRows(), 0);
  ASSERT_EQ(matrix1.GetCols(), 0);
  ASSERT_EQ(move_matrix.GetRows(), 7);
  ASSERT_EQ(move_matrix.GetCols(), 7);
}