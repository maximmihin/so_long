#include "../include/so_long.h"

t_image_textures init_textures(void	*mlx)
{
	t_image_textures image_textures;

	image_textures.empty_space = mlx_xpm_file_to_image(mlx,EMPTY_SPACE,0,0);
	image_textures.wall = mlx_xpm_file_to_image(mlx,WALL,0,0);
	image_textures.collectible = mlx_xpm_file_to_image(mlx,COLLECTIBLE,0,0);
	image_textures.exit = mlx_xpm_file_to_image(mlx,EXIT,0,0);
	image_textures.player = mlx_xpm_file_to_image(mlx, PLAYER,0,0);
	return (image_textures);
}

void render_map(void *mlx, void *mlx_win, char **map,
				t_image_textures image_textures)
{
	int	x;
	int	y;
	void	*tmp_texture;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if(map[y][x] == '0')
				tmp_texture = image_textures.empty_space;
			else if (map[y][x] == '1')
				tmp_texture = image_textures.wall;
			else if (map[y][x] == 'C')
				tmp_texture = image_textures.collectible;
			else if (map[y][x] == 'E')
				tmp_texture = image_textures.exit;
			else if (map[y][x] == 'P')
				tmp_texture = image_textures.player;
			mlx_put_image_to_window(mlx, mlx_win, tmp_texture,
										x * SCALE, y * SCALE);
			x++;
		}
		x = 0;
		y++;
	}
}