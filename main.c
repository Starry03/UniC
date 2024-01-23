#include <stdio.h>

int main() {
	FILE *file = fopen("Tests.h", "r");
	if (!file) {
		printf("File not found");
		return 1;
	}
	printf("%d", file->_file);
	fclose(file);
}
