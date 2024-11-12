#include "s21_test.h"

TEST(TestSub, TestSubExceptions_1) {
  S21Matrix matrix_1{2, 2};
  S21Matrix matrix_2{2, 1};

  S21Matrix matrix_1_now = matrix_1;
  S21Matrix matrix_2_now = matrix_2;

  EXPECT_ANY_THROW(matrix_1.SubMatrix(matrix_2));
  EXPECT_ANY_THROW(matrix_2.SubMatrix(matrix_1));
  EXPECT_TRUE(matrix_1 == matrix_1_now);
  EXPECT_TRUE(matrix_2 == matrix_2_now);
}

TEST(TestSub, TestSubExceptions_2) {
  EXPECT_ANY_THROW((S21Matrix{0, 5}.EqMatrix(S21Matrix{5, 5})));
}

TEST(TestSub, TestSubExceptions_3) {
  EXPECT_ANY_THROW((S21Matrix{2, 5}.EqMatrix(S21Matrix{0, 10})));
}

TEST(TestSub, TestSubExceptions_4) {
  EXPECT_ANY_THROW((S21Matrix{0, 0}.SubMatrix(S21Matrix{0, 0})));
}

TEST(TestSub, TestSubExceptions_5) {
  EXPECT_ANY_THROW((S21Matrix{-6, 6}.SubMatrix(S21Matrix{6, 6})));
}

TEST(TestSub, TestSub_1) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);

  matrix_1(0, 0) = -15.8;
  matrix_1(0, 1) = 25.0;
  matrix_1(1, 0) = 6.0;
  matrix_1(1, 1) = 7.9;

  matrix_2(0, 0) = -7.0;
  matrix_2(0, 1) = 87.8;
  matrix_2(1, 0) = -23.0;
  matrix_2(1, 1) = 1.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = -8.8;
  expected(0, 1) = -62.8;
  expected(1, 0) = 29.0;
  expected(1, 1) = 6.9;

  S21Matrix result = matrix_1 - matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestSub, TestSub_2) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);

  matrix_1(0, 0) = -1.8;
  matrix_1(0, 1) = 25.0;
  matrix_1(0, 2) = 0.0;
  matrix_1(1, 0) = 6.0;
  matrix_1(1, 1) = 55.0;
  matrix_1(1, 2) = 3.0;
  matrix_1(2, 0) = 4.8;
  matrix_1(2, 1) = 6.0;
  matrix_1(2, 2) = 0.2;

  matrix_2(0, 0) = 15.0;
  matrix_2(0, 1) = 8.8;
  matrix_2(0, 2) = 2.0;
  matrix_2(1, 0) = -2.0;
  matrix_2(1, 1) = 1.0;
  matrix_2(1, 2) = 5.0;
  matrix_2(2, 0) = 3.2;
  matrix_2(2, 1) = 0.0;
  matrix_2(2, 2) = 9.0;

  S21Matrix expected(3, 3);
  expected(0, 0) = -16.8;
  expected(0, 1) = 16.2;
  expected(0, 2) = -2.0;
  expected(1, 0) = 8.0;
  expected(1, 1) = 54.0;
  expected(1, 2) = -2.0;
  expected(2, 0) = 1.6;
  expected(2, 1) = 6.0;
  expected(2, 2) = -8.8;

  S21Matrix result = matrix_1 - matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestSub, TestSub_3) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);

  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 3.0;
  matrix_1(1, 0) = 2.0;
  matrix_1(1, 1) = 4.0;

  matrix_2(0, 0) = 5.0;
  matrix_2(0, 1) = 7.0;
  matrix_2(1, 0) = 6.0;
  matrix_2(1, 1) = 8.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = -4.0;
  expected(0, 1) = -4.0;
  expected(1, 0) = -4.0;
  expected(1, 1) = -4.0;

  S21Matrix result = matrix_1 - matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestSub, TestSub_4) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);

  matrix_1(0, 0) = 12345;
  matrix_1(0, 1) = -8765;
  matrix_1(1, 0) = 432.78;
  matrix_1(1, 1) = 4.0;

  matrix_2(0, 0) = 964.1;
  matrix_2(0, 1) = -794.8;
  matrix_2(1, 0) = 6.0;
  matrix_2(1, 1) = 854;

  S21Matrix expected(2, 2);
  expected(0, 0) = 11380.9;
  expected(0, 1) = -7970.2;
  expected(1, 0) = 426.78;
  expected(1, 1) = -850;

  S21Matrix result = matrix_1 - matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestSub, TestSubOperException_1) {
  S21Matrix matrix_1{5, 3};
  S21Matrix matrix_2{3, 3};

  S21Matrix matrix_1_now = matrix_1;
  S21Matrix matrix_2_now = matrix_2;

  EXPECT_ANY_THROW(matrix_1 + matrix_2);
  EXPECT_ANY_THROW(matrix_2 + matrix_1);
  EXPECT_TRUE(matrix_1 == matrix_1_now);
  EXPECT_TRUE(matrix_2 == matrix_2_now);
}

