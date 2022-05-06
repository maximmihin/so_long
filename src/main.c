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
	t_map_data		map_data;
	t_render_data	render_data;

	if (argc != 2)
		error1("Error : num arguments must be 1\n");

	map_data.map = map_parser(argv[1]);
	map_validation((const char **)map_data.map);
	map_data = extract_map_data(map_data);
	print_map(map_data.map);

	render_data.mlx = mlx_init();
	render_data.mlx_win = mlx_new_window(render_data.mlx, SCALE * map_data.map_width,
							 SCALE * map_data.map_height, "so_long");

	render_data.image_textures = init_textures(render_data.mlx);
	render_map(render_data.mlx, render_data.mlx_win, map_data.map,
			   render_data.image_textures);

	mlx_loop(render_data.mlx);

	return (0);
}