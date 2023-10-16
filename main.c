#include "Dictionary.h"
#include <stdio.h>
int main() {
    Dictionary dict = Dictionary_Create(10);
    Dictionary_Add(
            dict,
            string("key"),
            int_(1),
            STRING
    );
    printf("%d\n", *(int *) Dictionary_Get(dict, string("key"), STRING));
    Dictionary_Dealloc(dict);
}
