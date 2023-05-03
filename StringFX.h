//
// Created by andre on 5/2/2023.
//

#ifndef STARRY_STRINGFX_H
#define STARRY_STRINGFX_H

#endif //STARRY_STRINGFX_H

#include <stdbool.h>

unsigned int String_Length(const char* string);

bool String_Ended(const char ch);

bool String_Equal(const char* string, const char* other);

bool String_Contains(char* string, char* substring);
