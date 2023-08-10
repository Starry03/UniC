#include "Dictionary.h"
#include "HashFunctions.h"
#include <stdio.h>

int main() {
    int b = 104;
    int c = 105;
    int d = 106;
    int e = 107;

    Dictionary dict = Dictionary_Create(10, &hashString);
    Dictionary_Add(&dict, "ciao", &b);
    Dictionary_Add(&dict, "pirla", &c);
    Dictionary_Add(&dict, "sium", &d);
    Dictionary_Add(&dict, &e, "ciao");

    void *res = Dictionary_Get(dict, &e, "int");
    char* r = Dictionary_GetString(res);

    printf("res: %s\n", r);

    return 0;
}
