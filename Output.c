//
// Created by andre on 10/1/2023.
//

#include "Output.h"

#include <unistd.h>
#include <stdlib.h>

void print_char(char c) {
    write(STDOUT, &c, MAX_CHAR_COUNT);
}

void print_string(char *s) {
    size_t i = 0;
    while (s[i])
        print_char(s[i++]);
}

void print_int(int i) {
    const int base = 10;
    char *buffer;
    int temp = i;
    size_t order = 0;
    while (temp > 0) {
        temp /= base;
        order++;
    }
    buffer = (char *) malloc((order + 1) * sizeof(char));
    while (order - 1> 0) {
        buffer[order - 1] = (char) (i % base + '0');
        i /= base;
        order--;
    }
    print_string(buffer);
    free(buffer);
}

void print_float(float f) {
    print_int((int) f);
    print_char('.');
    const int rational_part = (int) (f * N_DECIMAL_PLACES) % N_DECIMAL_PLACES;
    print_int(rational_part);
}