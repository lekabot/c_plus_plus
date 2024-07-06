#include "main_tests.h"

// +

TEST(MatrixOperatorPlus, OtherRows) {
  S21Matrix m1(11, 12);
  S21Matrix m2(10, 12);

  EXPECT_THROW(m1 + m2, std::invalid_argument);
  EXPECT_THROW(m2 + m1, std::invalid_argument);
}

TEST(MatrixOperatorPlus, OtherCols) {
  S21Matrix m1(10, 11);
  S21Matrix m2(10, 12);

  EXPECT_THROW(m1 + m2, std::invalid_argument);
  EXPECT_THROW(m2 + m1, std::invalid_argument);
}

TEST(MatrixOperatorPlus, OtherRowsCols) {
  S21Matrix m1(11, 12);
  S21Matrix m2(10, 1);

  EXPECT_THROW(m1 + m2, std::invalid_argument);
  EXPECT_THROW(m2 + m1, std::invalid_argument);
}

TEST(MatrixOperatorPlus, SumMatrix) {
  int rows = 9;
  int cols = 10;
  S21Matrix m1(rows, cols);
  S21Matrix m2(rows, cols);
  S21Matrix m3(rows, cols);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      double a = 1.23 + i * 16.123 + j * 4.123;
      double b = 2.1 + i * 19.123 + j * 14.123;
      m1(i, j) = a;
      m2(i, j) = b;
      m3(i, j) = a + b;
    }
  }

  S21Matrix sum(m1 + m2);
  EXPECT_EQ(sum.GetRows(), m3.GetRows());
  EXPECT_EQ(sum.GetCols(), m3.GetCols());
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      EXPECT_EQ(sum(i, j), m3(i, j));
      EXPECT_EQ(sum(i, j), m1(i, j) + m2(i, j));
    }
  }
}

// +

// -

TEST(MatrixOperatorMinus, OtherRows) {
  S21Matrix m1(11, 12);
  S21Matrix m2(10, 12);

  EXPECT_THROW(m1 - m2, std::invalid_argument);
  EXPECT_THROW(m2 - m1, std::invalid_argument);
}

TEST(MatrixOperatorMinus, OtherCols) {
  S21Matrix m1(10, 11);
  S21Matrix m2(10, 12);

  EXPECT_THROW(m1 - m2, std::invalid_argument);
  EXPECT_THROW(m2 - m1, std::invalid_argument);
}

TEST(MatrixOperatorMinus, OtherRowsCols) {
  S21Matrix m1(11, 12);
  S21Matrix m2(10, 1);

  EXPECT_THROW(m1 - m2, std::invalid_argument);
  EXPECT_THROW(m2 - m1, std::invalid_argument);
}

TEST(MatrixOperatorMinus, SubMatrix) {
  int rows = 9;
  int cols = 10;
  S21Matrix m1(rows, cols);
  S21Matrix m2(rows, cols);
  S21Matrix m3(rows, cols);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      double a = 1.23 + i * 16.123 + j * 4.123;
      double b = 2.1 + i * 19.123 + j * 14.123;
      m1(i, j) = a;
      m2(i, j) = b;
      m3(i, j) = a - b;
    }
  }

  S21Matrix sub(m1 - m2);
  EXPECT_EQ(sub.GetRows(), m3.GetRows());
  EXPECT_EQ(sub.GetCols(), m3.GetCols());
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      EXPECT_EQ(sub(i, j), m3(i, j));
      EXPECT_EQ(sub(i, j), m1(i, j) - m2(i, j));
    }
  }
}

// -

// M*N

