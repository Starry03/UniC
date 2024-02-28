#include <stdio.h>
#include <stdlib.h>

struct data
{
	void *s;
};


int main() {
	struct data *d = malloc(sizeof(struct data));
	void *s = (char *)malloc(10);
	d->s = s;
	free(d->s);
	free(d);
}
