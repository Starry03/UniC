#pragma once

# include "types.h"
# include <stdbool.h>
# include <stddef.h>

size_t	linear_search(const t_generic *arr, size_t length, t_generic target,
			t_comparator cmp);

size_t	binary_search(const t_generic *arr, size_t length, t_generic target,
			t_comparator cmp);
