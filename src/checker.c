#include "../include/so_long.h"

void	check_invalid_symbols(static char **map)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (map[i] && map[i][j])
	{
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == '1'
				|| map[i][j] == 'C' || map[i][j] == 'E' || map[i][j] == 'P')
				j++;
			else
				error1("Error : the map contains invalid symbols\n");
		}
		j = 0;
		i++;
	}
}

void	check_rectangle(static char **map)
{
	int i;
	int len;
	int tmp_len;

	len = ft_strlen(map[0]);
	///тут надо разбираться, что делать с картой выстой 1, 2
	i = 1;
	while (map[i])
	{
		tmp_len = ft_strlen(map[i]);
		if (tmp_len != len)
			error1("Error : the map is not rectangle\n");
		i++;
	}
}

void	check_closed_perimeter(static char **map)
{
	int i;
	int j;
	int last;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			error1("Error : the map does not have a closed perimeter\n");
		j++;
	}

	i = 1;
	last = ft_strlen(map[i]) - 1;
	while (1)
	{
		if (map[i][0] != '1' || map[i][last] != '1')
			error1("Error : the map does not have a closed perimeter\n")
		///тут надо разбираться, что делать с картой выстой 3, 4
		if (map[i + 1] && map[i + 2] == NULL)
			break;
		i++;
	}

	i++;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			error1("Error : the map does not have a closed perimeter\n");
		j++;
	}

}

void	check_valid_symbols(static char **map)
{
	int	i;
	int j;
	int	C;
	int E;
	int P;

	i = 0;
	j = 0;
	C = 0;
	E = 0;
	P = 0;
	while (map[i] && map[i][j])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				C++;
			else if (map[i][j] == 'E')
				E++;
			else if (map[i][j] == 'P')
				P++;
			j++;
		}
		j = 0;
		i++;
	}
	if (C == 0 || E == 0 || P == 0)
		error1("Error : required components not found\n");
}

int is_map_valid(static char **map)
{
	check_invalid_symbols(map);
	check_rectangle(map);
	check_closed_perimeter(map);
	check_valid_symbols(map);


	return (1);
}