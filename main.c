#include "NeuralNetwork/CSV.h"

int main() {

    CSV csv = CreateCSV(sizeof(int));
    CSV_ReadFile(csv, fopen("test.csv", "r"), false);



    return 0;
}
