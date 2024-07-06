#include "../s21_matrix_oop.h"

const double S21Matrix::kEps = 1.0e-6;

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  if (other.rows_ != this->rows_ || other.cols_ != this->cols_) {
    return false;
  }
  for (int i = 0; i < other.rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      if (this->matrix_[i][j] != other.matrix_[i][j]) {
        return false;
      }
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (other.rows_ != this->rows_ || other.cols_ != this->cols_) {
    throw std::invalid_argument("Matrix dimensions must be equal for addition");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      this->matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (other.rows_ != this->rows_ || other.cols_ != this->cols_) {
    throw std::invalid_argument("Matrix dimensions must be equal for addition");
  }
  for (int i = 0; i < other.rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      this->matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j) {
      this->matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (this->cols_ != other.rows_) {
    throw std::invalid_argument("The matrices are incompatible.");
  }

  S21Matrix matrix_mul(this->rows_, other.cols_);

  for (int i = 0; i < matrix_mul.rows_; i++) {
    for (int j = 0; j < matrix_mul.cols_; j++) {
      matrix_mul.matrix_[i][j] = 0;
      for (int k = 0; k < cols_; k++) {
        matrix_mul.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }

  rows_ = matrix_mul.rows_;
  cols_ = matrix_mul.cols_;

  this->Deallocate();
  this->Allocate();

  this->SwapMatrix(matrix_mul);
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix transpose(this->cols_, this->rows_);

  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j) {
      transpose.matrix_[j][i] = this->matrix_[i][j];
    }
  }
  return transpose;
}

S21Matrix S21Matrix::CalcComplements() {
  if (this->rows_ != this->cols_) {
    throw std::invalid_argument("The matrix is not square");
  }
  S21Matrix complements(this->rows_, this->cols_);
  if (rows_ == 1) {
    complements.matrix_[0][0] = 1;
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        double sign = (i + j) % 2 ? -1.0 : 1.0;
        complements(i, j) = sign * this->Minor(i, j).Determinant();
      }
    }
  }
  return complements;
}

double S21Matrix::Determinant() {
  if (this->rows_ != this->cols_) {
    throw std::invalid_argument("The matrix is not square");
  }

  double det = 0.0;
  if (rows_ == 1) {
    det = this->matrix_[0][0];
  } else if (rows_ == 2) {
    det = this->matrix_[0][0] * this->matrix_[1][1] -
          this->matrix_[0][1] * this->matrix_[1][0];
  } else if (rows_ == 3) {
    det = this->matrix_[0][0] * this->matrix_[1][1] * this->matrix_[2][2] -
          this->matrix_[0][0] * this->matrix_[1][2] * this->matrix_[2][1] -
          this->matrix_[0][1] * this->matrix_[1][0] * this->matrix_[2][2] +
          this->matrix_[0][1] * this->matrix_[1][2] * this->matrix_[2][0] +
          this->matrix_[0][2] * this->matrix_[1][0] * this->matrix_[2][1] -
          this->matrix_[0][2] * this->matrix_[1][1] * this->matrix_[2][0];
  } else {
    for (int i = 0; i < cols_; i++) {
      double sign = i % 2 ? -1.0 : 1.0;
      det += sign * this->matrix_[0][i] * this->Minor(0, i).Determinant();
    }
  }
  return det;
}

S21Matrix S21Matrix::Minor(int row, int col) const {
  S21Matrix minor(this->cols_ - 1, this->rows_ - 1);
  for (int i = 0, k = 0; i < this->rows_ - 1; ++i, ++k) {
    for (int j = 0, l = 0; j < this->cols_ - 1; ++j, ++l) {
      if (k == row) {
        ++k;
      }
      if (l == col) {
        ++l;
      }
      minor.matrix_[i][j] = this->matrix_[k][l];
    }
  }
  return minor;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (this->rows_ != this->cols_) {
    throw std::invalid_argument("The matrix is not square");
  }

  double det = this->Determinant();
  if (fabs(det) < kEps) {
    throw std::invalid_argument(
        "The determinant is zero and there is no inverse matrix.");
  }
  det = 1.0 / det;

  return (this->CalcComplements().Transpose() * det);
}