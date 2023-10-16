//
// Created by andre on 4/13/2023.
//

#ifndef STARRY_MATRIX_H
#define STARRY_MATRIX_H

#include <stdbool.h>
#include <stddef.h>

#define SQUARE_ERROR "Matrix is not square"
#define TWOBTWO_ERROR "Matrix is not 2x2"
#define SARRUS_ERROR "Matrix is not 3x3"

typedef double Mat_type;
typedef struct {
    Mat_type **table;
    size_t cols;
    size_t rows;
} Mat;

typedef Mat *Matrix;

Mat_type *InitRow(size_t len);

Mat_type **InitTable(size_t y, size_t x);

Matrix MatrixInit(size_t y, size_t x);

Matrix Identity_matrix(size_t length, Mat_type value);

bool KroneckerDelta(size_t i, size_t j);

void MatrixSetValue(Matrix matrix, Mat_type value, size_t y, size_t x);

Mat_type Matrix_GetValue(Matrix matrix, size_t y, size_t x);

Mat_type *Matrix_GetColumn(Matrix matrix, size_t n);

Mat_type *Matrix_GetRow(Matrix matrix, size_t n);

Matrix MatrixSum(Matrix mat, Matrix mat2);

Matrix Matrix_ScalarProduct(Matrix mat, Mat_type scalar);

Matrix MatrixProduct(Matrix mat, Matrix mat2);

Matrix Matrix_Suppressed(Matrix mat, size_t y, size_t x);

Matrix Matrix_Transpose(Matrix mat);

Matrix RandomDoubleMatrix(size_t y, size_t x, size_t range, double offset);

Mat_type Matrix_TwoByTwoDet(Matrix mat);

Mat_type Matrix_SarrusDet(Matrix mat);

Mat_type Matrix_LaplaceDet(Matrix mat);

void Matrix_Fill(Matrix matrix, Mat_type value, size_t y0, size_t x0);

void MatrixPrsize_t(Matrix matrix);

#endif //STARRY_MATRIX_H
