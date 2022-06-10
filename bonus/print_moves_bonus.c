/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:38:50 by gradagas          #+#    #+#             */
/*   Updated: 2022/06/10 20:38:54 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_counter(t_image_textures image_textures,
						void *mlx, void *mlx_win)
{
	mlx_put_image_to_window(mlx, mlx_win, image_textures.counter_head, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, image_textures.counter[0],
		0, SCALE / 2);
	mlx_put_image_to_window(mlx, mlx_win, image_textures.counter[0],
		(SCALE / 4) * 1, SCALE / 2);
	mlx_put_image_to_window(mlx, mlx_win, image_textures.counter[0],
		(SCALE / 4) * 2, SCALE / 2);
	mlx_put_image_to_window(mlx, mlx_win, image_textures.counter[0],
		(SCALE / 4) * 3, SCALE / 2);
}

void	print_moves(t_render_data *render_data)
{
	int	tmp_score;
	int	shift;
	int	last_num;

	render_data->moves++;
	if (render_data->moves == 10000)
	{
		render_data->moves = 0;
		render_counter(render_data->image_textures, render_data->mlx,
			render_data->mlx_win);
	}
	tmp_score = render_data->moves;
	shift = 3;
	while (tmp_score != 0)
	{
		last_num = tmp_score % 10;
		mlx_put_image_to_window(render_data->mlx, render_data->mlx_win,
			render_data->image_textures.counter[last_num],
			(SCALE / 4) * shift, SCALE / 2);
		tmp_score /= 10;
		shift--;
	}
}
