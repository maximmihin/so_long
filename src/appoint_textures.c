/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appoint_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:31:32 by gradagas          #+#    #+#             */
/*   Updated: 2022/06/10 20:31:35 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	appoint_exits_textures(t_list **all_exits, t_render_data *render_data)
{
	t_map_object	*tmp_obj;
	t_list			*tmp_list;

	tmp_list = *all_exits;
	while (tmp_list)
	{
		tmp_obj = tmp_list->content;
		tmp_obj->x_texture = render_data->image_textures.exit_x;
		tmp_list = tmp_list->next;
	}
}

void	appoint_collectibles_textures(t_list **all_collectibles,
										t_render_data *render_data)
{
	t_map_object	*tmp_obj;
	t_list			*tmp_list;
	int				i;

	i = 0;
	tmp_list = *all_collectibles;
	while (tmp_list)
	{
		tmp_obj = tmp_list->content;
		tmp_obj->x_texture = render_data->image_textures.coll_x[i];
		i++;
		if (i == NUM_COLL_TEXTURES_PACK)
			i = 0;
		tmp_list = tmp_list->next;
	}
}

void	appoint_enemies_textures(t_list **all_enemies,
									t_render_data *render_data)
{
	t_map_object	*tmp_obj;
	t_list			*tmp_list;

	tmp_list = *all_enemies;
	while (tmp_list)
	{
		tmp_obj = tmp_list->content;
		tmp_obj->x_texture = render_data->image_textures.enemy_x[0];
		tmp_list = tmp_list->next;
	}
}