TEST(MatrixOperatorMulNum, MulMatrixNum) {
  int rows = 9;
  int cols = 10;
  double ratio = -17.123;
  S21Matrix m1(rows, cols);
  S21Matrix m2(rows, cols);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      m1(i, j) = m2(i, j) = 1.23 + i * 16.123 + j * 4.123;
      m2(i, j) *= ratio;
    }
  }

  S21Matrix mul(m1 * ratio);
  EXPECT_EQ(mul.GetRows(), m2.GetRows());
  EXPECT_EQ(mul.GetCols(), m2.GetCols());
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      EXPECT_EQ(mul(i, j), m2(i, j));
      EXPECT_EQ(mul(i, j), m1(i, j) * ratio);
    }
  }
}

// M*N

// M*M

TEST(MatrixOperatorMulMatrix, IncompatibleMatrices) {
  S21Matrix m1(19, 16);
  S21Matrix m2(18, 17);

  EXPECT_THROW(m1 * m2, std::invalid_argument);

  S21Matrix a1(14, 15);
  S21Matrix a2(14, 15);
  EXPECT_THROW(m1 * m2, std::invalid_argument);
}

TEST(MatrixOperatorMulMatrix, SquareMatrices) {
  double a[3][3] = {{-1.0, 2.0, 5.0}, {3.0, 4.0, 6.0}, {-8.0, 2.0, 12.0}};
  double b[3][3] = {{-2.0, 2.0, 19.1}, {5.0, 7.0, 17.7}, {-1.0, 4.0, -13.56}};
  double c[3][3] = {
      {7.0, 32.0, -51.5}, {8.0, 58.0, 46.74}, {14.0, 46.0, -280.12}};

  S21Matrix m1(3, 3);
  S21Matrix m2(3, 3);
  S21Matrix m3(3, 3);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      m1(i, j) = a[i][j];
      m2(i, j) = b[i][j];
      m3(i, j) = c[i][j];
    }
  }

  S21Matrix mul(m1 * m2);
  EXPECT_EQ(mul.GetRows(), m3.GetRows());
  EXPECT_EQ(mul.GetCols(), m3.GetCols());
  for (int i = 0; i < m3.GetRows(); ++i) {
    for (int j = 0; j < m3.GetCols(); ++j) {
      EXPECT_NEAR(mul(i, j), m3(i, j), S21Matrix::kEps);
    }
  }
}

TEST(MatrixOperatorMulMatrix, RectangleMatrices) {
  double a[3][4] = {
      {-1.0, 2.0, 5.0, 78.45}, {3.0, 4.0, 6.0, 19.01}, {-8.0, 2.0, 12.0, 0.43}};
  double b[4][5] = {{-2.0, 2.0, 19.1, 0.5, 0.001},
                    {5.0, 7.0, 17.7, -0.9, -18.78},
                    {-1.0, 4.0, -13.56, 189.1, 19.43},
                    {18.1, 0.3, -17.1, 1983.14, 0.93}};
  double c[3][5] = {{1426.945, 55.535, -1392.995, 156520.533, 132.5475},
                    {352.081, 63.703, -278.331, 38831.9914, 59.1423},
                    {21.783, 46.129, -287.473, 3116.1502, 195.9919}};

  S21Matrix m1(3, 4);
  S21Matrix m2(4, 5);
  S21Matrix m3(3, 5);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      m1(i, j) = a[i][j];
    }
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 5; ++j) {
      m2(i, j) = b[i][j];
    }
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 5; ++j) {
      m3(i, j) = c[i][j];
    }
  }

  S21Matrix mul(m1 * m2);
  EXPECT_EQ(mul.GetRows(), m3.GetRows());
  EXPECT_EQ(mul.GetCols(), m3.GetCols());
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      EXPECT_NEAR(mul(i, j), m3(i, j), S21Matrix::kEps);
    }
  }
}

// M*M

// == & !=

TEST(MatrixOperatorEqual, OtherCols) {
  S21Matrix m1(12, 14);
  S21Matrix m2(12, 11);

  EXPECT_EQ(m1 == m2, false);
  EXPECT_EQ(m2 == m1, false);
}

TEST(MatrixOperatorEqual, OtherRows) {
  S21Matrix m1(11, 14);
  S21Matrix m2(12, 14);

  EXPECT_EQ(m1 == m2, false);
  EXPECT_EQ(m2 == m1, false);
}

