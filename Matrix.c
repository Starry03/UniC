//
// Created by andre on 4/21/2023.
//

#include "Matrix.h"

#include "Arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include "Log.h"

Mat_type *InitRow(int len) {
    return (Mat_type *) AllocateArray(len, sizeof(Mat_type));
}

Mat_type **InitTable(int y, int x) {
    Mat_type **matrix = (Mat_type **) malloc(y * sizeof(Mat_type *));
    for (int i = 0; i < y; i++) matrix[i] = InitRow(x);
    return matrix;
}

Matrix MatrixInit(int y, int x) {
    Matrix matrix = (Matrix ) malloc(sizeof(Mat));
    matrix->table = InitTable(y, x);
    matrix->cols = x;
    matrix->rows = y;
    return matrix;
}

Matrix identity_matrix(int x) {
    Matrix matrix = MatrixInit(x, x);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            MatrixSetValue(matrix, KroneckerDelta(i, j), i, j);
        }
    }
    return matrix;
}

bool KroneckerDelta(int i, int j) {
    return i == j;
}

void MatrixSetValue(Matrix matrix, Mat_type value, int y, int x) {
    matrix->table[y][x] = value;
}

Mat_type *Matrix_GetRow(Matrix matrix, int n) {
    return matrix->table[n];
}

Mat_type *Matrix_GetColumn(Matrix matrix, int n) {
    Mat_type *arr = InitRow(matrix->rows);
    for (int y = 0; y < matrix->rows; y++) {
        arr[y] = matrix->table[y][n];
    }
    return (Mat_type *) arr;
}

Matrix MatrixSum(Matrix mat, Matrix mat2) {
    Matrix newMatrix = MatrixInit(mat->rows, mat->cols);
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

Matrix Matrix_ScalarProduct(Matrix mat, Mat_type scalar) {
    Matrix newMatrix = MatrixInit(mat->rows, mat->cols);
    for (int y = 0; y < mat->rows; y++) {
        for (int x = 0; x < mat->cols; x++) {
            MatrixSetValue(newMatrix, mat->table[y][x] * scalar, y, x);
        }
    }
    return newMatrix;
}

Matrix MatrixProduct(Matrix mat, Matrix mat2) {
    Matrix newMatrix = MatrixInit(mat->rows, mat2->cols);
    if (mat->cols != mat2->rows) {
        Error_Log("Cannot be multiplied, incompatible dimensions");
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

// y: index, length: mat->rows
// x: index, length: mat->cols
Matrix Matrix_Suppressed(Matrix mat, int y, int x) {
    // error handling
    if (mat->rows < 2 && mat->cols < 2) {
        Error_Log("Mat cannot be modified (insufficient size)");
        return mat;
    }

    if (y >= mat->rows || x >= mat->cols) {
        Error_Log("Mat cannot be modified (out of bounds)");
        return mat;
    }

    const int new_y = mat->rows - 1;
    const int new_x = mat->cols - 1;
    int x_count = 0, y_count = 0;
    Matrix subMatrix = MatrixInit(new_y, new_x);
    for (int i = 0; i < mat->rows && y_count < new_y; i++) {
        for (int j = 0; j < mat->cols; j++) {
            if (i != y && j != x) {
                MatrixSetValue(subMatrix,
                               mat->table[i][j],
                               y_count,
                               x_count++);
                // reset x_count
                if (x_count >= new_x) {
                    x_count = 0;
                    y_count++;
                }
            }
        }
    }
    return subMatrix;
}

Matrix Matrix_Transpose(Matrix mat) {
    Matrix newMatrix = MatrixInit(mat->cols, mat->rows);
    for (int y = 0; y < mat->rows; y++) {
        for (int x = 0; x < mat->cols; x++)
            MatrixSetValue(newMatrix, mat->table[y][x], x, y);
    }
    return newMatrix;
}

Matrix RandomMatrix(int y, int x, int range, double offset) {
    Matrix matrix = MatrixInit(y, x);
    for (int row = 0; row < matrix->rows; row++) {
        matrix->table[row] = RandomDoubleArray(x, range, offset);
    }
    return matrix;
}

void Matrix_Fill(Matrix matrix, Mat_type value, int y0, int x0) {
    while (y0 < matrix->rows) {
        while (x0 < matrix->cols) {
            MatrixSetValue(matrix, value, y0, x0);
            x0++;
        }
        y0++;
    }
}


void MatrixPrint(Matrix matrix) {
    printf("Mat:\n");
    for (int y = 0; y < matrix->rows; y++) {
        for (int x = 0; x < matrix->cols; x++) {
            printf("%lf ", matrix->table[y][x]);
        }
        printf("\n");
    }
}

