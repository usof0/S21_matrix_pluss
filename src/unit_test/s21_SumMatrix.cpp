#include "s21_test.h"

TEST(TestSum, TestSumExceptions_1) {
  S21Matrix matrix_1{2, 2};
  S21Matrix matrix_2{2, 1};

  S21Matrix matrix_1_now = matrix_1;
  S21Matrix matrix_2_now = matrix_2;

  EXPECT_ANY_THROW(matrix_1.SumMatrix(matrix_2));
  EXPECT_ANY_THROW(matrix_2.SumMatrix(matrix_1));
  EXPECT_TRUE(matrix_1 == matrix_1_now);
  EXPECT_TRUE(matrix_2 == matrix_2_now);
}

TEST(TestSum, TestSumExceptions_2) {
  EXPECT_ANY_THROW((S21Matrix{0, 5}.SumMatrix(S21Matrix{5, 5})));
}

TEST(TestSum, TestSumExceptions_3) {
  EXPECT_ANY_THROW((S21Matrix{2, 5}.SumMatrix(S21Matrix{0, 10})));
}

TEST(TestSum, TestSumExceptions_4) {
  EXPECT_ANY_THROW((S21Matrix{0, 0}.SumMatrix(S21Matrix{0, 0})));
}

TEST(TestSum, TestSumExceptions_5) {
  EXPECT_ANY_THROW((S21Matrix{-6, 6}.SumMatrix(S21Matrix{6, 6})));
}

TEST(TestSum, TestSum_1) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);

  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  matrix_2(0, 0) = 5.0;
  matrix_2(0, 1) = 6.0;
  matrix_2(1, 0) = 7.0;
  matrix_2(1, 1) = 8.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = 6.0;
  expected(0, 1) = 8.0;
  expected(1, 0) = 10.0;
  expected(1, 1) = 12.0;

  S21Matrix result = matrix_1 + matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestSum, TestSum_2) {
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
  expected(0, 0) = 7.2;
  expected(0, 1) = 12.0;
  expected(0, 2) = 68.0;
  expected(1, 0) = 88.2;
  expected(1, 1) = 18.1;
  expected(1, 2) = 4.0;
  expected(2, 0) = 8.0;
  expected(2, 1) = 20.5;
  expected(2, 2) = 4.0;

  S21Matrix result = matrix_1 + matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestSum, TestSum_3) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);

  matrix_1(0, 0) = 1.2;
  matrix_1(0, 1) = -3.0;
  matrix_1(1, 0) = 6.0;
  matrix_1(1, 1) = 7.9;

  matrix_2(0, 0) = 6.6;
  matrix_2(0, 1) = 8.0;
  matrix_2(1, 0) = -2.0;
  matrix_2(1, 1) = 15.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = 7.8;
  expected(0, 1) = 5.0;
  expected(1, 0) = 4.0;
  expected(1, 1) = 22.9;

  S21Matrix result = matrix_1 + matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestSum, TestSum_4) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);

  matrix_1(0, 0) = -159.8;
  matrix_1(0, 1) = 25789.0;
  matrix_1(1, 0) = 6666666.0;
  matrix_1(1, 1) = 7432.9;

  matrix_2(0, 0) = -789;
  matrix_2(0, 1) = 878;
  matrix_2(1, 0) = -234.7;
  matrix_2(1, 1) = 15989;

  S21Matrix expected(2, 2);
  expected(0, 0) = -948.8;
  expected(0, 1) = 26667;
  expected(1, 0) = 6666431.3;
  expected(1, 1) = 23421.9;

  S21Matrix result = matrix_1 + matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestSum, TestSumOperException_1) {
  S21Matrix matrix_1{5, 3};
  S21Matrix matrix_2{3, 3};

  S21Matrix matrix_1_now = matrix_1;
  S21Matrix matrix_2_now = matrix_2;

  EXPECT_ANY_THROW(matrix_1 + matrix_2);
  EXPECT_ANY_THROW(matrix_2 + matrix_1);
  EXPECT_TRUE(matrix_1 == matrix_1_now);
  EXPECT_TRUE(matrix_2 == matrix_2_now);
}