TEST(MatrixOperatorEqual, OtherRowsCols) {
  S21Matrix m1(12, 14);
  S21Matrix m2(11, 11);

  EXPECT_EQ(m1 == m2, false);
  EXPECT_EQ(m2 == m1, false);
}

TEST(MatrixOperatorEqual, Equal) {
  S21Matrix m1(12, 14);
  S21Matrix m2(12, 14);

  EXPECT_EQ(m1.EqMatrix(m2), true);
  EXPECT_EQ(m2.EqMatrix(m1), true);

  for (int i = 0; i < m1.GetRows(); ++i) {
    for (int j = 0; j < m1.GetCols(); ++j) {
      m1(i, j) = m2(i, j) = 0.12345 + i * 19.141 + j * 8.3;
    }
  }
  EXPECT_EQ(m1 == m2, true);
  EXPECT_EQ(m2 == m1, true);
}

TEST(MatrixOperatorEqual, NotEqual) {
  S21Matrix m1(12, 14);
  S21Matrix m2(12, 14);

  for (int i = 0; i < m1.GetRows(); ++i) {
    for (int j = 0; j < m1.GetCols(); ++j) {
      m1(i, j) = m2(i, j) = 0.12345 + i * 19.141 + j * 8.3;
    }
  }

  m1(2, 5) += 0.00143;
  EXPECT_EQ(m1 == m2, false);
  EXPECT_EQ(m2 == m1, false);
  m1(2, 5) = m2(2, 5);
  m1(m1.GetRows() - 1, m1.GetCols() - 1) -= 0.0001;
  EXPECT_EQ(m1 == m2, false);
  EXPECT_EQ(m2 == m1, false);
}

// == & !=

// =

TEST(MatrixOperatorAssign, DifferentDimensionLess) {
  S21Matrix m1(12, 14);
  S21Matrix m2(20, 21);

  for (int i = 0; i < m1.GetRows(); ++i) {
    for (int j = 0; j < m1.GetCols(); ++j) {
      m1(i, j) = 0.12345 + i * 19.141 + j * 8.3;
    }
  }
  for (int i = 0; i < m2.GetRows(); ++i) {
    for (int j = 0; j < m2.GetCols(); ++j) {
      m2(i, j) = 0.12345 - i * 19.141 + j * 8.3;
    }
  }

  m2 = m1;
  EXPECT_EQ(m2.GetRows(), m1.GetRows());
  EXPECT_EQ(m2.GetCols(), m1.GetCols());
  EXPECT_TRUE(m2 == m1);
}

TEST(MatrixOperatorAssign, DifferentDimensionGreater) {
  S21Matrix m1(20, 21);
  S21Matrix m2(12, 14);

  for (int i = 0; i < m1.GetRows(); ++i) {
    for (int j = 0; j < m1.GetCols(); ++j) {
      m1(i, j) = 0.12345 + i * 19.141 + j * 8.3;
    }
  }
  for (int i = 0; i < m2.GetRows(); ++i) {
    for (int j = 0; j < m2.GetCols(); ++j) {
      m2(i, j) = 0.12345 - i * 19.141 + j * 8.3;
    }
  }

  m2 = m1;
  EXPECT_EQ(m2.GetRows(), m1.GetRows());
  EXPECT_EQ(m2.GetCols(), m1.GetCols());
  EXPECT_TRUE(m2 == m1);
}

// =

// Move =

TEST(MatrixMoveOperatorAssign, SameDimension) {
  S21Matrix m1(12, 14);
  S21Matrix m2(12, 14);
  S21Matrix m3(12, 14);

  for (int i = 0; i < m1.GetRows(); ++i) {
    for (int j = 0; j < m1.GetCols(); ++j) {
      m1(i, j) = 0.12345 + i * 19.141 + j * 8.3;
      m2(i, j) = 0.12345 - i * 19.141 + j * 8.3;
      m3(i, j) = 0.12345 + i * 19.141 + j * 8.3;
    }
  }

  m2 = std::move(m1);
  EXPECT_EQ(m2.GetRows(), m3.GetRows());
  EXPECT_EQ(m2.GetCols(), m3.GetCols());
  EXPECT_TRUE(m2 == m3);
}

