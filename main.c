#include "Dictionary.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Prova{
    char c;
    int n;
}Prova_;
typedef Prova_ *Prova;
int main() {
    Prova p = (Prova) malloc(sizeof(Prova_));
    p->n = 1;

    Dictionary dict = Dictionary_Create(10);
    Dictionary_Add(
            dict,
            p,
            p,
            INT
    );
    Prova res = Dictionary_Get(dict, p, INT);
    Dictionary_Dealloc(dict);
}