TEST(TestSub, TestSubOperException_2) {
  S21Matrix matrix_1{5, 3};
  S21Matrix matrix_2{3, 3};

  S21Matrix matrix_1_now = matrix_1;
  S21Matrix matrix_2_now = matrix_2;

  EXPECT_ANY_THROW(matrix_1 + matrix_2);
  EXPECT_ANY_THROW(matrix_2 + matrix_1);
  EXPECT_TRUE(matrix_1 == matrix_1_now);
  EXPECT_TRUE(matrix_2 == matrix_2_now);
}

TEST(TestSub, TestSubOperException_3) {
  S21Matrix matrix_1{7, 3};
  S21Matrix matrix_2{1, 3};

  S21Matrix matrix_1_now = matrix_1;
  S21Matrix matrix_2_now = matrix_2;

  EXPECT_ANY_THROW(matrix_1 + matrix_2);
  EXPECT_ANY_THROW(matrix_2 + matrix_1);
  EXPECT_TRUE(matrix_1 == matrix_1_now);
  EXPECT_TRUE(matrix_2 == matrix_2_now);
}

TEST(TestSub, TestSubOperException_4) {
  EXPECT_ANY_THROW((S21Matrix{-1, 1}.SubMatrix(S21Matrix{1, 1})));
}

TEST(TestSub, TestSubOperException_5) {
  EXPECT_ANY_THROW((S21Matrix{4, 4}.SubMatrix(S21Matrix{0, 4})));
}

TEST(TestSub, TestSubOperException_6) {
  EXPECT_ANY_THROW((S21Matrix{0, 0}.SubMatrix(S21Matrix{0, 0})));
}

TEST(TestSub, SubOper_1) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);

  matrix_1(0, 0) = -15.8;
  matrix_1(0, 1) = 25.0;
  matrix_1(1, 0) = 6.0;
  matrix_1(1, 1) = 7.9;

  matrix_2(0, 0) = -7.0;
  matrix_2(0, 1) = 87.8;
  matrix_2(1, 0) = -23.0;
  matrix_2(1, 1) = 1.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = -8.8;
  expected(0, 1) = -62.8;
  expected(1, 0) = 29.0;
  expected(1, 1) = 6.9;

  S21Matrix result = matrix_1 - matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestSub, SubOper_2) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);

  matrix_1(0, 0) = -1.8;
  matrix_1(0, 1) = 25.0;
  matrix_1(0, 2) = 0.0;
  matrix_1(1, 0) = 6.0;
  matrix_1(1, 1) = 55.0;
  matrix_1(1, 2) = 3.0;
  matrix_1(2, 0) = 4.8;
  matrix_1(2, 1) = 6.0;
  matrix_1(2, 2) = 0.2;

  matrix_2(0, 0) = 15.0;
  matrix_2(0, 1) = 8.8;
  matrix_2(0, 2) = 2.0;
  matrix_2(1, 0) = -2.0;
  matrix_2(1, 1) = 1.0;
  matrix_2(1, 2) = 5.0;
  matrix_2(2, 0) = 3.2;
  matrix_2(2, 1) = 0.0;
  matrix_2(2, 2) = 9.0;

  S21Matrix expected(3, 3);
  expected(0, 0) = -16.8;
  expected(0, 1) = 16.2;
  expected(0, 2) = -2.0;
  expected(1, 0) = 8.0;
  expected(1, 1) = 54.0;
  expected(1, 2) = -2.0;
  expected(2, 0) = 1.6;
  expected(2, 1) = 6.0;
  expected(2, 2) = -8.8;

  S21Matrix result = matrix_1 - matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestSub, SubOper_3) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);

  matrix_1(0, 0) = 1.0;
  matrix_1(0, 1) = 3.0;
  matrix_1(1, 0) = 2.0;
  matrix_1(1, 1) = 4.0;

  matrix_2(0, 0) = 5.0;
  matrix_2(0, 1) = 7.0;
  matrix_2(1, 0) = 6.0;
  matrix_2(1, 1) = 8.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = -4.0;
  expected(0, 1) = -4.0;
  expected(1, 0) = -4.0;
  expected(1, 1) = -4.0;

  S21Matrix result = matrix_1 - matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestSub, SubOper_4) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);

  matrix_1(0, 0) = 12345;
  matrix_1(0, 1) = -8765;
  matrix_1(1, 0) = 432.78;
  matrix_1(1, 1) = 4.0;

  matrix_2(0, 0) = 964.1;
  matrix_2(0, 1) = -794.8;
  matrix_2(1, 0) = 6.0;
  matrix_2(1, 1) = 854;

  S21Matrix expected(2, 2);
  expected(0, 0) = 11380.9;
  expected(0, 1) = -7970.2;
  expected(1, 0) = 426.78;
  expected(1, 1) = -850;

  S21Matrix result = matrix_1 - matrix_2;

  for (int i = 0; i < result.GetRows(); ++i) {
    for (int j = 0; j < result.GetCols(); ++j) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-9);
    }
  }
}

TEST(TestSum, TestSubOperPereg_1) {
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
  expected(0, 0) = -4.0;
  expected(0, 1) = -4.0;
  expected(1, 0) = -4.0;
  expected(1, 1) = -4.0;

  matrix_1 -= matrix_2;

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