#include "../include/so_long.h"


void	init_map_objects(t_render_data **render_data, char **map_char);


int		key_press_processing_x(int keycode, t_render_data *render_data);
int		my_loop_x(t_render_data *render_data);

int	win_kill(int keycode, t_render_data *render_data)
{
	if (keycode == 0)
		ft_putstr_fd("\nYou are Exit!\n",1);
	if (keycode == 1)
		ft_putstr_fd("\nYou won!\n", 1);
	if (keycode == 2)
		ft_putstr_fd("\nYou lose!\n", 1);

	render_data->loop_iteration = 0;

	exit(0);
}

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


t_map_object	**init_map_column(unsigned int z_length)
{
	t_map_object	**column;
	unsigned int 	i;

	column = (t_map_object **) malloc(sizeof(t_map_object *) *
											  z_length);
	if (!column)
		error("Error : malloc (column) failed\n");

	i = 0;
	while (i < z_length)
	{
		column[i] = NULL;
		i++;
	}
	return (column);
}

t_map_object	****init_map(unsigned int y_length, unsigned int x_length)
{
	t_map_object	****root;
//	int 	x;
	unsigned int		y;

//	x = 0;
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
//		while (x < x_length)
//		{
//			root[y][x] = init_map_column(z_length);
//			x++;
//		}
//		x = 0;
		y++;
	}
	return (root);
}

t_map_object	**get_map_column(t_render_data *render_data, char type,
								 int z_length)
{
	t_map_object	**column;
	int 			i;

	column = (t_map_object **) malloc(sizeof(t_map_object *) *
									  z_length);
	if (!column)
		error("Error : malloc (column) failed\n");
	if (type == '1')
		column[0] = render_data->wall_x;
	else
		column[0] = render_data->space_x;

	i = 1;
	while (i < z_length)
	{
		column[i] = NULL;
		i++;
	}
	return (column);
}

void			put_base(t_render_data *render_data, char **map_char)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map_char[y])
	{
		while (map_char[y][x])
		{
			render_data->map_new[y][x] = get_map_column(render_data,
					map_char[y][x], MAP_LAYERS);
			x++;
		}
		x = 0;
		y++;
	}
}

void put_object_on_map(t_map_object *obj, unsigned int lvl,
					   t_map_object ****map_new)
{
	int 			x;
	int				y;

	x = obj->x_current_map_pos.x;
	y = obj->x_current_map_pos.y;
	map_new[y][x][lvl] = obj;
}

void put_objects_list_on_map(t_list *obj_list, unsigned int lvl,
							 t_map_object ****map_new)
{
	t_list			*tmp_list;

	tmp_list = obj_list;
	while (tmp_list)
	{
//		if (tmp_list->content)
		put_object_on_map(tmp_list->content, lvl, map_new);
		tmp_list = tmp_list->next;
	}
}

void			filling_map(t_render_data *render_data, char **map_char)
{
	put_base(render_data, map_char);

	put_object_on_map(render_data->player_x, 2, render_data->map_new);
	put_objects_list_on_map(render_data->collectibles_x, 1, render_data->map_new);
	put_objects_list_on_map(render_data->exits_x, 1, render_data->map_new);
	put_objects_list_on_map(render_data->enemies_x, 3, render_data->map_new);
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

int find_num_space(char **map_char)
{
	int counter;
	int i;
	int j;

	counter = 0;
	i = 1;
	j = 1;
	while (map_char[i])
	{
		while (map_char[i][j])
		{
			if (map_char[i][j] == '0')
				counter++;
			j++;
		}
		j = 1;
		i++;
	}
	return (counter);
}

void	put_enemies_on_map(char **map_char)
{
//	int space;
	int counter;
	int i;
	int j;

//	space = find_num_space(map_char);

	counter = 0;
	i = 1;
	j = 1;
	while (map_char[i])
	{
		while (map_char[i][j])
		{
			if (map_char[i][j] == '0')
				counter++;
			if (counter > ENEMY_DENSITY)
			{
				map_char[i][j] = 'B';
				counter = 0;
			}
			j++;
		}
		j = 1;
		i++;
	}
}

t_render_data *init_render_data(char *map_file)
{
	t_render_data	*render_data;
	char			**map_char;

	render_data = (t_render_data *) malloc(sizeof(t_render_data));
	if (!render_data)
		error("Error : failed malloc for render_data\n");


	//render_data->map_old = map_parser(map_file);
	map_char = map_parser(map_file);

	//map_validation((const char **)render_data->map_old);
	map_validation((const char **)map_char);


//	find_map_size(&render_data->y_length, &render_data->x_length,
//				  render_data->map_old);
	find_map_size(&render_data->y_length, &render_data->x_length,
				  map_char);

	put_enemies_on_map(map_char);


	render_data->mlx = mlx_init();
	render_data->image_textures = init_textures(render_data->mlx);

	init_map_objects(&render_data, map_char);

	render_data->map_new = init_map(render_data->y_length,
									render_data->x_length);

	filling_map(render_data, map_char);
	del_map_char(map_char, render_data->y_length);

	render_data->mlx_win = mlx_new_window(render_data->mlx,
			render_data->x_length * SCALE,
			render_data->y_length * SCALE,
			"so_long");

	render_data->moves = 0;
	render_data->loop_iteration = 0;
	render_data->player_speed = 0;
	render_data->enemy_freez = 0;
	render_data->enemy_speed = 0;
	render_data->collectibles_speed = ANIMATION_SPEED;
	return (render_data);
}

int	main(int argc, char **argv)
{
	t_render_data	*render_data;

	if (argc != 2)
		error("Error : num arguments must be 1\n");

	render_data = init_render_data(argv[1]);

	render_map(render_data);

	mlx_hook(render_data->mlx_win, 17, 0, win_kill, render_data);
	mlx_hook(render_data->mlx_win, 2, 0, key_press_processing_x, render_data);

	mlx_loop_hook(render_data->mlx, my_loop_x, render_data);

	mlx_loop(render_data->mlx);
	return (0);
}
