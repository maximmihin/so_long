/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:38:00 by gradagas          #+#    #+#             */
/*   Updated: 2022/06/10 20:38:14 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_moves(t_render_data *render_data)
{
	render_data->moves++;
	if (render_data->moves == 10000)
		render_data->moves = 0;
	write(1, "\rsteps : ", 9);
	ft_putnbr_fd(render_data->moves, 1);
}
