#include "../include/so_long.h"

void	error1(char *str)
{
	write(2, str, ft_strlen(str));
	exit(9);
}
