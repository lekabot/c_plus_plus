#include "main_tests.h"

// EQ

TEST(MatrixEq, EqMatrixDifferentMatrices) {
  S21Matrix matrix1(3, 3);
  matrix1.FillMatrix(4);
  S21Matrix matrix2(3, 3);
  matrix2.FillMatrix(5);

  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
}

TEST(MatrixEq, EqMatrixEqualMatrices) {
  S21Matrix matrix1(2, 2);
  matrix1.FillMatrix(5);

  S21Matrix matrix2(2, 2);
  matrix2.FillMatrix(5);
  EXPECT_TRUE(matrix1.EqMatrix(matrix2));
}

TEST(MatrixEq, EqMatrixDifferentSizes) {
  S21Matrix matrix1(2, 3);
  matrix1.FillRand();
  S21Matrix matrix2(3, 2);
  matrix2.FillRand();

  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
}

// EQ

// SUM

TEST(MatrixSum, SumMatrixSameSize) {
  S21Matrix matrix1(2, 2);
  matrix1.FillMatrix(2);

  S21Matrix matrix2(2, 2);
  matrix2.FillMatrix(3);

  matrix1.SumMatrix(matrix2);

  double** result = matrix1.GetMatrix();
  EXPECT_EQ(result[0][0], 5);
  EXPECT_EQ(result[0][1], 5);
  EXPECT_EQ(result[1][0], 5);
  EXPECT_EQ(result[1][1], 5);
}

TEST(MatrixSum, SumMatrixDiffSize) {
  S21Matrix matrix1(22, 3);
  matrix1.FillMatrix(2);

  S21Matrix matrix2(1, 23);
  matrix2.FillMatrix(3);

  EXPECT_THROW(matrix1.SumMatrix(matrix2), std::invalid_argument);
}

// SUM

// SUB

TEST(MatrixSub, SubMatrixSameSize) {
  S21Matrix matrix1(2, 2);
  matrix1.FillMatrix(5);

  S21Matrix matrix2(2, 2);
  matrix2.FillMatrix(3);

  matrix1.SubMatrix(matrix2);

  double** result = matrix1.GetMatrix();
  EXPECT_EQ(result[0][0], 2);
  EXPECT_EQ(result[0][1], 2);
  EXPECT_EQ(result[1][0], 2);
  EXPECT_EQ(result[1][1], 2);
}

TEST(MatrixSub, SubMatrixDiffSize) {
  S21Matrix matrix1(2, 2);
  matrix1.FillMatrix(5);

  S21Matrix matrix2(3, 3);
  matrix2.FillMatrix(3);

  EXPECT_THROW(matrix1.SubMatrix(matrix2), std::invalid_argument);
}

// SUB

// MUlN

TEST(MatrixMulN, MulNumberTest) {
  S21Matrix matrix(2, 2);
  matrix.FillMatrix(3);

  matrix.MulNumber(2);

  double** result = matrix.GetMatrix();
  EXPECT_EQ(result[0][0], 6);
  EXPECT_EQ(result[0][1], 6);
  EXPECT_EQ(result[1][0], 6);
  EXPECT_EQ(result[1][1], 6);
}

// MULN

// MULM

TEST(MatrixMulMatrix, MulMatrixValidTest) {
  S21Matrix matrix1(2, 3);
  matrix1.FillMatrix(3);

  S21Matrix matrix2(3, 2);
  matrix2.FillMatrix(3);

  S21Matrix expected(2, 2);
  expected.FillMatrix(27);

  matrix1.MulMatrix(matrix2);

  EXPECT_TRUE(matrix1.EqMatrix(expected));
}

TEST(MatrixMulMatrix, MulMatrixValidTest2) {
  S21Matrix matrix1(3, 3);
  matrix1.FillMatrix(3);

  S21Matrix matrix2(3, 3);
  matrix2.FillMatrix(3);

  S21Matrix expected(3, 3);
  expected.FillMatrix(27);

  matrix1.MulMatrix(matrix2);

  EXPECT_TRUE(matrix1.EqMatrix(expected));
}

TEST(MatrixMulMatrix, MulMatrixInvalidTest) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(2, 2);
  EXPECT_THROW(matrix1.MulMatrix(matrix2), std::exception);
}

TEST(MatrixMulMatrix, SquareMatrices) {
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

  m1.MulMatrix(m2);
  EXPECT_EQ(m1.GetRows(), m3.GetRows());
  EXPECT_EQ(m1.GetCols(), m3.GetCols());
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      EXPECT_NEAR(m1(i, j), m3(i, j), S21Matrix::kEps);
    }
  }
}

