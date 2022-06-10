#include "../include/so_long.h"

void	find_map_size(unsigned int *map_height, unsigned int *map_width, char **map)
{
	*map_height = 0;
	*map_width = 0;
	while (map[0][*map_width])
		(*map_width)++;
	while (map[*map_height])
		(*map_height)++;
	if ((*map_width) == 0 && (*map_height) == 0)
		error("Error : map_old size not found\n");
}

t_map_object	****init_map(unsigned int y_length, unsigned int x_length)
{
	t_map_object	****root;
	unsigned int	y;

	y = 0;
	root = (t_map_object ****) malloc(sizeof(t_map_object ***) * y_length);
	if (!root)
		error("Error : malloc (***root) failed\n");
	while (y < y_length)
	{
		root[y] = (t_map_object ***) malloc(sizeof(t_map_object **) *
											x_length);
		if (!root[y])
			error("Error : malloc (root[y]) failed\n");
		y++;
	}
	return (root);
}

void	del_map_char(char **map_char, int y_len)
{
	int y;

	y = 0;
	while (y < y_len)
	{
		free(map_char[y]);
		y++;
	}
	free(map_char);
}

void	init_render_counters(t_render_data *render_data)
{
	render_data->moves = 0;
	render_data->loop_iteration = 0;
	render_data->player_speed = 0;
	render_data->enemy_freez = 0;
	render_data->enemy_animation_steps = 0;
	render_data->collectibles_speed = ANIMATION_SPEED;
}
