# include "Matrix.h"

int main() {
    const int width = 41000;
    const int height = 800;
    Mat *mat = RandomMatrix(width, height, 1, 0);
    MatrixPrint(mat);

    return 0;
}
