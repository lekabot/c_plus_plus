#ifndef __S21_MATRIX_OOP_H__
#define __S21_MATRIX_OOP_H__

#include <math.h>
#include <cstring>
#include <iostream>

class S21Matrix {
 private:
    int rows_;
    int cols_;
    double** matrix_;

 public:
    S21Matrix();   // Default constructor
    S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix &other);
    S21Matrix(S21Matrix&& other);
    ~S21Matrix();  // Destructor

    bool EqMatrix(const S21Matrix& other);
    void SumMatrix(const S21Matrix& other);
    void SubMatrix(const S21Matrix& other);
    void MulNumber(const double num);
    void MulMatrix(const S21Matrix& other);
    S21Matrix Transpose();
    S21Matrix CalcComplements();
    double Determinant();
    S21Matrix InverseMatrix();

   bool operator==(const S21Matrix other) const;
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

    void create_matrix();
    void delete_matrix();
    void copy_matrix(const S21Matrix& other);
};

#endif