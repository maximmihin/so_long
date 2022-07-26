/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:32:22 by gradagas          #+#    #+#             */
/*   Updated: 2022/06/10 20:32:24 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void				check_size_texture(int x, int y, int width_texture,
						int height_texture);
t_image_textures	init_count_textures(void *mlx,
						t_image_textures image_textures);
void				init_collectible_textures(t_image_textures *image_textures,
						int num_texture_pack, void *mlx);
void				init_player_textures(t_image_textures *image_textures,
						int num_texture_pack, void *mlx);
void				init_enemy_textures(t_image_textures *image_textures,
						int num_texture_pack, void *mlx);
void				init_exit_textures(t_image_textures *image_textures,
						void *mlx);

t_image_textures	init_map_textures(void *mlx)
{
	t_image_textures	image_textures;
	void				*tmp_texture;
	int					x;
	int					y;

	tmp_texture = mlx_xpm_file_to_image(mlx,
			EMPTY_SPACE, &x, &y);
	if (!tmp_texture)
		error("Error : failed init texture (empty space)\n");
	check_size_texture(x, y, SCALE, SCALE);
	image_textures.space_x = ft_lstnew(tmp_texture);
	if (!image_textures.space_x)
		error("Error : failed create list texture (empty space)\n");
	tmp_texture = mlx_xpm_file_to_image(mlx,
			WALL, &x, &y);
	if (!tmp_texture)
		error("Error : failed init texture (wall)\n");
	check_size_texture(x, y, SCALE, SCALE);
	image_textures.wall_x = ft_lstnew(tmp_texture);
	if (!image_textures.wall_x)
		error("Error : failed create list texture (wall)\n");
	return (image_textures);
}

t_image_textures	init_all_textures(void	*mlx)
{
	t_image_textures	image_textures;

	image_textures = init_map_textures(mlx);
	image_textures = init_count_textures(mlx, image_textures);
	init_collectible_textures(&image_textures, NUM_COLL_TEXTURES_PACK, mlx);
	init_player_textures(&image_textures, NUM_PLAYER_TEXTURES_PACK, mlx);
	init_enemy_textures(&image_textures, NUM_ENEMY_TEXTURES_PACK, mlx);
	init_exit_textures(&image_textures, mlx);
	return (image_textures);
}
