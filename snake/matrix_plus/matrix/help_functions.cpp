#include "../s21_matrix_oop.h"

void S21Matrix::Allocate() {
  this->matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; ++i) {
    this->matrix_[i] = new double[cols_]();
  }
}

void S21Matrix::Deallocate() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}

void S21Matrix::CopyMatrix(const S21Matrix& other) {
  int min_rows = std::min(this->rows_, other.rows_);
  int min_cols = std::min(this->cols_, other.cols_);

  if (this->cols_ == other.cols_) {
    memcpy(this->matrix_[0], other.matrix_[0],
           min_rows * min_cols * sizeof(this->matrix_[0][0]));
  } else {
    for (int i = 0; i < min_rows; ++i) {
      for (int j = 0; j < min_cols; ++j) {
        this->matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::FillRand() {
  srand(time(nullptr));
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = this->GetRand(0.0, 100.0);
    }
  }
}

double S21Matrix::GetRand(double min, double max) {
  double value = static_cast<double>(rand()) / RAND_MAX;
  return min + value * (max - min);
}

int S21Matrix::GetRows() { return rows_; }

int S21Matrix::GetCols() { return cols_; }

double** S21Matrix::GetMatrix() { return matrix_; }

// void S21Matrix::SetMatrix(int rows, int cols, double value) {
//   this->matrix_[rows][cols] = value;
// }

void S21Matrix::FillMatrix(double value) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = value;
    }
  }
}

// void S21Matrix::PrintMatrix() const {
//   for (int i = 0; i < rows_; ++i) {
//     for (int j = 0; j < cols_; ++j) {
//       std::cout << matrix_[i][j] << " ";
//     }
//     std::cout << std::endl;
//   }
// }

void S21Matrix::SwapMatrix(S21Matrix& other) noexcept {
  std::swap(this->rows_, other.rows_);
  std::swap(this->cols_, other.cols_);
  std::swap(this->matrix_, other.matrix_);
}