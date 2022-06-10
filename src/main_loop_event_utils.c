#include "../include/so_long.h"

/// TODO more 25 lines
void	minus_collectibles(t_list **collectibles_addresses,
							unsigned int to_x, unsigned int to_y)
{
	t_list			*tmp_coll_address;
	t_list			*tmp;
	t_coordinates	tmp_coord;

	tmp_coll_address = *collectibles_addresses;
	tmp_coord = ((t_map_object *)tmp_coll_address->content)->x_current_map_pos;
	if (tmp_coord.x == to_x && tmp_coord.y == to_y)
	{
		*collectibles_addresses = (*collectibles_addresses)->next;
		free(tmp_coll_address->content);
		free(tmp_coll_address);
	}
	else
	{
		while (tmp_coll_address->next)
		{
			tmp_coord = ((t_map_object *)tmp_coll_address->next->content)
				->x_current_map_pos;
			if (tmp_coord.x == to_x && tmp_coord.y == to_y)
			{
				free(tmp_coll_address->next->content);
				tmp = tmp_coll_address->next->next;
				free(tmp_coll_address->next);
				tmp_coll_address->next = tmp;
				return ;
			}
			tmp_coll_address = tmp_coll_address->next;
		}
	}
}

void	processing_collectibles(t_render_data *render_data)
{
	t_coordinates	tmp_coord;

	tmp_coord = render_data->player->x_current_map_pos;
	if (render_data->map[tmp_coord.y][tmp_coord.x][1]
		&& render_data->map[tmp_coord.y][tmp_coord.x][1]->type == 'C')
	{
		minus_collectibles(&render_data->collectibles_x,
			tmp_coord.x, tmp_coord.y);
		render_data->map[tmp_coord.y][tmp_coord.x][1] = NULL;
	}
}

void	open_exits(t_render_data *render_data)
{
	t_map_object	*tmp_map_obj;
	t_list			**list;
	t_list			*tmp_list;

	list = &render_data->exits_x;
	while (*list)
	{
		tmp_list = (*list)->next;
		tmp_map_obj = (*list)->content;
		tmp_map_obj->x_texture = tmp_map_obj->x_texture->next;
		mlx_put_image_to_window(render_data->mlx, render_data->mlx_win,
			tmp_map_obj->x_texture->content,
			tmp_map_obj->x_windows_pos.x,
			tmp_map_obj->x_windows_pos.y);
		free(*list);
		(*list) = tmp_list;
	}
}

void	processing_exits(t_render_data *render_data)
{
	t_coordinates	tmp_coord;

	tmp_coord = render_data->player->x_current_map_pos;
	if (render_data->collectibles_x)
		return ;
	if (render_data->exits_x
		&& ((t_map_object *)render_data->exits_x->content)->x_texture->next)
		open_exits(render_data);
	else if (render_data->map[tmp_coord.y][tmp_coord.x][1]
		&& render_data->map[tmp_coord.y][tmp_coord.x][1]->type == 'E')
		win_kill(1, render_data);
}

void	update_current_pos_enemies(t_list *enemies_x, t_map_object ****map)
{
	t_coordinates	tmp_coord;

	while (enemies_x)
	{
		if (((t_map_object *)enemies_x->content)->move_dir != -1)
		{
			tmp_coord = ((t_map_object *)enemies_x->content)->x_current_map_pos;
			map[tmp_coord.y][tmp_coord.x][3] = NULL;
			tmp_coord = ((t_map_object *)enemies_x->content)->x_target_map_pos;
			((t_map_object *)enemies_x->content)->x_current_map_pos = tmp_coord;
		}
		enemies_x = enemies_x->next;
	}
}
