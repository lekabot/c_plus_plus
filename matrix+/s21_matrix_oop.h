#ifndef __S21MATRIXOOP_H__
#define __S21MATRIXOOP_H__

#include <math.h>

#include <cstring>
#include <iostream>

class S21Matrix {
 private:
  // Attributes
    int rows_;
    int cols_;
    double** matrix_;  // Pointer to the memory where the matrix is allocated

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

    void create_matrix();
    void delete_matrix();
    void copy_matrix(const S21Matrix& other);
};

#endif