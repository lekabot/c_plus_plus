#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#include <math.h>

#include <cstring>
#include <iostream>

class S21Matrix {
 public:
  static const double kEps;

  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();
  S21Matrix Minor(int row, int col) const;

  bool operator==(const S21Matrix& other) const;
  bool operator!=(const S21Matrix other) const;
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  S21Matrix& operator=(const S21Matrix& other);

  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(const double number) const;

  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double number);
  const double& operator()(int i, int j) const;
  double& operator()(int i, int j);

  void FillMatrix(double value);
  void FillRand();
  int GetRows();
  int GetCols();
  double** GetMatrix();
  // void SetMatrix(int rows, int cols, double value);
  // void PrintMatrix() const;
  void SwapMatrix(S21Matrix& other) noexcept;
  void CopyMatrix(const S21Matrix& other);

 private:
  int rows_;
  int cols_;
  double** matrix_;
  double GetRand(double min, double max);
  void Allocate();
  void Deallocate();
};

#endif  // S21_MATRIX_OOP_H
