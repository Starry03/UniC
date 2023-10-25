//
// Created by andre on 4/21/2023.
//

#include "Matrix.h"

#include "DataStructures/Array/Arrays.h"
#include <stdio.h>
#include <stdlib.h>

#define SQUARE_ERROR "Matrix is not square"
#define TWOBTWO_ERROR "Matrix is not 2x2"
#define SARRUS_ERROR "Matrix is not 3x3"

static Mat_type *InitRow(size_t len) {
    return (Mat_type *) calloc(len, sizeof(Mat_type));
}

static Mat_type **InitTable(size_t y, size_t x) {
    Mat_type **matrix = (Mat_type **) malloc(y * sizeof(Mat_type *));
    for (size_t i = 0; i < y; i++) matrix[i] = InitRow(x);
    return (matrix);
}

Matrix Matrix_Init(size_t y, size_t x) {
    Matrix matrix = (Matrix) malloc(sizeof(Mat));
    matrix->table = InitTable(y, x);
    matrix->cols = x;
    matrix->rows = y;
    return (matrix);
}

Matrix Identity_matrix(size_t length, Mat_type value) {
    Matrix matrix = Matrix_Init(length, length);
    for (size_t i = 0; i < length; i++)
        for (size_t j = 0; j < length; j++)
            Matrix_SetValue(matrix, KroneckerDelta(i, j) * value, i, j);

    return (matrix);
}

bool KroneckerDelta(size_t i, size_t j) {
    return (i == j);
}

void Matrix_SetValue(Matrix matrix, Mat_type value, size_t y, size_t x) {
    matrix->table[y][x] = value;
}

Mat_type *Matrix_GetRow(Matrix matrix, size_t n) {
    return (matrix->table[n]);
}

Mat_type *Matrix_GetColumn(Matrix matrix, size_t n) {
    Mat_type *arr = InitRow(matrix->rows);
    for (size_t y = 0; y < matrix->rows; y++) {
        arr[y] = matrix->table[y][n];
    }
    return (Mat_type *) arr;
}

Matrix Matrix_Sum(Matrix mat, Matrix mat2) {
    Matrix newMatrix = Matrix_Init(mat->rows, mat->cols);
    if ((mat->rows != mat2->rows) || (mat->cols != mat2->cols)) {
        printf("cannot be summed");
        return (newMatrix);
    }

    for (size_t y = 0; y < mat->rows; y++)
        for (size_t x = 0; x < mat->cols; x++)
            Matrix_SetValue(newMatrix, mat->table[y][x] + mat2->table[y][x], y, x);

    return (newMatrix);
}

Matrix Matrix_ScalarProduct(Matrix mat, Mat_type scalar) {
    Matrix newMatrix = Matrix_Init(mat->rows, mat->cols);
    for (size_t y = 0; y < mat->rows; y++)
        for (size_t x = 0; x < mat->cols; x++)
            Matrix_SetValue(newMatrix, mat->table[y][x] * scalar, y, x);

    return (newMatrix);
}

Matrix MatrixProduct(Matrix mat, Matrix mat2) {
    Matrix newMatrix = Matrix_Init(mat->rows, mat2->cols);
    if (mat->cols != mat2->rows) {
        printf("Cannot be multiplied, incompatible dimensions");
        return (newMatrix);
    }
    for (size_t y = 0; y < mat->rows; y++)
        for (size_t x = 0; x < mat->cols; x++)
            for (size_t k = 0; k < mat->cols; k++)
                newMatrix->table[y][x] += mat->table[y][k] * mat->table[k][x];

    return (newMatrix);
}

