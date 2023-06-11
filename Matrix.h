//
// Created by andre on 4/13/2023.
//

#ifndef STARRY_MATRIX_H
#define STARRY_MATRIX_H

#endif //STARRY_MATRIX_H

#include <stdbool.h>

typedef double Mat_type;
typedef struct {
    Mat_type **table;
    int cols;
    int rows;
} Mat;

typedef Mat *Matrix;

Mat_type *InitRow(int len);

Mat_type **InitTable(int y, int x);

Matrix MatrixInit(int y, int x);

Matrix Identity_matrix(int length, Mat_type value);

bool KroneckerDelta(int i, int j);

void MatrixSetValue(Matrix matrix, Mat_type value, int y, int x);

Mat_type *Matrix_GetColumn(Matrix matrix, int n);

Mat_type *Matrix_GetRow(Matrix matrix, int n);

Matrix MatrixSum(Matrix mat, Matrix mat2);

Matrix Matrix_ScalarProduct(Matrix mat, Mat_type scalar);

Matrix MatrixProduct(Matrix mat, Matrix mat2);

Matrix Matrix_Suppressed(Matrix mat, int y, int x);

Matrix Matrix_Transpose(Matrix mat);

Matrix RandomDoubleMatrix(int y, int x, int range, double offset);

Mat_type Matrix_Det(Matrix mat);

void Matrix_Fill(Matrix matrix, Mat_type value, int y0, int x0);

void MatrixPrint(Matrix matrix);
