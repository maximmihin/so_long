#include "../include/so_long.h"

t_map_data	find_player_position(t_map_data map_data)
{
	map_data.player_x = 0;
	map_data.player_y = 0;
	while (map_data.map[map_data.player_x])
	{
		while (map_data.map[map_data.player_x][map_data.player_y])
		{
			if (map_data.map[map_data.player_x][map_data.player_y] == 'P')
				return (map_data);
			map_data.player_y++;
		}
		map_data.player_x++;
		map_data.player_y = 0;
	}
	map_data.player_x = 0;
	map_data.player_y = 0;
	return (map_data);
}

t_map_data	find_map_size(t_map_data map_data)
{
	map_data.map_height = 0;
	map_data.map_width = 0;
	while (map_data.map[0][map_data.map_width])
		map_data.map_width++;
	while (map_data.map[map_data.map_height])
		map_data.map_height++;
	return (map_data);
}

t_map_data	find_num_collectibles(t_map_data map_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map_data.collectibles = 0;
	while (map_data.map[i])
	{
		while (map_data.map[i][j])
		{
			if (map_data.map[i][j] == 'C')
				map_data.collectibles++;
			j++;
		}
		i++;
		j = 0;
	}
	return (map_data);
}

t_map_data	extract_map_data(t_map_data map_data)
{
	map_data = find_player_position(map_data);
	if (map_data.player_x == 0 && map_data.player_y == 0)
		error1("Error : player position not found\n");
	map_data =	find_map_size(map_data);
	if (map_data.map_height == 0 && map_data.map_width == 0)
		error1("Error : map size not found\n");
	map_data = find_num_collectibles(map_data);
	if (map_data.collectibles == 0)
		error1("Error : required components not found (Collectibles)\n");
	return (map_data);
}
