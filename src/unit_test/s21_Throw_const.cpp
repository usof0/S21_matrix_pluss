#include "s21_test.h"

TEST(TestThrow, TestThrow_1) { EXPECT_ANY_THROW(S21Matrix(-1, 10)); }

TEST(TestThrow, TestThrow_2) { EXPECT_ANY_THROW(S21Matrix(0, 5)); }

TEST(TestThrow, TestThrow_3) { EXPECT_ANY_THROW(S21Matrix(3, -100)); }

TEST(TestThrow, TestThrow_4) { EXPECT_ANY_THROW(S21Matrix(-1000, -1000)); }

TEST(TestThrow, TestThrow_5) { EXPECT_ANY_THROW(S21Matrix(0, 0)); }

TEST(TestThrow, TestThrow_6) { EXPECT_ANY_THROW(S21Matrix(-1, 0)); }

TEST(TestThrow, TestThrow_7) { EXPECT_ANY_THROW(S21Matrix(0, -5)); }