// y: index, length: mat->rows
// x: index, length: mat->cols
Matrix Matrix_Suppressed(Matrix mat, size_t y, size_t x) {
    if (mat->rows < 2 && mat->cols < 2) {
        printf("Mat cannot be modified (insufficient size)");
        return (mat);
    }

    if (y >= mat->rows || x >= mat->cols) {
        printf("Mat cannot be modified (out of bounds)");
        return (mat);
    }

    const size_t new_y = mat->rows - 1;
    const size_t new_x = mat->cols - 1;
    size_t x_count = 0, y_count = 0;
    Matrix subMatrix = Matrix_Init(new_y, new_x);
    for (size_t i = 0; i < mat->rows && y_count < new_y; i++) {
        for (size_t j = 0; j < mat->cols; j++) {
            if (i != y && j != x) {
                Matrix_SetValue(subMatrix,
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
    return (subMatrix);
}

Matrix Matrix_Transpose(Matrix mat) {
    Matrix newMatrix = Matrix_Init(mat->cols, mat->rows);
    for (size_t row = 0; row < mat->rows; row++)
        for (size_t col = 0; col < mat->cols; col++)
            Matrix_SetValue(newMatrix, mat->table[row][col], col, row);

    return (newMatrix);
}

Matrix RandomDoubleMatrix(size_t y, size_t x, size_t range, double offset) {
    Matrix matrix = Matrix_Init(y, x);
    for (size_t row = 0; row < matrix->rows; row++)
        matrix->table[row] = RandomDoubleArray(x, range, offset);

    return (matrix);
}

Mat_type Matrix_TwoByTwoDet(Matrix mat) {
    if (mat->rows != 2 || mat->cols != 2) {
        printf("%s \n", TWOBTWO_ERROR);
        exit(EXIT_FAILURE);
    }
    const double mainDiagonal = mat->table[0][0] * mat->table[1][1];
    const double secondaryDiagonal = mat->table[0][1] * mat->table[1][0];
    return (mainDiagonal - secondaryDiagonal);
}

Mat_type Matrix_SarrusDet(Matrix mat) {
    if (mat->rows != 3 || mat->cols != 3) {
        printf("%s\n", SARRUS_ERROR);
        exit(EXIT_FAILURE);
    }
    const Mat_type mainDiagonal = mat->table[0][0] * mat->table[1][1] * mat->table[2][2];
    const Mat_type secondaryDiagonal = mat->table[0][1] * mat->table[1][2] * mat->table[2][0];
    const Mat_type tertiaryDiagonal = mat->table[0][2] * mat->table[1][0] * mat->table[2][1];
    const Mat_type mainDiagonal2 = mat->table[0][2] * mat->table[1][1] * mat->table[2][0];
    const Mat_type secondaryDiagonal2 = mat->table[0][0] * mat->table[1][2] * mat->table[2][1];
    const Mat_type tertiaryDiagonal2 = mat->table[0][1] * mat->table[1][0] * mat->table[2][2];

    return (mainDiagonal + secondaryDiagonal + tertiaryDiagonal - mainDiagonal2 - secondaryDiagonal2 -
            tertiaryDiagonal2);
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"

Mat_type Matrix_LaplaceDet(Matrix mat) {
    if (mat->rows != mat->cols) {
        printf("%s\n", SQUARE_ERROR);
        exit(EXIT_FAILURE);
    }
    if (mat->rows == 2) return (Matrix_TwoByTwoDet(mat));
    if (mat->rows == 3) return (Matrix_SarrusDet(mat));
    Mat_type det = 0;
    for (size_t i = 0; i < mat->rows; i++) {
        Matrix subMatrix = Matrix_Suppressed(mat, 0, i);
        det += mat->table[0][i] * Matrix_LaplaceDet(subMatrix) * (i % 2 == 0 ? 1 : -1);
        Matrix_Free(subMatrix);
    }
    return (det);
}

#pragma clang diagnostic pop

void Matrix_Fill(Matrix matrix, Mat_type value, size_t y0, size_t x0) {
    size_t x0_copy = x0;
    while (y0 < matrix->rows) {
        while (x0 < matrix->cols) {
            Matrix_SetValue(matrix, value, y0, x0);
            x0++;
        }
        y0++;
        x0 = x0_copy;
    }
}

void Matrix_Print(Matrix matrix) {
    printf("Mat:\n");
    for (size_t y = 0; y < matrix->rows; y++) {
        for (size_t x = 0; x < matrix->cols; x++)
            printf("%lf\t", matrix->table[y][x]);

        printf("\n");
    }
}

void Matrix_Free(Matrix matrix) {
    for (size_t i = 0; i < matrix->rows; i++) free(matrix->table[i]);
    free(matrix->table);
    free(matrix);
}

Mat_type Matrix_GetValue(Matrix matrix, size_t y, size_t x) {
    return (matrix->table[y][x]);
}

Matrix Matrix_Inverse(Matrix mat) {
    Matrix newMatrix = Matrix_Init(mat->cols, mat->rows);
    for (size_t i = 0; i < newMatrix->cols; i++)
        for (size_t j = 0; j < newMatrix->rows; j++) {
            Matrix sup = Matrix_Suppressed(mat, i, j);
            Matrix_SetValue(
                    newMatrix,
                    Matrix_LaplaceDet(sup),
                    i,
                    j
            );
            Matrix_Free(sup);
        }
    return (newMatrix);
}
