#include "../include/so_long.h"

int main(int argc, char **argv)
{
	t_map map;

	if (argc != 2)
		error1("Error : num arguments must be 1\n");

	map.map = map_parser(argv[1]);
	if (!is_map_valid(map.map))
		error1("Error : map is invalid\n");

	return (0);
}