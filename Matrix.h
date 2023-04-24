//
// Created by andre on 4/13/2023.
//

#ifndef STARRY_MATRIX_H
#define STARRY_MATRIX_H

#endif //STARRY_MATRIX_H

typedef int Mat_type;
typedef struct Matrix {
    Mat_type **table;
    int cols;
    int rows;
} Matrix;

int *InitRow(int size);

Mat_type **InitTable(int y, int x);

Matrix *MatrixInit(int y, int x);

void MatrixSetValue(Matrix *matrix, Mat_type value, int y, int x);

Mat_type *Matrix_Column(Matrix *matrix, int n);

Mat_type *Matrix_Row(Matrix *matrix, int n);

Matrix* MatrixSum(Matrix* mat, Matrix* mat2);

Matrix* MatrixProduct(Matrix* mat, Matrix* mat2);

void MatrixPrint(Matrix *matrix);