TEST(MatrixMulMatrix, RectangleMatrices) {
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

  m1.MulMatrix(m2);
  EXPECT_EQ(m1.GetRows(), m3.GetRows());
  EXPECT_EQ(m1.GetCols(), m3.GetCols());
  for (int i = 0; i < m3.GetRows(); ++i) {
    for (int j = 0; j < m3.GetCols(); ++j) {
      EXPECT_NEAR(m1(i, j), m3(i, j), S21Matrix::kEps);
    }
  }
}

// MULM

// TRANS

TEST(MatrixTranspose, SquareMatrix) {
  int rows = 97;
  int cols = 97;
  S21Matrix m1(rows, cols);
  S21Matrix m2(cols, rows);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      m1(i, j) = m2(j, i) = 192.123 + i * 17.123 - j * 9.87;
    }
  }
  S21Matrix m3(m1.Transpose());
  EXPECT_EQ(m1.GetRows(), m3.GetCols());
  EXPECT_EQ(m1.GetCols(), m3.GetRows());
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      EXPECT_EQ(m1(i, j), m3(j, i));
    }
  }
  for (int i = 0; i < cols; ++i) {
    for (int j = 0; j < rows; ++j) {
      EXPECT_EQ(m2(i, j), m3(i, j));
    }
  }
}

TEST(MatrixTranspose, RectangleMatrix) {
  int rows = 97;
  int cols = 197;
  S21Matrix m1(rows, cols);
  S21Matrix m2(cols, rows);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      m1(i, j) = m2(j, i) = 192.123 + i * 17.123 - j * 9.87;
    }
  }
  S21Matrix m3(m1.Transpose());
  EXPECT_EQ(m1.GetRows(), m3.GetCols());
  EXPECT_EQ(m1.GetCols(), m3.GetRows());
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      EXPECT_EQ(m1(i, j), m3(j, i));
    }
  }
  for (int i = 0; i < cols; ++i) {
    for (int j = 0; j < rows; ++j) {
      EXPECT_EQ(m2(i, j), m3(i, j));
    }
  }
}

// TRANS

// COMPLEMENTS

TEST(MatrixCalcComplements, Matrix1x1) {
  S21Matrix m1(1, 1);
  S21Matrix m2(1, 1);

  m1(0, 0) = 0.0;
  S21Matrix comp1 = m1.CalcComplements();
  EXPECT_EQ(comp1.GetRows(), 1);
  EXPECT_EQ(comp1.GetCols(), 1);
  EXPECT_EQ(comp1(0, 0), 1.0);

  m2(0, 0) = 100.0;
  S21Matrix comp2 = m2.CalcComplements();
  EXPECT_EQ(comp2.GetRows(), 1);
  EXPECT_EQ(comp2.GetCols(), 1);
  EXPECT_EQ(comp2(0, 0), 1.0);
}

TEST(MatrixCalcComplements, Matrix2x2) {
  double a[2][2] = {{15.87, 78.98}, {47.25, -45.478}};
  double b[2][2] = {{-45.478, -47.25}, {-78.98, 15.87}};

  S21Matrix ma(2, 2);
  S21Matrix mb(2, 2);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      ma(i, j) = a[i][j];
      mb(i, j) = b[i][j];
    }
  }

  S21Matrix comp = ma.CalcComplements();
  EXPECT_TRUE(comp == mb);
}

TEST(MatrixCalcComplements, Matrix3x3) {
  double a[3][3] = {{1., 2., 3.}, {0., 4., 2.}, {5., 2., 1.}};
  double b[3][3] = {{0., 10., -20.}, {4., -14., 8.}, {-8., -2., 4.}};

  S21Matrix ma(3, 3);
  S21Matrix mb(3, 3);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      ma(i, j) = a[i][j];
      mb(i, j) = b[i][j];
    }
  }

  S21Matrix comp = ma.CalcComplements();
  EXPECT_TRUE(comp == mb);
}

TEST(MatrixCalcComplements, Matrix4x4) {
  double a[4][4] = {
      {4., 5., 9., 8.}, {4., 1., 2., 3.}, {8., 7., 15., 4.}, {7., 6., 4., 9}};
  double b[4][4] = {{-145., -169., 109., 177.},
                    {252., -504., 72., 108.},
                    {47., 95., 25., -111.},
                    {24., 276., -132., -36.}};

  S21Matrix ma(4, 4);
  S21Matrix mb(4, 4);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      ma(i, j) = a[i][j];
      mb(i, j) = b[i][j];
    }
  }

  S21Matrix comp = ma.CalcComplements();
  EXPECT_TRUE(comp == mb);
}

