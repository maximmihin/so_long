/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:38:25 by gradagas          #+#    #+#             */
/*   Updated: 2022/06/10 20:38:29 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_sector(t_render_data *render_data, int x, int y)
{
	t_map_object	****map;
	t_map_object	**sector;
	void			*texture_to_print;
	int				lvl;

	map = render_data->map;
	sector = map[y][x];
	if (!sector[1])
	{
		texture_to_print = sector[0]->x_texture->content;
		mlx_put_image_to_window(render_data->mlx, render_data->mlx_win,
			texture_to_print, x * SCALE, y * SCALE);
	}
	lvl = 1;
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

void	render_map(t_render_data *render_data)
{
	unsigned int	x;
	unsigned int	y;

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
