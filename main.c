#include "Matrix.h"
#include <stdio.h>

int main() {

    Matrix matrix = Identity_matrix(3, 2);
    printf("det: %lf\n", Matrix_Det(matrix));

    return 0;
}
