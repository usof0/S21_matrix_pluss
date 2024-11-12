#include "s21_test.h"

TEST(S21Matrix, GetterSetter) {
  S21Matrix matrix;

  EXPECT_EQ(3, matrix.GetRows());
  EXPECT_EQ(3, matrix.GetCols());

  matrix.SetRows(2);
  matrix.SetCols(2);

  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  S21Matrix temp(matrix);

  matrix.SetRows(5);
  matrix.SetCols(5);
  S21Matrix tempo(matrix);
  matrix.SetRows(2);
  matrix.SetCols(2);

  EXPECT_TRUE(matrix == temp);

  matrix.SetRows(5);
  matrix.SetCols(5);

  EXPECT_TRUE(tempo == matrix);

  try {
    matrix.SetRows(0);
    FAIL() << "Expected exception not thrown";
  } catch (const std::out_of_range& e) {
    EXPECT_STREQ(e.what(), "S21Matrix: rows can't be set to 0 or less");
  }

  try {
    matrix.SetCols(0);
    FAIL() << "Expected exception not thrown";
  } catch (const std::out_of_range& e) {
    EXPECT_STREQ(e.what(), "S21Matrix: cols can't be set to 0 or less");
  }
}