TEST(MatrixCalcComplements, Matrix5x5) {
  double a[5][5] = {{78., 951., 147., 47., 52.},
                    {76., 98., 78., 753., -89.},
                    {87., 457., 253., 984., -71.},
                    {47., 453., 786., 123., 357.},
                    {765., -896., 783., 478., 456}};
  double b[5][5] = {
      {892211883., -9088259207., 44376427597., -13166556043., -81751647719.},
      {97617917421., -13672761316., 251606522691., -104032036661.,
       -513616435766.},
      {-71997449493., 10510919457., -193843105045., 72992451018.,
       397773228858.},
      {25486500814., -1504267981., 29580687324., -14989913303., -80792756249.},
      {-12212500158., 1182045334., -9293332343., 4297527901., 19088191207}};

  S21Matrix ma(5, 5);
  S21Matrix mb(5, 5);
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      ma(i, j) = a[i][j];
      mb(i, j) = b[i][j];
    }
  }

  S21Matrix comp = ma.CalcComplements();
  EXPECT_TRUE(comp == mb);
}

TEST(MatrixCalcComplements, RectangleMatrix) {
  S21Matrix m1(19, 18);
  S21Matrix m2(21, 43);

  EXPECT_THROW(m1.CalcComplements(), std::invalid_argument);
  EXPECT_THROW(m2.CalcComplements(), std::invalid_argument);
}

// COMPLEMENTS

// DETERMINANT

TEST(MatrixDeterminant, Matrix1x1) {
  double dt = 1183.2019381738;
  S21Matrix m(1, 1);

  m(0, 0) = dt;
  EXPECT_NEAR(dt, m.Determinant(), S21Matrix::kEps);
}

TEST(MatrixDeterminant, Matrix2x2) {
  double a[2][2] = {{179.38, 18.91}, {2.18821, 472.9428}};
  double dt = 84795.1004129;
  S21Matrix m(2, 2);

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      m(i, j) = a[i][j];
    }
  }
  EXPECT_NEAR(dt, m.Determinant(), S21Matrix::kEps);
}

TEST(MatrixDeterminant, Matrix3x3) {
  double a[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {5.0, 7.0, 9.0}};
  double dt = 0.0;
  S21Matrix m(3, 3);

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      m(i, j) = a[i][j];
    }
  }
  EXPECT_NEAR(dt, m.Determinant(), S21Matrix::kEps);
}

TEST(MatrixDeterminant, Matrix5x5) {
  double a[5][5] = {{3.0, 2.0, -6.0, 2.0, -6.0},
                    {-4.0, 17.0, 7.0, 17.0, 7.0},
                    {1.0, 2.0, 9.0, -3.0, 4.0},
                    {12.0, 3.0, 3.0, 2.0, 9.0},
                    {-1.0, -2.0, 4.0, 8.0, -1.0}};
  double dt = -158255.0;

  S21Matrix m(5, 5);
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      m(i, j) = a[i][j];
    }
  }
  EXPECT_NEAR(dt, m.Determinant(), S21Matrix::kEps);
}

TEST(MatrixDeterminant, Matrix6x6) {
  double a[6][6] = {{1.1, 1.2, 1.3, 1.4, 1.5, 1.6},
                    {2.8, -2.9, -2.3, -2.4, 2.5, 2.7},
                    {3.33, 3.2, -3.87, 3.99, 3.47, -3.02},
                    {4.85, 4.23, 4.32, -4.18, 4.89, 4.23},
                    {5.12, 5.32, 5.28, 5.67, -5.73, 5.91},
                    {6.15, -6.53, 6.44, 6.32, 6.78, 6.98}};
  double dt = -77591.0 - (269266237810933.0 / 3733527061589101.0);

  S21Matrix m(6, 6);
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
      m(i, j) = a[i][j];
    }
  }
  EXPECT_NEAR(dt, m.Determinant(), S21Matrix::kEps);
}

TEST(MatrixDeterminant, Matrix6x6_2) {
  double a[6][6] = {{0.0, 1.2, 1.3, 1.4, 1.5, 1.6},
                    {0.0, -2.9, -2.3, -2.4, 2.5, 2.7},
                    {0.0, 3.2, -3.87, 3.99, 3.47, -3.02},
                    {0.0, 4.23, 4.32, -4.18, 4.89, 4.23},
                    {0.0, 5.32, 5.28, 5.67, -5.73, 5.91},
                    {0.0, -6.53, 6.44, 6.32, 6.78, 6.98}};
  double dt = 0.0;

  S21Matrix m(6, 6);
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
      m(i, j) = a[i][j];
    }
  }
  EXPECT_NEAR(dt, m.Determinant(), S21Matrix::kEps);
}