TEST(MatrixMoveOperatorAssign, DifferentDimensionLess) {
  S21Matrix m1(12, 14);
  S21Matrix m2(20, 21);
  S21Matrix m3(12, 14);

  for (int i = 0; i < m1.GetRows(); ++i) {
    for (int j = 0; j < m1.GetCols(); ++j) {
      m1(i, j) = 0.12345 + i * 19.141 + j * 8.3;
      m3(i, j) = 0.12345 + i * 19.141 + j * 8.3;
    }
  }
  for (int i = 0; i < m2.GetRows(); ++i) {
    for (int j = 0; j < m2.GetCols(); ++j) {
      m2(i, j) = 0.12345 - i * 19.141 + j * 8.3;
    }
  }

  m2 = std::move(m1);
  EXPECT_EQ(m2.GetRows(), m3.GetRows());
  EXPECT_EQ(m2.GetCols(), m3.GetCols());
  EXPECT_TRUE(m2 == m3);
}

TEST(MatrixMoveOperatorAssign, DifferentDimensionGreater) {
  S21Matrix m1(20, 21);
  S21Matrix m2(12, 14);
  S21Matrix m3(20, 21);

  for (int i = 0; i < m1.GetRows(); ++i) {
    for (int j = 0; j < m1.GetCols(); ++j) {
      m1(i, j) = 0.12345 + i * 19.141 + j * 8.3;
      m3(i, j) = 0.12345 + i * 19.141 + j * 8.3;
    }
  }
  for (int i = 0; i < m2.GetRows(); ++i) {
    for (int j = 0; j < m2.GetCols(); ++j) {
      m2(i, j) = 0.12345 - i * 19.141 + j * 8.3;
    }
  }

  m2 = std::move(m1);
  EXPECT_EQ(m2.GetRows(), m3.GetRows());
  EXPECT_EQ(m2.GetCols(), m3.GetCols());
  EXPECT_TRUE(m2 == m3);
}

// Move =

// +=

TEST(MatrixOperatorPlusAssign, OtherRows) {
  S21Matrix m1(11, 12);
  S21Matrix m2(10, 12);

  EXPECT_THROW(m1 += m2, std::invalid_argument);
  EXPECT_THROW(m2 += m1, std::invalid_argument);
}

TEST(MatrixOperatorPlusAssign, OtherCols) {
  S21Matrix m1(10, 11);
  S21Matrix m2(10, 12);

  EXPECT_THROW(m1 += m2, std::invalid_argument);
  EXPECT_THROW(m2 += m1, std::invalid_argument);
}

TEST(MatrixOperatorPlusAssign, OtherRowsCols) {
  S21Matrix m1(11, 12);
  S21Matrix m2(10, 1);

  EXPECT_THROW(m1 += m2, std::invalid_argument);
  EXPECT_THROW(m2 += m1, std::invalid_argument);
}

TEST(MatrixOperatorPlusAssign, SumMatrix) {
  int rows = 9;
  int cols = 10;
  S21Matrix m1(rows, cols);
  S21Matrix m2(rows, cols);
  S21Matrix m3(rows, cols);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      double a = 1.23 + i * 16.123 + j * 4.123;
      double b = 2.1 + i * 19.123 + j * 14.123;
      m1(i, j) = a;
      m2(i, j) = b;
      m3(i, j) = a + b;
    }
  }

  m1 += m2;
  EXPECT_EQ(m1.GetRows(), m3.GetRows());
  EXPECT_EQ(m1.GetCols(), m3.GetCols());
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      EXPECT_EQ(m1(i, j), m3(i, j));
    }
  }
}

