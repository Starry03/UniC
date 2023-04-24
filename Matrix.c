//
// Created by andre on 4/21/2023.
//

#include "Matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include "Log.h"

Mat_type *InitRow(int size) {
    return (Mat_type *) calloc(size, sizeof(Mat_type));
}

Mat_type **InitTable(int y, int x) {
    Mat_type **matrix = (Mat_type **) malloc(y * sizeof(Mat_type *));
    for (int i = 0; i < y; i++) matrix[i] = InitRow(x);
    return matrix;
}

Matrix *MatrixInit(int y, int x) {
    Matrix *matrix = (Matrix *) malloc(sizeof(Matrix));
    matrix->table = InitTable(y, x);
    matrix->cols = x;
    matrix->rows = y;
    return matrix;
}

void MatrixSetValue(Matrix *matrix, Mat_type value, int y, int x) {
    matrix->table[y][x] = value;
}

Mat_type *Matrix_Row(Matrix *matrix, int n) {
    return matrix->table[n];
}

Mat_type *Matrix_Column(Matrix *matrix, int n) {
    int *arr = InitRow(matrix->rows);
    for (int y = 0; y < matrix->rows; y++) {
        arr[y] = matrix->table[y][n];
    }
    return arr;
}

Matrix *MatrixSum(Matrix *mat, Matrix *mat2) {
    Matrix *newMatrix = MatrixInit(mat->rows, mat->cols);
    if ((mat->rows != mat2->rows) || (mat->cols != mat2->cols)) {
        Error_Log("cannot be summed");
        return newMatrix;
    }
    for (int y = 0; y < mat->rows; y++) {
        for (int x = 0; x < mat->cols; x++) {
            MatrixSetValue(newMatrix, mat->table[y][x] + mat2->table[y][x], y, x);
        }
    }
    return newMatrix;
}

Matrix *MatrixProduct(Matrix *mat, Matrix *mat2) {
    Matrix *newMatrix = MatrixInit(mat->rows, mat2->cols);
    if (mat->cols != mat2->rows) {
        Error_Log("Cannot be multiplied");
        return newMatrix;
    }
    for (int y = 0; y < mat->rows; y++) {
        for (int x = 0; x < mat->cols; x++) {
            for (int k = 0; k < mat->cols; k++) {
                newMatrix->table[y][x] += mat->table[y][k] * mat->table[k][x];
            }
        }
    }
    return newMatrix;
}

void MatrixPrint(Matrix *matrix) {
    printf("Matrix:\n");
    for (int y = 0; y < matrix->rows; y++) {
        for (int x = 0; x < matrix->cols; x++) {
            printf("%d ", matrix->table[y][x]);
        }
        printf("\n");
    }
}

