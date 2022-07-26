/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:32:10 by gradagas          #+#    #+#             */
/*   Updated: 2022/06/10 20:32:11 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_object_on_map(t_map_object *obj, unsigned int lvl,
			t_map_object ****map_new)
{
	int	x;
	int	y;

	x = obj->x_current_map_pos.x;
	y = obj->x_current_map_pos.y;
	map_new[y][x][lvl] = obj;
}

void	put_objects_list_on_map(t_list *obj_list, unsigned int lvl,
			t_map_object ****map_new)
{
	t_list			*tmp_list;

	tmp_list = obj_list;
	while (tmp_list)
	{
		put_object_on_map(tmp_list->content, lvl, map_new);
		tmp_list = tmp_list->next;
	}
}

t_map_object	**get_map_column(t_render_data *render_data, char type,
					int z_length)
{
	t_map_object	**column;
	int				i;

	column = (t_map_object **) malloc(sizeof(t_map_object *) * z_length);
	if (!column)
		error("Error : malloc (column) failed\n");
	if (type == '1')
		column[0] = render_data->wall_x;
	else
		column[0] = render_data->space_x;
	i = 1;
	while (i < z_length)
	{
		column[i] = NULL;
		i++;
	}
	return (column);
}

void	put_base(t_render_data *render_data, char **map_char)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map_char[y])
	{
		while (map_char[y][x])
		{
			render_data->map[y][x] = get_map_column(render_data,
					map_char[y][x], MAP_LAYERS);
			x++;
		}
		x = 0;
		y++;
	}
}

void	filling_map(t_render_data *render_data, char **map_char)
{
	put_base(render_data, map_char);
	put_object_on_map(render_data->player, 2, render_data->map);
	put_objects_list_on_map(render_data->collectibles_x, 1, render_data->map);
	put_objects_list_on_map(render_data->exits_x, 1, render_data->map);
	put_objects_list_on_map(render_data->enemies_x, 3, render_data->map);
}
