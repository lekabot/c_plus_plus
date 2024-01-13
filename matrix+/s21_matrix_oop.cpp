#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(3), cols_(3) { create_matrix(); }

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("rows or columns are equal or less 0");
    }
    create_matrix();
}

S21Matrix::S21Matrix(const S21Matrix& other) : rows_(other.rows_), cols_(other.cols_) {
    create_matrix();
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; i < cols_; j++) {
            matrix_[i][j] = other.matrix_[i][j];
        }
    }
}

S21Matrix::S21Matrix(S21Matrix&& other) {
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;
    other.rows_ = 0;
    other.cols_ = 0;
    other.delete_matrix();
}

S21Matrix::~S21Matrix() { this->delete_matrix(); }

void S21Matrix::create_matrix() {
   this->matrix_ = new double*[rows_]();
   for (int i = 0; i < rows_; i++) {
        this->matrix_[i] = new double[cols_]();
   }
}

void S21Matrix::delete_matrix() {
    if (matrix_ != nullptr) {
        for (int i = 0; i < rows_; i++) {
            delete[] matrix_[i];
        }
        delete[] matrix_;
    }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        return false;
    } else {
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols_; j++) {
                if (matrix_[i][j] != other.matrix_[i][j]) {
                    return false;
                }
            }
        }
    }
    return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        throw std::exception();
    }
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] += other.matrix_[i][j];
        }
    }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        throw std::exception();
    }
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] -= other.matrix_[i][j];
        }
    }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = num * matrix_[i][j];
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
    if (cols_ != other.rows_) {
        throw std::exception();
    }

    S21Matrix matrix_mul(rows_, other.cols_);

    for (int i = 0; i < matrix_mul.rows_; i++) {
        for (int y = 0; y < matrix_mul.cols_; y++) {
            matrix_mul.matrix_[i][y] = 0;
            for (int k = 0; k < cols_; k++) {
                matrix_mul.matrix_[i][y] += matrix_[i][k] * other.matrix_[k][y];
            }
        }
    }

    rows_ = matrix_mul.rows_;
    cols_ = matrix_mul.cols_;
    
    delete_matrix();
    create_matrix();

    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] = matrix_mul.matrix_[i][j];
        }
    }
}

S21Matrix S21Matrix::Transpose() {
    S21Matrix res(cols_, rows_);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
        res.matrix_[j][i] = matrix_[i][j];
    }
  }
}

S21Matrix S21Matrix::CalcComplements() {
    if (rows_ != cols_) {
        throw std::exception();
    }
    S21Matrix result(rows_, cols_);
    S21Matrix minor(rows_-1, cols_-1);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            int c1 = 0;
            int c2 = 0;
            for (int x = 0; x < rows_; x++) {
                for (int y = 0; y < cols_; y++) {
                    if (x != i && y != j) {
                        minor.matrix_[c1][c2] = matrix_[x][y];
                        c2++;
                        if (c2 == rows_ - 1) {
                            c2 = 0;
                            c1++;
                        }
                    }
                }
            }
            result.matrix_[i][j] = minor.Determinant();
            if ((i + j) % 2) {
                result.matrix_[i][j] *= -1;
            }
        }
    }
    return result;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::exception();
  }
  double result = 0;
  if (rows_ == 1) {
    result = matrix_[0][0];
  } else {
    if (rows_ == 2) {
      result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
    } else {
      S21Matrix other = this->CalcComplements();
      for (int i = 0; i < cols_; i++) {
        result += matrix_[0][i] * other.matrix_[0][i];
      }
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
    double determinant = this->Determinant();
    if (fabs(determinant) < 1e-7) {
        throw std::exception();
    }
    S21Matrix res = this->Transpose().CalcComplements();
    res.MulNumber(1.0 / determinant);
    return res;
}