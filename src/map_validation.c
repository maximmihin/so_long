#include "../include/so_long.h"

size_t	arrlen(void const **arr);

static void	check_invalid_symbols(char const **map)
{
	int	i;
	int	j;

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

static void	check_rectangle(char const **map)
{
	int		i;
	size_t	len;
	size_t	tmp_len;
	size_t	lines_num;

	lines_num = arrlen((void const **)map);
	if (lines_num < 3)
		error1("Error : the map is not rectangle\n");
	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		tmp_len = ft_strlen(map[i]);
		if (tmp_len != len)
			error1("Error : the map is not rectangle\n");
		i++;
	}
}

static void	check_closed_perimeter(char const **map)
{
	int		i;
	int		j;
	size_t	last_line;
	size_t	last_elem;

	j = 0;
	last_line = arrlen((void const **)map) - 1;
	last_elem = ft_strlen(map[0]) - 1;
	while (map[0][j])
	{
		if (map[0][j] != '1' || map[last_line][j] != '1')
			error1("Error : the map does not have a closed perimeter\n");
		j++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][last_elem] != '1')
			error1("Error : the map does not have a closed perimeter\n");
		i++;
	}
}

static void	check_valid_symbols(char const **map)
{
	int	i;
	int	j;
	int	arr[3];

	i = 0;
	j = 0;
	ft_memset(&arr, 0, 3);
	while (map[i] && map[i][j])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				arr[0]++;
			else if (map[i][j] == 'E')
				arr[1]++;
			else if (map[i][j] == 'P')
				arr[2]++;
			j++;
		}
		j = 0;
		i++;
	}
	if (arr[0] == 0 || arr[1] == 0 || arr[2] == 0)
		error1("Error : required components not found\n");
}

void	map_validation(char const **map)
{
	check_invalid_symbols(map);
	check_rectangle(map);
	check_closed_perimeter(map);
	check_valid_symbols(map);
}
