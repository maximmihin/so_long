/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:34:58 by gradagas          #+#    #+#             */
/*   Updated: 2022/06/10 20:35:01 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	processing_collectibles(t_render_data *render_data);
void	processing_exits(t_render_data *render_data);
void	update_current_pos_enemies(t_list *enemies_x, t_map_object ****map);

void	event_player_end_move(t_render_data *render_data)
{
	render_data->player->x_current_map_pos
		= render_data->player->x_target_map_pos;
	processing_collectibles(render_data);
	processing_exits(render_data);
	print_moves(render_data);
	render_data->player->move_dir = 10;
}

void	event_enemies_end_move(t_render_data *render_data)
{
	update_current_pos_enemies(render_data->enemies_x, render_data->map);
	render_data->enemy_freez = 0;
}

int	is_player_eaten(t_list *enemies, t_map_object *player)
{
	t_map_object	*tmp_enemy;

	while (enemies)
	{
		tmp_enemy = enemies->content;
		if (player->x_windows_pos.x == tmp_enemy->x_windows_pos.x
			&& player->x_windows_pos.y == tmp_enemy->x_windows_pos.y)
			return (1);
		enemies = enemies->next;
	}
	return (0);
}
