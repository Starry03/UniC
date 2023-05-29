//
// Created by andre on 4/13/2023.
//

#ifndef STARRY_MATRIX_H
#define STARRY_MATRIX_H

#endif //STARRY_MATRIX_H

#include <stdbool.h>

typedef int Mat_type;
typedef struct Matrix {
    Mat_type **table;
    int cols;
    int rows;
} Matrix;

int *InitRow(int len);

Mat_type **InitTable(int y, int x);

Matrix *MatrixInit(int y, int x);

Matrix* identity_matrix(int x);

bool KroneckerDelta(int i, int j);

void MatrixSetValue(Matrix *matrix, Mat_type value, int y, int x);

Mat_type *Matrix_Column(Matrix *matrix, int n);

Mat_type *Matrix_Row(Matrix *matrix, int n);

Matrix* MatrixSum(Matrix* mat, Matrix* mat2);

Matrix* Matrix_ScalarProduct(Matrix* mat, Mat_type scalar);

Matrix* MatrixProduct(Matrix* mat, Matrix* mat2);

Matrix* Matrix_Suppressed(Matrix* mat, int y, int x);

void Matrix_Fill(Matrix* matrix, Mat_type value, int y0, int x0);

void MatrixPrint(Matrix *matrix);