// +=

// -=

TEST(MatrixOperatorMinusAssign, OtherRows) {
  S21Matrix m1(11, 12);
  S21Matrix m2(10, 12);

  EXPECT_THROW(m1 -= m2, std::invalid_argument);
  EXPECT_THROW(m2 -= m1, std::invalid_argument);
}

TEST(MatrixOperatorMinusAssign, OtherCols) {
  S21Matrix m1(10, 11);
  S21Matrix m2(10, 12);

  EXPECT_THROW(m1 -= m2, std::invalid_argument);
  EXPECT_THROW(m2 -= m1, std::invalid_argument);
}

TEST(MatrixOperatorMinusAssign, OtherRowsCols) {
  S21Matrix m1(11, 12);
  S21Matrix m2(10, 1);

  EXPECT_THROW(m1 -= m2, std::invalid_argument);
  EXPECT_THROW(m2 -= m1, std::invalid_argument);
}

TEST(MatrixOperatorMinusAssign, SumMatrix) {
  int rows = 9;
  int cols = 10;
  S21Matrix m1(rows, cols);
  S21Matrix m2(rows, cols);
  S21Matrix m3(rows, cols);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      double a = 1.23 + i * 16.123 + j * 4.123;
      double b = 2.1 + i * 19.123 + j * 14.123;
      m1(i, j) = a;
      m2(i, j) = b;
      m3(i, j) = a - b;
    }
  }

  m1 -= m2;
  EXPECT_EQ(m1.GetRows(), m3.GetRows());
  EXPECT_EQ(m1.GetCols(), m3.GetCols());
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      EXPECT_EQ(m1(i, j), m3(i, j));
    }
  }
}

// -=

// M *= M

TEST(MatrixOperatorMulAssignMatrix, IncompatibleMatrices) {
  S21Matrix m1(19, 16);
  S21Matrix m2(18, 17);

  EXPECT_THROW(m1 *= m2, std::invalid_argument);

  S21Matrix a1(14, 15);
  S21Matrix a2(14, 15);
  EXPECT_THROW(m1 *= m2, std::invalid_argument);
}

TEST(MatrixOperatorMulAssignMatrix, SquareMatrices) {
  double a[3][3] = {{-1.0, 2.0, 5.0}, {3.0, 4.0, 6.0}, {-8.0, 2.0, 12.0}};
  double b[3][3] = {{-2.0, 2.0, 19.1}, {5.0, 7.0, 17.7}, {-1.0, 4.0, -13.56}};
  double c[3][3] = {
      {7.0, 32.0, -51.5}, {8.0, 58.0, 46.74}, {14.0, 46.0, -280.12}};

  S21Matrix m1(3, 3);
  S21Matrix m2(3, 3);
  S21Matrix m3(3, 3);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      m1(i, j) = a[i][j];
      m2(i, j) = b[i][j];
      m3(i, j) = c[i][j];
    }
  }

  m1 *= m2;
  EXPECT_EQ(m1.GetRows(), m3.GetRows());
  EXPECT_EQ(m1.GetCols(), m3.GetCols());
  for (int i = 0; i < m3.GetRows(); ++i) {
    for (int j = 0; j < m3.GetCols(); ++j) {
      EXPECT_NEAR(m1(i, j), m3(i, j), S21Matrix::kEps);
    }
  }
}

