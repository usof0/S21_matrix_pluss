#include "s21_test.h"

TEST(TestMul, TestMulExceptions_1) {
  S21Matrix matrix_1{3, 3};
  S21Matrix matrix_2{2, 2};

  S21Matrix matrix_1_now = matrix_1;
  S21Matrix matrix_2_now = matrix_2;

  EXPECT_ANY_THROW(matrix_1.MulMatrix(matrix_2));
  EXPECT_ANY_THROW(matrix_2.MulMatrix(matrix_1));
  EXPECT_TRUE(matrix_1 == matrix_1_now);
  EXPECT_TRUE(matrix_2 == matrix_2_now);
}

TEST(TestMul, TestMulExceptions_2) {
  EXPECT_ANY_THROW((S21Matrix{0, 5}.MulMatrix(S21Matrix{5, 5})));
}

TEST(TestMul, TestMulExceptions_3) {
  EXPECT_ANY_THROW((S21Matrix{2, 5}.MulMatrix(S21Matrix{0, 10})));
}

TEST(TestMul, TestMulExceptions_4) {
  EXPECT_ANY_THROW((S21Matrix{0, 0}.MulMatrix(S21Matrix{0, 0})));
}

TEST(TestMul, TestMulExceptions_5) {
  EXPECT_ANY_THROW((S21Matrix{-6, 6}.MulMatrix(S21Matrix{6, 6})));
}

TEST(TestMul, TestMul_1) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);

  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  matrix_2(0, 0) = 1.0;
  matrix_2(0, 1) = 4.0;
  matrix_2(1, 0) = 2.0;
  matrix_2(1, 1) = 5.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = 5.0;
  expected(0, 1) = 14.0;
  expected(1, 0) = 11.0;
  expected(1, 1) = 32.0;

  S21Matrix result = matrix_1 * matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-6);
    }
  }
}

TEST(TestMul, TestMul_2) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);

  matrix_1(0, 0) = 1.2;
  matrix_1(0, 1) = 4.0;
  matrix_1(0, 2) = 55.0;
  matrix_1(1, 0) = 2.0;
  matrix_1(1, 1) = 3.1;
  matrix_1(1, 2) = 2.0;
  matrix_1(2, 0) = 1.0;
  matrix_1(2, 1) = 19.0;
  matrix_1(2, 2) = 0.0;

  matrix_2(0, 0) = 6.0;
  matrix_2(0, 1) = 8.0;
  matrix_2(0, 2) = 13.0;
  matrix_2(1, 0) = 86.2;
  matrix_2(1, 1) = 15.0;
  matrix_2(1, 2) = 2.0;
  matrix_2(2, 0) = 7.0;
  matrix_2(2, 1) = 1.5;
  matrix_2(2, 2) = 4.0;

  S21Matrix expected(3, 3);
  expected(0, 0) = 737.0;
  expected(0, 1) = 152.1;
  expected(0, 2) = 243.6;
  expected(1, 0) = 293.22;
  expected(1, 1) = 65.5;
  expected(1, 2) = 40.2;
  expected(2, 0) = 1643.8;
  expected(2, 1) = 293.0;
  expected(2, 2) = 51.0;

  S21Matrix result = matrix_1 * matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestMul, TestMul_3) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);

  matrix_1(0, 0) = -50.0;
  matrix_1(0, 1) = 24.0;
  matrix_1(1, 0) = 2.0;
  matrix_1(1, 1) = 3.1;

  matrix_2(0, 0) = 67.0;
  matrix_2(0, 1) = 8.0;
  matrix_2(1, 0) = 86.2;
  matrix_2(1, 1) = 0.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = -1281.2;
  expected(0, 1) = -400.0;
  expected(1, 0) = 401.22;
  expected(1, 1) = 16.0;

  S21Matrix result = matrix_1 * matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestMul, TestMulOperException_1) {
  S21Matrix matrix_1{5, 3};
  S21Matrix matrix_2{3, 3};

  S21Matrix matrix_1_now = matrix_1;
  S21Matrix matrix_2_now = matrix_2;

  EXPECT_ANY_THROW(matrix_1 + matrix_2);
  EXPECT_ANY_THROW(matrix_2 + matrix_1);
  EXPECT_TRUE(matrix_1 == matrix_1_now);
  EXPECT_TRUE(matrix_2 == matrix_2_now);
}

TEST(TestMul, TestMulOperException_2) {
  S21Matrix matrix_1{5, 3};
  S21Matrix matrix_2{3, 3};

  S21Matrix matrix_1_now = matrix_1;
  S21Matrix matrix_2_now = matrix_2;

  EXPECT_ANY_THROW(matrix_1 + matrix_2);
  EXPECT_ANY_THROW(matrix_2 + matrix_1);
  EXPECT_TRUE(matrix_1 == matrix_1_now);
  EXPECT_TRUE(matrix_2 == matrix_2_now);
}

