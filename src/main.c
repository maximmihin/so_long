#include "../include/so_long.h"

t_render_data	*init_render_data(char *map_file)
{
	t_render_data	*render_data;
	char			**map_char;

	render_data = (t_render_data *) malloc(sizeof(t_render_data));
	if (!render_data)
		error("Error : failed malloc for render_data\n");
	map_char = map_parser(map_file);
	map_validation((const char **)map_char);
	find_map_size(&render_data->y_length, &render_data->x_length,
		map_char);
	render_data->mlx = mlx_init();
	render_data->image_textures = init_all_textures(render_data->mlx);
	init_map_objects(&render_data, map_char);
	render_data->map = init_map(render_data->y_length,
			render_data->x_length);
	filling_map(render_data, map_char);
	del_map_char(map_char, render_data->y_length);
	render_data->mlx_win = mlx_new_window(render_data->mlx,
			render_data->x_length * SCALE,
			render_data->y_length * SCALE,
			"so_long");
	init_render_counters(render_data);
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
	mlx_loop_hook(render_data->mlx, main_loop_x, render_data);
	mlx_loop(render_data->mlx);
	return (0);
}
