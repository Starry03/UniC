//
// Created by andre on 10/23/2023.
//

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc != 2) return (0);
    char buf;
    int n;
    FILE *file = fopen(argv[1], "r");
    if (!file) return (1);
    printf("File: %s\n\n", argv[1]);
    while ((n = fgetc(file)) != EOF) {
        buf = (char) n;
        write(1, &buf, 1);
    }
    fclose(file);
    printf("\n\nFile end");
    return (0);
}