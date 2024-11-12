#include "s21_test.h"

TEST(TestConstructors, TestBase_1) {
  S21Matrix matrix(10, 10);

  ASSERT_EQ(matrix.GetRows(), 10);
  ASSERT_EQ(matrix.GetCols(), 10);
}

TEST(TestConstructors, TestBase_2) {
  S21Matrix matrix(150, 150);

  ASSERT_EQ(matrix.GetRows(), 150);
  ASSERT_EQ(matrix.GetCols(), 150);
}

TEST(TestConstructors, TestBase_3) {
  S21Matrix matrix(2, 2);

  ASSERT_EQ(matrix.GetRows(), 2);
  ASSERT_EQ(matrix.GetCols(), 2);
}

TEST(TestConstructors, TestBase_4) {
  S21Matrix matrix(3, 4);

  ASSERT_EQ(matrix.GetRows(), 3);
  ASSERT_EQ(matrix.GetCols(), 4);
}

TEST(TestConstructors, TestBase_5) {
  S21Matrix matrix;

  ASSERT_EQ(matrix.GetRows(), 3);
  ASSERT_EQ(matrix.GetCols(), 3);
}

TEST(TestConstructors, TestBase_6) { EXPECT_ANY_THROW(S21Matrix(0, -3)); }

TEST(TestConstructors, TestBase_7) { EXPECT_ANY_THROW(S21Matrix(0, 0)); }

TEST(TestConstructors, TestBase_8) { EXPECT_ANY_THROW(S21Matrix(5, 0)); }

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}