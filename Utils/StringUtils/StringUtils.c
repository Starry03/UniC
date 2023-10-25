//
// Created by andre on 10/6/2023.
//

#include "StringUtils.h"

#include <stdlib.h>

// O(1)
bool char_null(char c) { return (!c); }

// O(1)
bool char_eq(char c1, char c2) { return (c1 == c2); }

// O(1)
String str_alloc(size_t length) { return (String) (malloc(length)); }

// O(1)
String *str_arr(size_t length) {
    const size_t SIZE = sizeof(String) * length + sizeof(String);
    String *arr = (String *) malloc (SIZE);
    arr[length - 1] = NULL;
    return (arr);
}

/*
 * O(N)
 * N = max_len(str, str2)
*/
bool str_eq(String str, String str2) {
    size_t i = 0;
    while (str[i] && str2[i]) {
        if (str[i] != str2[i]) return (false);
        i++;
    }
    return (true);
}

size_t str_len(String str) {
    size_t len = 0;
    while (str[len]) len++;
    return (len);
}

// O(N)
size_t str_cmp(String str, String str2) {
    size_t i = 0;
    while ((!char_null(str[i]) || !char_null(str2[i]) || char_eq(str[i], str2[i])))
        i++;
    return (size_t) str[i] - str2[i];
}

// O(N)
size_t str_ncmp(String str, String str2, size_t n) {
    size_t i = 0;
    while ((!char_null(str[i]) || !char_null(str2[i]) || char_eq(str[i], str2[i])) && i < n)
        i++;
    return (size_t) (str[i] - str2[i]);
}

// O(N)
void str_cpy(String dest, String src, bool terminated) {
    size_t i = 0;
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    if (terminated) dest[i] = '\0';
}

void str_ncpy(String dest, String src, size_t n, bool terminated) {
    size_t i = 0;
    while (src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (terminated) dest[i] = '\0';
}

// O(N)
size_t separator_generated_strings(String str, String sep) {
    size_t i = 0;
    size_t count = 0;
    const size_t SEP_LEN = str_len(sep);
    bool was_sep = true;

    while (str[i]) {
        if (str_eq(str + i, sep)) {
            i += SEP_LEN;
            was_sep = true;
        } else {
            if (was_sep)
                count++;
            was_sep = false;
            i++;
        }
    }
    return (count);
}

// O()
String *split(String str, String sep) {
    size_t i = 0;
    size_t index = 0;
    size_t left;
    const size_t count_words = separator_generated_strings(str, sep);
    const size_t SEP_LEN = str_len(sep);
    char **arr = str_arr(count_words);

    while (str[i]) {
        if (!str_eq(str + i, sep)) {
            left = i;
            while (!str_eq(str + i, sep))
                i++;
            arr[index] = str_alloc(i - left + 1);
            str_ncpy(arr[index++], str + left, i - left, true);
        } else i += SEP_LEN;
    }
    return (arr);
}