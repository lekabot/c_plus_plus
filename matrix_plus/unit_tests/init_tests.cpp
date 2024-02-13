#include <stdexcept>

#include "main_tests.h"

TEST(S21InitMatrixTest, MoveConstructor) {
  S21Matrix original(2, 3);
  original(0, 0) = 1.0;
  original(0, 1) = 2.0;
  original(0, 2) = 3.0;
  original(1, 0) = 4.0;
  original(1, 1) = 5.0;
  original(1, 2) = 6.0;

  S21Matrix copy(original);

  S21Matrix moved(std::move(copy));

  EXPECT_EQ(moved.GetRows(), 2);
  EXPECT_EQ(moved.GetCols(), 3);

  EXPECT_EQ(moved(0, 0), 1.0);
  EXPECT_EQ(moved(0, 1), 2.0);
  EXPECT_EQ(moved(0, 2), 3.0);
  EXPECT_EQ(moved(1, 0), 4.0);
  EXPECT_EQ(moved(1, 1), 5.0);
  EXPECT_EQ(moved(1, 2), 6.0);

  EXPECT_EQ(copy.GetRows(), 0);
  EXPECT_EQ(copy.GetCols(), 0);
}

TEST(S21InitMatrixTest, StandartConstructorTest) {
  S21Matrix matrix;
  EXPECT_EQ(matrix.GetRows(), 3);
  EXPECT_EQ(matrix.GetCols(), 3);

  double** mat = matrix.GetMatrix();

  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      EXPECT_EQ(mat[i][j], 0);
    }
  }
}

TEST(S21InitMatrixTest, StandardInitTest) {
  S21Matrix matrix;
  ASSERT_NE(matrix.GetMatrix(), nullptr);
}

TEST(S21InitMatrixTest, SecondConstructor) {
  S21Matrix matrix(5, 4);

  EXPECT_EQ(matrix.GetRows(), 5);
  EXPECT_EQ(matrix.GetCols(), 4);

  double** mat = matrix.GetMatrix();

  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      EXPECT_EQ(mat[i][j], 0);
    }
  }
}

TEST(S21InitMatrixTest, MemoryAllocation) {
  const int rows = 2;
  const int cols = 3;
  S21Matrix matrix(rows, cols);

  EXPECT_NE(matrix.GetMatrix(), nullptr);
}

TEST(S21InitMatrixTest, NegativeValuesConstructor) {
  const int rows = -1;
  const int cols = -2;

  EXPECT_THROW(S21Matrix matrix(rows, cols), std::invalid_argument);
}

TEST(S21InitMatrixTest, CopyConstructor) {
  S21Matrix original(3, 3);
  original.FillRand();

  S21Matrix copy(original);

  EXPECT_EQ(copy.GetRows(), original.GetRows());
  EXPECT_EQ(copy.GetCols(), original.GetCols());

  double** original_matrix = original.GetMatrix();
  double** copy_matrix = copy.GetMatrix();

  for (int i = 0; i < original.GetRows(); ++i) {
    for (int j = 0; j < original.GetCols(); ++j) {
      EXPECT_EQ(copy_matrix[i][j], original_matrix[i][j]);
    }
  }
}

TEST(S21InitMatrixTest, CopyConstructorEmptyMatrix) {
  S21Matrix original;

  S21Matrix copy(original);

  EXPECT_EQ(copy.GetRows(), original.GetRows());
  EXPECT_EQ(copy.GetCols(), original.GetCols());

  double** original_matrix = original.GetMatrix();
  double** copy_matrix = copy.GetMatrix();

  for (int i = 0; i < original.GetRows(); ++i) {
    for (int j = 0; j < original.GetCols(); ++j) {
      EXPECT_EQ(copy_matrix[i][j], original_matrix[i][j]);
    }
  }
}
