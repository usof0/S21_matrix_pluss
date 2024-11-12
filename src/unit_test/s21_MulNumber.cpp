#include "s21_test.h"

TEST(TestMulNumber, TestMulNumber_1) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  EXPECT_EQ(matrix.GetRows(), 2);
  EXPECT_EQ(matrix.GetCols(), 2);

  double number = 2.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = 2.0;
  expected(0, 1) = 4.0;
  expected(1, 0) = 6.0;
  expected(1, 1) = 8.0;

  matrix.MulNumber(number);

  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      EXPECT_NEAR(matrix(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestMulNumber, TestMulNumber_2) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 15.0;
  matrix(0, 1) = 2.3;
  matrix(1, 0) = -3.4;
  matrix(1, 1) = 24.0;

  EXPECT_EQ(matrix.GetRows(), 2);
  EXPECT_EQ(matrix.GetCols(), 2);

  double number = -2.5;

  S21Matrix expected(2, 2);
  expected(0, 0) = -37.5;
  expected(0, 1) = -5.75;
  expected(1, 0) = 8.5;
  expected(1, 1) = -60.0;

  matrix.MulNumber(number);

  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      EXPECT_NEAR(matrix(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestMulNumber, TestMulNumber_3) {
  const int size = 50;
  S21Matrix matrix(size, size);

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      matrix(i, j) = i * size + j + 1;
    }
  }

  double number = 2.0;
  S21Matrix result = matrix * number;

  matrix.MulNumber(number);

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      EXPECT_NEAR(result(i, j), matrix(i, j), 1e-9);
    }
  }
}

TEST(TestMulNumber, TestMulNumber_4) {
  const int size = 90;
  const int size_1 = 95;
  S21Matrix matrix(size, size_1);

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size_1; ++j) {
      matrix(i, j) = i * size + j + 1;
    }
  }

  double number = 5.1;
  S21Matrix result = matrix * number;

  matrix.MulNumber(number);

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size_1; ++j) {
      EXPECT_NEAR(result(i, j), matrix(i, j), 1e-9);
    }
  }
}

TEST(TestMulNumber, TestMulNumber_5) {
  const int size = 13;
  const int size_1 = 15;
  S21Matrix matrix(size, size_1);

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size_1; ++j) {
      matrix(i, j) = i * size + j + 1;
    }
  }

  double number = -24.0009;
  S21Matrix result = matrix * number;

  matrix.MulNumber(number);

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size_1; ++j) {
      EXPECT_NEAR(result(i, j), matrix(i, j), 1e-9);
    }
  }
}

TEST(TestMulNumber, TestMulOperNumber_1) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  EXPECT_EQ(matrix.GetRows(), 2);
  EXPECT_EQ(matrix.GetCols(), 2);

  double number = 2.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = 2.0;
  expected(0, 1) = 4.0;
  expected(1, 0) = 6.0;
  expected(1, 1) = 8.0;

  matrix.MulNumber(number);

  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      EXPECT_NEAR(matrix(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestMulNumber, TestMulOperNumber_2) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 15.0;
  matrix(0, 1) = 2.3;
  matrix(1, 0) = -3.4;
  matrix(1, 1) = 24.0;

  EXPECT_EQ(matrix.GetRows(), 2);
  EXPECT_EQ(matrix.GetCols(), 2);

  double number = -2.5;

  S21Matrix expected(2, 2);
  expected(0, 0) = -37.5;
  expected(0, 1) = -5.75;
  expected(1, 0) = 8.5;
  expected(1, 1) = -60.0;

  matrix.MulNumber(number);

  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      EXPECT_NEAR(matrix(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestMulNumber, TestMulOperNumber_3) {
  const int size = 50;
  S21Matrix matrix(size, size);

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      matrix(i, j) = i * size + j + 1;
    }
  }

  double number = 2.0;
  S21Matrix result = matrix * number;

  matrix.MulNumber(number);

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      EXPECT_NEAR(result(i, j), matrix(i, j), 1e-9);
    }
  }
}

TEST(TestMulNumber, TestMulOperNumber_4) {
  const int size = 90;
  const int size_1 = 95;
  S21Matrix matrix(size, size_1);

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size_1; ++j) {
      matrix(i, j) = i * size + j + 1;
    }
  }

  double number = 5.1;
  S21Matrix result = matrix * number;

  matrix.MulNumber(number);

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size_1; ++j) {
      EXPECT_NEAR(result(i, j), matrix(i, j), 1e-9);
    }
  }
}

TEST(TestMulNumber, TestMulOperNumber_5) {
  const int size = 13;
  const int size_1 = 15;
  S21Matrix matrix(size, size_1);

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size_1; ++j) {
      matrix(i, j) = i * size + j + 1;
    }
  }

  double number = -24.0009;
  S21Matrix result = matrix * number;

  matrix.MulNumber(number);

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size_1; ++j) {
      EXPECT_NEAR(result(i, j), matrix(i, j), 1e-9);
    }
  }
}

TEST(TestMulNumber, TestMulOperException_1) {
  double number = 9;
  EXPECT_ANY_THROW(S21Matrix(0, 0).MulNumber(number));
}

TEST(TestMulNumber, TestMulNumberOperPereg_1) {
  const int size = 2;
  S21Matrix matrix(size, size);

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      matrix(i, j) = i * size + j + 1;
    }
  }

  double number = 2.0;

  matrix *= number;

  EXPECT_NEAR(matrix(0, 0), 2.0, 1e-9);
  EXPECT_NEAR(matrix(0, 1), 4.0, 1e-9);
  EXPECT_NEAR(matrix(1, 0), 6.0, 1e-9);
  EXPECT_NEAR(matrix(1, 1), 8.0, 1e-9);
}