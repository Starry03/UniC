#include "comparators.h"
#include <string.h>
#include <stdint.h>

int	Compare_String(Generic a, Generic b)
{
	if (!b && !a)
		return (0);
	if (!a)
		return (-1);
	if (!b)
		return (1);
	return (strcmp((char *)a, (char *)b));
}

int	Compare_Int(Generic a, Generic b)
{
	if (!b && !a)
		return (0);
	if (!a)
		return (-1);
	if (!b)
		return (1);
	return (*(int *)a - *(int *)b);
}

int	Compare_Uint64(Generic a, Generic b)
{
	if (!b && !a)
		return (0);
	if (!a)
		return (-1);
	if (!b)
		return (1);
	return (*(uint64_t *)a - *(uint64_t *)b);
}
