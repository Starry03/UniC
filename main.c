#include "Dictionary.h"
#include "HashFunctions.h"
#include <stdio.h>

int main() {
    char* pippo = "pippo";
    char *c = "zio pera";
    int p = 3;
    float pi = 3.14f;


    Dictionary dict = Dictionary_Create(10);
    Dictionary_Add(&dict, pippo, c, "str");
    Dictionary_Add(&dict, &p, &pi, "int");

    char* ss = Dictionary_GetString(Dictionary_Get(dict, pippo, "str"));
    float flo = Dictionary_GetFloat(Dictionary_Get(dict, &p, "float"));

    printf("%s\n", ss);
    printf("%f\n", flo);

    return 0;
}