TEST(MatrixDeterminant, RectangleMatrix) {
  S21Matrix m1(1, 2);
  S21Matrix m2(115, 23);

  EXPECT_THROW(m1.Determinant(), std::invalid_argument);
  EXPECT_THROW(m2.Determinant(), std::invalid_argument);
}

// DETERMINANT

// INVERSE

TEST(MatrixInverse, Matrix1x1) {
  double a = 125480.4;
  double b = 5.0 / 627402.0;

  S21Matrix m(1, 1);
  m(0, 0) = a;
  S21Matrix inverse = m.InverseMatrix();
  EXPECT_EQ(inverse.GetRows(), m.GetRows());
  EXPECT_EQ(inverse.GetCols(), m.GetCols());
  EXPECT_NEAR(inverse(0, 0), b, S21Matrix::kEps);
}

TEST(MatrixInverse, Matrix3x3) {
  double a[3][3] = {{2., 5., 7.}, {6., 3., 4.}, {5., -2., -3.}};
  double b[3][3] = {{1., -1., 1.}, {-38., 41., -34.}, {27., -29., 24.}};

  S21Matrix ma(3, 3);
  S21Matrix mb(3, 3);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      ma(i, j) = a[i][j];
      mb(i, j) = b[i][j];
    }
  }

  S21Matrix inverse = ma.InverseMatrix();
  EXPECT_TRUE(inverse == mb);
}

TEST(MatrixInverse, Matrix6x6) {
  double a[6][6] = {
      {12., 47., 58., 47., 42., 14.},   {47., 59., 63., 54., 89., 12.},
      {15., 56., -65., -97., 32., 16.}, {58., 75., -24., 45., -16., 8.},
      {78., 93., 17., 13., -11., 7.},   {84., 65., 19., -35., 54., 18.}};
  double b[6][6] = {{-0.01, -0.001, -0.009, 0.006, -0.005, 0.016},
                    {0.0, 0.008, 0.01, -0.007, 0.018, -0.018},
                    {0.009, -0.005, -0.004, -0.014, 0.011, 0.002},
                    {0.001, 0.003, -0.004, 0.012, -0.009, -0.001},
                    {-0.011, 0.017, 0.005, -0.001, -0.004, -0.005},
                    {0.075, -0.067, -0.012, 0.04, -0.061, 0.058}};

  S21Matrix ma(6, 6);
  S21Matrix mb(6, 6);
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
      ma(i, j) = a[i][j];
      mb(i, j) = b[i][j];
    }
  }

  S21Matrix inverse = ma.InverseMatrix();
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
      EXPECT_NEAR(inverse(i, j), b[i][j], 1.0e-3);
    }
  }
}

TEST(MatrixInverse, NoExist) {
  double a[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {5.0, 7.0, 9.0}};

  S21Matrix m(3, 3);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      m(i, j) = a[i][j];
    }
  }

  EXPECT_THROW(m.InverseMatrix(), std::invalid_argument);
}

TEST(MatrixInverse, NoExist2) {
  S21Matrix m1(1, 1);
  m1(0, 0) = 0.0;
  EXPECT_THROW(m1.InverseMatrix(), std::invalid_argument);

  S21Matrix m2(13, 10);
  EXPECT_THROW(m2.InverseMatrix(), std::invalid_argument);

  S21Matrix m3(9, 10);
  EXPECT_THROW(m3.InverseMatrix(), std::invalid_argument);
}

// INVERSE

TEST(S21CopyMatrixTest, SameDimensions) {
  S21Matrix original(2, 2);
  S21Matrix other(3, 3);

  other.FillRand();

  original.CopyMatrix(other);

  for (int i = 0; i < original.GetRows(); ++i) {
    for (int j = 0; j < original.GetCols(); ++j) {
      EXPECT_EQ(original(i, j), other(i, j));
    }
  }
}

TEST(S21CopyMatrixTest, FewerRowsAndColumns) {
  S21Matrix original(4, 4);
  S21Matrix other(3, 3);

  other.FillRand();

  original.CopyMatrix(other);

  for (int i = 0; i < other.GetRows(); ++i) {
    for (int j = 0; j < other.GetCols(); ++j) {
      EXPECT_EQ(original(i, j), other(i, j));
    }
  }

  for (int i = other.GetRows(); i < original.GetRows(); ++i) {
    for (int j = other.GetCols(); j < original.GetCols(); ++j) {
      EXPECT_EQ(original(i, j), 0.0);
    }
  }
}