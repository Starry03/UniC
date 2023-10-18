//
// Created by andre on 10/16/2023.
//

#include "AllocationUtils.h"
#include "StringUtils.h"

#include <stdlib.h>

char *string(char *string) {
    char *new_string = (char *) malloc(str_len(string) * sizeof(char));
    str_cpy(new_string, string, true);
    return (new_string);
}

int *int_(int int_) {
    int *new_int = (int *) malloc(sizeof(int));
    *new_int = int_;
    return (new_int);
}

long long *long_(long long long_) {
    long long *new_long = (long long *) malloc(sizeof(long long));
    *new_long = long_;
    return (new_long);
}

float *float_(float float_) {
    float *new_float = (float *) malloc(sizeof(float));
    *new_float = float_;
    return (new_float);
}

double *double_(double double_) {
    double *new_double = (double *) malloc(sizeof(double));
    *new_double = double_;
    return (new_double);
}

char *char_(char char_) {
    char *new_char = (char *) malloc(sizeof(char));
    *new_char = char_;
    return (new_char);
}
