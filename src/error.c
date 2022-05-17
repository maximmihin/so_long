#include "../include/so_long.h"

void	error(char *error_message)
{
	write(2, error_message, ft_strlen(error_message));
	exit(9);
}
