#include "../s21_matrix_oop.h"

bool S21Matrix::operator==(const S21Matrix& other) const {
  return this->EqMatrix(other);
}

S21Matrix S21Matrix::operator*(const double number) const {
  S21Matrix temp(*this);
  temp.MulNumber(number);
  return temp;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix temp(*this);
  temp.MulMatrix(other);
  return temp;
}

bool S21Matrix::operator!=(const S21Matrix other) const {
  return !(this->EqMatrix(other));
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix temp(*this);
  temp.SumMatrix(other);
  return temp;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix temp(*this);
  temp.SubMatrix(other);
  return temp;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  this->SwapMatrix(other);
  return (*this);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
      S21Matrix(other).SwapMatrix(*this);
    } else {
      CopyMatrix(other);
    }
  }

  return (*this);
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(double number) {
  this->MulNumber(number);
  return (*this);
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return (*this);
}

const double& S21Matrix::operator()(int i, int j) const {
  if (i < 0 || i >= rows_) {
    throw std::out_of_range("Index outside the range of rows.");
  }
  if (j < 0 || j >= cols_) {
    throw std::out_of_range("Index outside the range of columns.");
  }

  return (matrix_[i][j]);
}

double& S21Matrix::operator()(int i, int j) {
  if (i < 0 || i >= rows_) {
    throw std::out_of_range("Index outside the range of rows.");
  }
  if (j < 0 || j >= cols_) {
    throw std::out_of_range("Index outside the range of columns.");
  }

  return (matrix_[i][j]);
}