TEST(TestSum, TestSumOperException_2) {
  S21Matrix matrix_1{5, 3};
  S21Matrix matrix_2{3, 3};

  S21Matrix matrix_1_now = matrix_1;
  S21Matrix matrix_2_now = matrix_2;

  EXPECT_ANY_THROW(matrix_1 + matrix_2);
  EXPECT_ANY_THROW(matrix_2 + matrix_1);
  EXPECT_TRUE(matrix_1 == matrix_1_now);
  EXPECT_TRUE(matrix_2 == matrix_2_now);
}

TEST(TestSum, TestSumOperException_3) {
  S21Matrix matrix_1{7, 3};
  S21Matrix matrix_2{1, 3};

  S21Matrix matrix_1_now = matrix_1;
  S21Matrix matrix_2_now = matrix_2;

  EXPECT_ANY_THROW(matrix_1 + matrix_2);
  EXPECT_ANY_THROW(matrix_2 + matrix_1);
  EXPECT_TRUE(matrix_1 == matrix_1_now);
  EXPECT_TRUE(matrix_2 == matrix_2_now);
}

TEST(TestSum, TTestSumOperException_4) {
  EXPECT_ANY_THROW((S21Matrix{-1, 1}.SumMatrix(S21Matrix{1, 1})));
}

TEST(TestSum, TTestSumOperException_5) {
  EXPECT_ANY_THROW((S21Matrix{4, 4}.SumMatrix(S21Matrix{0, 4})));
}

TEST(TestSum, TTestSumOperException_6) {
  EXPECT_ANY_THROW((S21Matrix{0, 0}.SumMatrix(S21Matrix{0, 0})));
}

TEST(TestSum, TestSumOper_1) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);

  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 2.0;
  matrix_1(1, 0) = 3.0;
  matrix_1(1, 1) = 4.0;

  matrix_2(0, 0) = 5.0;
  matrix_2(0, 1) = 6.0;
  matrix_2(1, 0) = 7.0;
  matrix_2(1, 1) = 8.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = 6.0;
  expected(0, 1) = 8.0;
  expected(1, 0) = 10.0;
  expected(1, 1) = 12.0;

  S21Matrix result = matrix_1 + matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestSum, TestSumOper_2) {
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
  expected(0, 0) = 7.2;
  expected(0, 1) = 12.0;
  expected(0, 2) = 68.0;
  expected(1, 0) = 88.2;
  expected(1, 1) = 18.1;
  expected(1, 2) = 4.0;
  expected(2, 0) = 8.0;
  expected(2, 1) = 20.5;
  expected(2, 2) = 4.0;

  S21Matrix result = matrix_1 + matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestSum, TestSumOper_3) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);

  matrix_1(0, 0) = 1.2;
  matrix_1(0, 1) = -3.0;
  matrix_1(1, 0) = 6.0;
  matrix_1(1, 1) = 7.9;

  matrix_2(0, 0) = 6.6;
  matrix_2(0, 1) = 8.0;
  matrix_2(1, 0) = -2.0;
  matrix_2(1, 1) = 15.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = 7.8;
  expected(0, 1) = 5.0;
  expected(1, 0) = 4.0;
  expected(1, 1) = 22.9;

  S21Matrix result = matrix_1 + matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestSum, TestSumOper_4) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);

  matrix_1(0, 0) = -159.8;
  matrix_1(0, 1) = 25789.0;
  matrix_1(1, 0) = 6666666.0;
  matrix_1(1, 1) = 7432.9;

  matrix_2(0, 0) = -789;
  matrix_2(0, 1) = 878;
  matrix_2(1, 0) = -234.7;
  matrix_2(1, 1) = 15989;

  S21Matrix expected(2, 2);
  expected(0, 0) = -948.8;
  expected(0, 1) = 26667;
  expected(1, 0) = 6666431.3;
  expected(1, 1) = 23421.9;

  S21Matrix result = matrix_1 + matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestSum, TestSumOperPereg_1) {
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
  expected(0, 0) = 6.0;
  expected(0, 1) = 8.0;
  expected(1, 0) = 10.0;
  expected(1, 1) = 12.0;

  matrix_1 += matrix_2;

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