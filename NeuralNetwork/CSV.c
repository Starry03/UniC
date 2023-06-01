//
// Created by andre on 6/1/2023.
//

#include "CSV.h"
#include <stdlib.h>
#include <string.h>
#include "Arrays.h"

CSV CreateCSV(size_t sizeOfContents) {
    CSV csv = (CSV) (malloc(CSV_SIZE));
    csv->cols = 0;
    csv->rows = 0;
    csv->content = AllocateArray(1, 1);
    csv->content_type_size = sizeOfContents;
    return csv;
}

static LinkedList SplitString(char *string, char separator) {
    LinkedList list;
    const size_t stringLength = strlen(string);
    int sizeHelper = 0;
    for (int pointer = 0; pointer < stringLength; pointer++) {
        // found separator
        if (string[pointer] == separator) {
            pointer++; // skip separator
            char *newString = (char *) malloc(pointer - sizeHelper);
            // copy string
            for (int i = sizeHelper; i < pointer; i++) {
                newString[i - sizeHelper] = string[i];
            }
            ListAppend(&list, newString);
            sizeHelper = pointer;
        }
    }
    return list;
}

static void AddContentRow(CSV dest, void *content) {}

void CSV_ReadFile(CSV dest, FILE *file, bool has_header) {
    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    int numberOfElements;
    bool isFirstLine = true;

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        LinkedList splitLine = SplitString(buffer, ',');
        if (isFirstLine) {
            isFirstLine = false;
            numberOfElements = ListLength(splitLine);
            realloc(dest->content, sizeof(void *) * numberOfElements);
            dest->cols = numberOfElements;
        }
        for (int i = 0; i < numberOfElements; i++)
            dest->content[i] = ListGet(splitLine, i);
        dest->rows++;
    }
}
