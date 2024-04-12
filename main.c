#include "DataStructures/Dictionary/Dictionary.h"

int	main(int argc, char const *argv[])
{
	t_dict	dict;
	int		i;

	// test dictionary
	dict = Dict_Init(10);
	// add 11 elements
	i = 0;
	while (i < 11)
	{
		Dict_Add(&dict, i, i, NULL, NULL);
		i++;
	}
	// print dictionary
	Dict_Status(dict);
	Dict_Free(dict);
	return (0);
}
