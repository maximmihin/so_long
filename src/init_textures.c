#include "../include/so_long.h"

void	check_size_texture(int x, int y, int width_texture, int height_texture);
void	add_texture(t_list **list_texture, char *path_to_texture, void *mlx);
void	loop_list(t_list **list_texture);
t_list	*get_texture_pack(char *path_to_texture, int num_textures_in_pack,
			void *mlx);

t_image_textures	init_count_textures(void *mlx,
										t_image_textures image_textures)
{
	int		weight_texture;
	int		height_texture;
	int		digit;
	char	*file;
	char	*x_pos;

	image_textures.counter_head = mlx_xpm_file_to_image(mlx,
			COUNTER_HEAD, &weight_texture, &height_texture);
	check_size_texture(weight_texture, height_texture,
		SCALE, SCALE / 2);
	digit = 0;
	file = ft_strdup(COUNTER_X);
	x_pos = ft_strchr(file, 'X');
	while (digit < 10)
	{
		*x_pos = digit + '0';
		image_textures.counter[digit] = mlx_xpm_file_to_image(mlx,
				file, &weight_texture, &height_texture);
		if (!image_textures.counter[digit++])
			error("Error : init counter textures failed\n");
		check_size_texture(weight_texture, height_texture,
			SCALE / 4, SCALE / 2);
	}
	free(file);
	return (image_textures);
}

void	init_collectible_textures(t_image_textures *image_textures,
								int num_texture_pack, void *mlx)
{
	int		index_pack;
	char	*path_to_texture;
	char	*x_pos;

	path_to_texture = ft_strdup(COLLECTIBLE_X_Y);
	x_pos = ft_strchr(path_to_texture, 'X');
	index_pack = 0;
	while (index_pack < num_texture_pack)
	{
		*x_pos = index_pack + '0';
		image_textures->coll_x[index_pack] = get_texture_pack
			(path_to_texture, NUM_TEXTURES_IN_COLLECTIBLES_PACK, mlx);
		index_pack++;
	}
	free (path_to_texture);
}

void	init_player_textures(t_image_textures *image_textures,
							int num_texture_pack, void *mlx)
{
	int		index_pack;
	char	*path_to_texture;
	char	*x_pos;

	path_to_texture = ft_strdup(PLAYER_X_Y);
	x_pos = ft_strchr(path_to_texture, 'X');
	index_pack = 0;
	while (index_pack < num_texture_pack)
	{
		*x_pos = index_pack + '0';
		image_textures->player_x[index_pack] = get_texture_pack
			(path_to_texture, NUM_TEXTURES_IN_PLAYERS_PACK, mlx);
		index_pack++;
	}
	free (path_to_texture);
}

void	init_enemy_textures(t_image_textures *image_textures,
							int num_texture_pack, void *mlx)
{
	int		index_pack;
	char	*path_to_texture;
	char	*x_pos;

	path_to_texture = ft_strdup(ENEMY_X_Y);
	x_pos = ft_strchr(path_to_texture, 'X');
	index_pack = 0;
	while (index_pack < num_texture_pack)
	{
		*x_pos = index_pack + '0';
		image_textures->enemy_x[index_pack] = get_texture_pack
			(path_to_texture, NUM_TEXTURES_IN_ENEMY_PACK, mlx);
		index_pack++;
	}
	free (path_to_texture);
}

void	init_exit_textures(t_image_textures *image_textures, void *mlx)
{
	char	*path_to_texture;

	path_to_texture = ft_strdup(EXIT_0_Y);
	image_textures->exit_x = get_texture_pack
		(path_to_texture, 2, mlx);
	free(path_to_texture);
}
