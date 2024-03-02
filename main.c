#include <stdio.h>
#include <stdlib.h>
#include "./Utils/Conversion/Conversion.h"

int main() {
	String s = uintToString(8, 32);
	printf("%s\n", s);
	free(s);
}
