#include "../include/so_long.h"

void	render_counter(t_image_textures image_textures,
					   void *mlx, void *mlx_win)
{
	mlx_put_image_to_window(mlx, mlx_win, image_textures.counter_head, 0, 0);

	mlx_put_image_to_window(mlx, mlx_win, image_textures.counter[0],
							0,SCALE / 2);
	mlx_put_image_to_window(mlx, mlx_win, image_textures.counter[0],
							(SCALE / 4) * 1,SCALE / 2);
	mlx_put_image_to_window(mlx, mlx_win, image_textures.counter[0],
							(SCALE / 4) * 2,SCALE / 2);
	mlx_put_image_to_window(mlx, mlx_win, image_textures.counter[0],
							(SCALE / 4) * 3,SCALE / 2);
}

void	render_sector(t_render_data *render_data, int x, int y)
{
	t_map_object	****map;
	t_map_object	**sector;
	void			*texture_to_print;
	int				lvl;

	map = render_data->map_new;
	sector = map[y][x];
	lvl = 0;
	if (!sector[1])
	{
		texture_to_print = sector[lvl]->x_texture->content;
		mlx_put_image_to_window(render_data->mlx, render_data->mlx_win,
								texture_to_print, x * SCALE, y * SCALE);
	}
	lvl++;
	while (lvl < MAP_LAYERS)
	{
		if (sector[lvl])
		{
			texture_to_print = sector[lvl]->x_texture->content;
			mlx_put_image_to_window(render_data->mlx, render_data->mlx_win,
									texture_to_print, sector[lvl]->x_windows_pos.x,
									sector[lvl]->x_windows_pos.y);
		}
		lvl++;
	}
}

void	render_all(t_render_data *render_data)
{
	unsigned int x;
	unsigned int y;

	x = 0;
	y = 0;
	while (y < render_data->y_length)
	{
		while (x < render_data->x_length)
		{
			render_sector(render_data, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	render_map(t_render_data *render_data)
{
	render_all(render_data);

	render_counter(render_data->image_textures,
				   render_data->mlx, render_data->mlx_win);
}