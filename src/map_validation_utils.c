#include "../include/so_long.h"

size_t	arrlen(void const **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
