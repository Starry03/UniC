#include "Dictionary.h"
#include "HashFunctions.h"
#include "Matrix.h"
#include "Utils.h"
#include <stdio.h>


int main() {
    Matrix matrix = MatrixInit(4, 4);
    Matrix_Fill(matrix, 1, 1, 1);

    Dictionary dict = Dictionary_Create(100);
    Dictionary_Add(&dict, matrix, CreateInt(5), "struct");
    int mat = Dictionary_GetInt(Dictionary_Get(dict, matrix, "struct"));
    printf("%d\n", mat);

    return 0;
}
