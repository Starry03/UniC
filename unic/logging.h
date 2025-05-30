#pragma once

# include <stddef.h>

typedef enum e_log_type
{
	LOG_INFO,
	LOG_WARNING,
	LOG_ERROR,
	LOG_FATAL
}		t_log_type;

void	logging_log(t_log_type type, const char *message);
void	log_intarray(int *arr, size_t size, size_t new_index);
