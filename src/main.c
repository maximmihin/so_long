#include "../include/so_long.h"

#include <stdio.h>
void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}


int main(int argc, char **argv)
{
	t_map_data map;

	if (argc != 2)
		error1("Error : num arguments must be 1\n");

	map.map = map_parser(argv[1]);
	map_validation((const char **)map.map);
	print_map(map.map);

	return (0);
}