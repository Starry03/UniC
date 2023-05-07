//
// Created by andre on 5/2/2023.
//

#include "StringFX.h"

unsigned int String_Length(const char *string) {
    unsigned int count = 0;
    while (string[count++] != '\0');
    return count;
}

bool String_Ended(const char ch) {
    return ch == '\0';
}

bool String_Equal(const char *string, const char *other) {
    unsigned int count = 0;
    while (!(String_Ended(string[count]) && String_Ended(other[count]))) {
        if (string[count] != other[count])
            return false;
        count++;
    }
    return true;
}

bool String_Contains(char *string, char *substring) {
    return 0;
}


