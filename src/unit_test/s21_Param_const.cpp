#include "s21_test.h"

TEST(TestConstructors, TestParamConst_1) {
  S21Matrix matrix_check(5, 4);
  ASSERT_EQ(matrix_check.GetRows(), 5);
  ASSERT_EQ(matrix_check.GetCols(), 4);

  for (int i = 0; i < matrix_check.GetRows(); ++i) {
    for (int j = 0; j < matrix_check.GetCols(); ++j) {
      EXPECT_DOUBLE_EQ(matrix_check(i, j), 0.0);
    }
  }
}

TEST(TestConstructors, TestParamConst_2) {
  S21Matrix matrix_check(7, 7);
  ASSERT_EQ(matrix_check.GetRows(), 7);
  ASSERT_EQ(matrix_check.GetCols(), 7);

  for (int i = 0; i < matrix_check.GetRows(); ++i) {
    for (int j = 0; j < matrix_check.GetCols(); ++j) {
      EXPECT_DOUBLE_EQ(matrix_check(i, j), 0.0);
    }
  }
}

TEST(TestConstructors, TestParamConst_3) {
  S21Matrix matrix_check(2, 1);
  ASSERT_EQ(matrix_check.GetRows(), 2);
  ASSERT_EQ(matrix_check.GetCols(), 1);

  for (int i = 0; i < matrix_check.GetRows(); ++i) {
    for (int j = 0; j < matrix_check.GetCols(); ++j) {
      EXPECT_DOUBLE_EQ(matrix_check(i, j), 0.0);
    }
  }
}

TEST(TestConstructors, TestParamConst_4) { EXPECT_ANY_THROW(S21Matrix(0, -5)); }

TEST(TestConstructors, TestParamConst_5) { EXPECT_ANY_THROW(S21Matrix(0, 0)); }

TEST(TestConstructors, TestParamConst_6) {
  EXPECT_ANY_THROW(S21Matrix(10, -1));
}