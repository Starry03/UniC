//
// Created by andre on 6/1/2023.
//

#ifndef STARRY_CLIBRARY_CSV_H
#define STARRY_CLIBRARY_CSV_H

#endif //STARRY_CLIBRARY_CSV_H

#include <stdio.h>
#include <stdbool.h>
#include "LinkedList.h"

typedef struct {
    int rows;
    int cols;
    void **content;
    size_t content_type_size;
} CSV_;


#define CSV_SIZE 16

typedef CSV_ *CSV;

CSV CreateCSV(size_t sizeOfContents);

static LinkedList SplitString(char *string, char separator);

static void AddContentRow(CSV dest, void *content);

void CSV_ReadFile(CSV dest, FILE *file, bool has_header);