TEST(TestMul, TestMulOperException_3) {
  S21Matrix matrix_1{7, 3};
  S21Matrix matrix_2{1, 3};

  S21Matrix matrix_1_now = matrix_1;
  S21Matrix matrix_2_now = matrix_2;

  EXPECT_ANY_THROW(matrix_1 + matrix_2);
  EXPECT_ANY_THROW(matrix_2 + matrix_1);
  EXPECT_TRUE(matrix_1 == matrix_1_now);
  EXPECT_TRUE(matrix_2 == matrix_2_now);
}

TEST(TestMul, TestMulOperException_4) {
  EXPECT_ANY_THROW((S21Matrix{-1, 1}.MulMatrix(S21Matrix{1, 1})));
}

TEST(TestMul, TestMulOperException_5) {
  EXPECT_ANY_THROW((S21Matrix{4, 4}.MulMatrix(S21Matrix{0, 4})));
}

TEST(TestMul, TestMulOperException_6) {
  EXPECT_ANY_THROW((S21Matrix{0, 0}.MulMatrix(S21Matrix{0, 0})));
}

TEST(TestMul, TestMulOper_1) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);

  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  matrix_2(0, 0) = 1.0;
  matrix_2(0, 1) = 4.0;
  matrix_2(1, 0) = 2.0;
  matrix_2(1, 1) = 5.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = 5.0;
  expected(0, 1) = 14.0;
  expected(1, 0) = 11.0;
  expected(1, 1) = 32.0;

  S21Matrix result = matrix_1 * matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestMul, TestMulOper_2) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);

  matrix_1(0, 0) = 1.2;
  matrix_1(0, 1) = 4.0;
  matrix_1(0, 2) = 55.0;
  matrix_1(1, 0) = 2.0;
  matrix_1(1, 1) = 3.1;
  matrix_1(1, 2) = 2.0;
  matrix_1(2, 0) = 1.0;
  matrix_1(2, 1) = 19.0;
  matrix_1(2, 2) = 0.0;

  matrix_2(0, 0) = 6.0;
  matrix_2(0, 1) = 8.0;
  matrix_2(0, 2) = 13.0;
  matrix_2(1, 0) = 86.2;
  matrix_2(1, 1) = 15.0;
  matrix_2(1, 2) = 2.0;
  matrix_2(2, 0) = 7.0;
  matrix_2(2, 1) = 1.5;
  matrix_2(2, 2) = 4.0;

  S21Matrix expected(3, 3);
  expected(0, 0) = 737.0;
  expected(0, 1) = 152.1;
  expected(0, 2) = 243.6;
  expected(1, 0) = 293.22;
  expected(1, 1) = 65.5;
  expected(1, 2) = 40.2;
  expected(2, 0) = 1643.8;
  expected(2, 1) = 293.0;
  expected(2, 2) = 51.0;

  S21Matrix result = matrix_1 * matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestMul, TestMulOper_3) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);

  matrix_1(0, 0) = -50.0;
  matrix_1(0, 1) = 24.0;
  matrix_1(1, 0) = 2.0;
  matrix_1(1, 1) = 3.1;

  matrix_2(0, 0) = 67.0;
  matrix_2(0, 1) = 8.0;
  matrix_2(1, 0) = 86.2;
  matrix_2(1, 1) = 0.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = -1281.2;
  expected(0, 1) = -400.0;
  expected(1, 0) = 401.22;
  expected(1, 1) = 16.0;

  S21Matrix result = matrix_1 * matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestMul, TestMulOperPereg_1) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  S21Matrix matrix_2(2, 2);
  matrix_2(0, 0) = 5.0;
  matrix_2(0, 1) = 6.0;
  matrix_2(1, 0) = 7.0;
  matrix_2(1, 1) = 8.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = 19.0;
  expected(0, 1) = 22.0;
  expected(1, 0) = 43.0;
  expected(1, 1) = 50.0;

  matrix_1 *= matrix_2;

  for (int i = 0; i < matrix_1.GetRows(); ++i) {
    for (int j = 0; j < matrix_1.GetCols(); ++j) {
      EXPECT_NEAR(matrix_1(i, j), expected(i, j), 1e-9);
    }
  }

  EXPECT_NEAR(matrix_2(0, 0), 5.0, 1e-9);
  EXPECT_NEAR(matrix_2(0, 1), 6.0, 1e-9);
  EXPECT_NEAR(matrix_2(1, 0), 7.0, 1e-9);
  EXPECT_NEAR(matrix_2(1, 1), 8.0, 1e-9);
}