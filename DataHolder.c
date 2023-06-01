//
// Created by andre on 6/1/2023.
//

#include "DataHolder.h"
#include <stdio.h>

void Dataholder_Print(DataHolder dataHolder) {
    switch (dataHolder->type) {
        case Data_integer:
            printf("%d", *((int *) dataHolder->info));
            break;

        case Data_float:
            printf("%f", *((float *) dataHolder->info));
            break;

        case Data_double:
            printf("%lf", *((double *) dataHolder->info));
            break;

        case Data_char:
            printf("%c", *((char *) dataHolder->info));
            break;

        case Data_string:
            printf("%s", (char *) dataHolder->info);
            break;

        default:
            printf("Unknown type");
            break;
    }
}
