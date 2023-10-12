//
// Created by andre on 10/6/2023.
//


#ifndef STARRY_CLIBRARY_STRINGUTILS_H
#define STARRY_CLIBRARY_STRINGUTILS_H

#include <corecrt.h>
#include <stdbool.h>

typedef char *String;

bool char_null(char c);

bool char_eq(char c1, char c2);

String str_alloc(size_t length);

bool str_eq(String str, String str2);

size_t str_len(String str);

size_t str_cmp(String str, String str2);

size_t str_ncmp(String str, String str2, size_t n);

void str_cpy(String dest, String src, bool terminated);

void str_ncpy(String dest, String src, size_t n, bool terminated);

size_t separator_generated_strings(String str, String sep);

String *split(String str, String sep);

#endif //STARRY_CLIBRARY_STRINGUTILS_H