TEST(MatrixOperatorMulAssignMatrix, RectangleMatrices) {
  double a[3][4] = {
      {-1.0, 2.0, 5.0, 78.45}, {3.0, 4.0, 6.0, 19.01}, {-8.0, 2.0, 12.0, 0.43}};
  double b[4][5] = {{-2.0, 2.0, 19.1, 0.5, 0.001},
                    {5.0, 7.0, 17.7, -0.9, -18.78},
                    {-1.0, 4.0, -13.56, 189.1, 19.43},
                    {18.1, 0.3, -17.1, 1983.14, 0.93}};
  double c[3][5] = {{1426.945, 55.535, -1392.995, 156520.533, 132.5475},
                    {352.081, 63.703, -278.331, 38831.9914, 59.1423},
                    {21.783, 46.129, -287.473, 3116.1502, 195.9919}};

  S21Matrix m1(3, 4);
  S21Matrix m2(4, 5);
  S21Matrix m3(3, 5);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      m1(i, j) = a[i][j];
    }
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 5; ++j) {
      m2(i, j) = b[i][j];
    }
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 5; ++j) {
      m3(i, j) = c[i][j];
    }
  }

  m1 *= m2;
  EXPECT_EQ(m1.GetRows(), m3.GetRows());
  EXPECT_EQ(m1.GetCols(), m3.GetCols());
  for (int i = 0; i < m3.GetRows(); ++i) {
    for (int j = 0; j < m3.GetCols(); ++j) {
      EXPECT_NEAR(m1(i, j), m3(i, j), S21Matrix::kEps);
    }
  }
}

// M *= M

// ()

TEST(MatrixOperatorParentheses, LessThanZero) {
  S21Matrix m1(100, 77);
  const S21Matrix m2(100, 77);

  EXPECT_THROW(m1(-1, 14), std::out_of_range);
  EXPECT_THROW(m1(1, -14), std::out_of_range);
  EXPECT_THROW(m1(-11, -14), std::out_of_range);

  EXPECT_THROW(m2(-1, 14), std::out_of_range);
  EXPECT_THROW(m2(1, -14), std::out_of_range);
  EXPECT_THROW(m2(-11, -14), std::out_of_range);
}

TEST(MatrixOperatorParentheses, GreaterThanZero) {
  S21Matrix m1(100, 77);
  const S21Matrix m2(100, 77);

  EXPECT_THROW(m1(100, 14), std::out_of_range);
  EXPECT_THROW(m1(1, 77), std::out_of_range);
  EXPECT_THROW(m1(110, 66), std::out_of_range);
  EXPECT_THROW(m1(11, 99), std::out_of_range);
  EXPECT_THROW(m1(111, 949), std::out_of_range);

  EXPECT_THROW(m2(100, 14), std::out_of_range);
  EXPECT_THROW(m2(1, 77), std::out_of_range);
  EXPECT_THROW(m2(110, 66), std::out_of_range);
  EXPECT_THROW(m2(11, 99), std::out_of_range);
  EXPECT_THROW(m2(111, 949), std::out_of_range);
}

TEST(MatrixOperatorParentheses, NormalIndex) {
  S21Matrix m1(100, 77);
  const S21Matrix m2(100, 77);

  for (int i = 0; i < m1.GetRows(); ++i) {
    for (int j = 0; j < m1.GetCols(); ++j) {
      m1(i, j) = static_cast<double>(i) + static_cast<double>(j);
    }
  }

  EXPECT_EQ(m1(14, 63), 14.0 + 63.0);
  EXPECT_EQ(m2(17, 54), 0.0);
}

// ()

TEST(S21MatrixOperatorTest, MultiplyEqualsOperator) {
  // Создаем исходную матрицу
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix *= 2.0;

  EXPECT_EQ(matrix(0, 0), 2.0);
  EXPECT_EQ(matrix(0, 1), 4.0);
  EXPECT_EQ(matrix(1, 0), 6.0);
  EXPECT_EQ(matrix(1, 1), 8.0);
}

TEST(S21MatrixOperatorTest, NotEqualsOperator) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1.0;
  matrix1(0, 1) = 2.0;
  matrix1(1, 0) = 3.0;
  matrix1(1, 1) = 4.0;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = 1.0;
  matrix2(0, 1) = 2.0;
  matrix2(1, 0) = 3.0;
  matrix2(1, 1) = 5.0;
  EXPECT_TRUE(matrix1 != matrix2);
}
