#include "../include/so_long.h"

void	render_sector(t_render_data *render_data, int x, int y);
void	render_counter(t_image_textures image_textures,
					   void *mlx, void *mlx_win);

void	xxx_render_coll(t_render_data *render_data)
{
	t_list			*tmp_collectibles_x;
	t_map_object	*tmp_map_obj;

	tmp_collectibles_x = render_data->collectibles_x;

	while (tmp_collectibles_x)
	{
		tmp_map_obj = tmp_collectibles_x->content;
		tmp_map_obj->x_texture = tmp_map_obj->x_texture->next;
		mlx_put_image_to_window(render_data->mlx, render_data->mlx_win,
								tmp_map_obj->x_texture->content,
								tmp_map_obj->x_windows_pos.x,
								tmp_map_obj->x_windows_pos.y);
		tmp_collectibles_x = tmp_collectibles_x->next;
	}
}



void	add_map_obj_to_print_list(t_list **print_list, t_map_object *map_obj)
{
	t_list			*tmp_list;
	t_coordinates	*tmp_coord;

	tmp_coord = &map_obj->x_current_map_pos;
	tmp_list = ft_lstnew(tmp_coord);
	if (!tmp_list)
		error("Error : failed malloc t_list\n");
	ft_lstadd_front(print_list, tmp_list);
}

void	add_coordinates_to_print_list(t_list **print_list, t_coordinates *coord)
{
	t_list			*tmp_list;

	tmp_list = ft_lstnew(coord);
	if (!tmp_list)
		error("Error : failed malloc t_list\n");
	ft_lstadd_front(print_list, tmp_list);
}

void	collectibles_to_print(t_list **print_list, t_list *collectibles)
{
	while (collectibles)
	{
		((t_map_object *)collectibles->content)->x_texture = ((t_map_object *)
				collectibles->content)->x_texture->next;

		add_coordinates_to_print_list(print_list, &((t_map_object *)
		collectibles->content)->x_current_map_pos);

		collectibles = collectibles->next;
	}
}

void	render_list(t_list *to_print, t_render_data *render_data)
{
	t_coordinates	tmp_coord;

	while (to_print)
	{
		tmp_coord = *((t_coordinates *)to_print->content);
		render_sector(render_data, tmp_coord.x, tmp_coord.y);
		to_print = to_print->next;
	}
}

void	clear_list(t_list **list)
{
	t_list	*temp;

	while (*list)
	{
		temp = (*list)->next;
		free(*list);
		(*list) = temp;
	}
}


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
				return;
			}
			tmp_coll_address = tmp_coll_address->next;
		}
	}
}

void	processing_collectibles(t_render_data *render_data)
{
	t_coordinates tmp_coord;

	tmp_coord = render_data->player_x->x_current_map_pos;

	if (render_data->map_new[tmp_coord.y][tmp_coord.x][1]
		&& render_data->map_new[tmp_coord.y][tmp_coord.x][1]->type == 'C')
	{
		minus_collectibles(&render_data->collectibles_x,
						   tmp_coord.x, tmp_coord.y);
		render_data->map_new[tmp_coord.y][tmp_coord.x][1] = NULL;
	}
}

void	open_exits(t_render_data *render_data)
{
	t_map_object	*tmp_map_obj;
	t_list			*tmp_list;

	tmp_list = render_data->exits_x;
	while (tmp_list)
	{
		tmp_map_obj = tmp_list->content;
		tmp_map_obj->x_texture = tmp_map_obj->x_texture->next;
		mlx_put_image_to_window(render_data->mlx, render_data->mlx_win,
								tmp_map_obj->x_texture->content,
								tmp_map_obj->x_windows_pos.x,
								tmp_map_obj->x_windows_pos.y);
		tmp_list = tmp_list->next;
	}
	clear_list(&render_data->exits_x);
}

void	processing_exits(t_render_data *render_data)
{
	t_coordinates tmp_coord;

	tmp_coord = render_data->player_x->x_current_map_pos;

	if (render_data->collectibles_x)
		return;

	if (render_data->exits_x
		&& ((t_map_object *)render_data->exits_x->content)->x_texture->next)
		open_exits(render_data);
	else if (render_data->map_new[tmp_coord.y][tmp_coord.x][1]
			&& render_data->map_new[tmp_coord.y][tmp_coord.x][1]->type == 'E')
		win_kill(1, render_data);
}

void	print_moves(t_render_data *render_data)
{
	render_data->moves++;
	if (render_data->moves == 10000)
	{
		render_data->moves = 0;
		render_counter(render_data->image_textures, render_data->mlx,
					   render_data->mlx_win);
	}
	write(1, "\rsteps : ", 9);
	ft_putnbr_fd(render_data->moves, 1);

	///отрисовка счёта
	int tmp_score;
	int	shift;
	int last_num;

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

t_coordinates	x_get_target_pos(t_coordinates current_map_pos, int move_dir);
int	is_move_possible6(t_map_object ****map, t_coordinates target_pos)
{
	if (map[target_pos.y][target_pos.x][0]->type == '1'
		|| (map[target_pos.y][target_pos.x][3]
			&& map[target_pos.y][target_pos.x][3]->type == 'B'))
		return (0);
	return (1);

}

t_coordinates	get_enemy_target_pos(t_map_object ****map, t_map_object **enemy)
{
	t_coordinates	target_pos;

	target_pos = x_get_target_pos((*enemy)->x_current_map_pos,
								  (*enemy)->move_dir);
	if (is_move_possible6(map, target_pos))
		return (target_pos);

	if ((*enemy)->move_dir == 2)
		(*enemy)->move_dir = 0;
	else // move_dir == 0
		(*enemy)->move_dir = 2;
	target_pos = x_get_target_pos((*enemy)->x_current_map_pos,
								  (*enemy)->move_dir);
	if (!is_move_possible6(map, target_pos))
		(*enemy)->move_dir = -1;
	return (target_pos);
}

void	config_shift_texture(t_map_object **map_obj, int move_dir);

void	configure_enemies_move(t_list *enemies, t_map_object ****map,
								t_image_textures image_textures)
{
	t_map_object	*tmp_map_obj;

	while (enemies)
	{
		tmp_map_obj = enemies->content;
		tmp_map_obj->x_target_map_pos = get_enemy_target_pos
				(map, &tmp_map_obj);
		if (tmp_map_obj->move_dir != -1)
		{
			tmp_map_obj->x_texture = image_textures
					.enemy_x[tmp_map_obj->move_dir];

			map[tmp_map_obj->x_target_map_pos.y]
			[tmp_map_obj->x_target_map_pos.x][3] = tmp_map_obj;

			config_shift_texture(&tmp_map_obj, tmp_map_obj->move_dir);
		}
		enemies = enemies->next;
	}
}

void	shift_enemies(t_list *enemies)
{
//	t_map_object	*tmp_map_obj;

	while (enemies)
	{
//		tmp_map_obj = enemies->content;
//		*tmp_map_obj->ptr_shift_coord += tmp_map_obj->shift_value;
		if (((t_map_object *)enemies->content)->move_dir != -1)
			*((t_map_object *)enemies->content)->ptr_shift_coord +=
				((t_map_object *)enemies->content)->shift_value;

		enemies = enemies->next;
	}

}

void	enemies_to_print(t_list **print_list, t_list *enemies)
{
	while (enemies)
	{
		if (((t_map_object *)enemies->content)->move_dir != -1)
		{
			add_coordinates_to_print_list(print_list, &((t_map_object *)
			enemies->content)->x_current_map_pos);
			add_coordinates_to_print_list(print_list, &((t_map_object *)
			enemies->content)->x_target_map_pos);
		}
		enemies = enemies->next;
	}
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


int	is_player_eated(t_list *enemies, t_map_object *player)
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

int		my_loop_x(t_render_data *render_data)
{
	t_list	*to_print;

	/// плюсование каунтеров
	render_data->loop_iteration++;
	if (render_data->loop_iteration == 10000)
		render_data->loop_iteration = 0;

	if (render_data->player_freez)
		render_data->player_freez--;

	if (render_data->enemy_freez)
		render_data->enemy_freez--;

	if (render_data->collectibles_speed)
		render_data->collectibles_speed--;


	to_print = NULL;

	/// collectibles
	if (render_data->collectibles_x && !(render_data->collectibles_speed))
	{
		collectibles_to_print(&to_print, render_data->collectibles_x);
		render_data->collectibles_speed = ANIMATION_SPEED;
	}

	/// enemies
	if (render_data->enemies_x 	&& !(render_data->enemy_freez))
	{
		if (!(render_data->enemy_speed))
		{
			configure_enemies_move(render_data->enemies_x,
								   render_data->map_new,
								   render_data->image_textures);
			render_data->enemy_freez = 200;
			render_data->enemy_speed = 10;
		}
		shift_enemies(render_data->enemies_x);
		enemies_to_print(&to_print, render_data->enemies_x);

		render_data->enemy_freez = 200;
		render_data->enemy_speed--;
	}

	/// player
	if (render_data->player_speed && !(render_data->player_freez))
	{
		*render_data->player_x->ptr_shift_coord += render_data->player_x
				->shift_value;

		add_coordinates_to_print_list(&to_print,
				&render_data->player_x->x_current_map_pos);
		add_coordinates_to_print_list(&to_print,
				&render_data->player_x->x_target_map_pos);

		render_data->player_speed--;
		if (!render_data->player_speed)
			render_data->player_x->move_dir = 9;

		render_data->player_freez = 50;
	}



	/// печать
	if (to_print)
	{
		render_list(to_print, render_data);
		clear_list(&to_print);
	}

	/// обработка событий - плеер дошёл
	if (render_data->player_x->move_dir == 9)
	{
		render_data->player_x->x_current_map_pos =
		render_data->player_x->x_target_map_pos;
		processing_collectibles(render_data);
		processing_exits(render_data);
		print_moves(render_data);
		render_data->player_x->move_dir = 10;
	}


	if (render_data->enemy_speed == 0)
	{
		update_current_pos_enemies(render_data->enemies_x, render_data->map_new);
		render_data->enemy_freez = 0;
	}

	if (is_player_eated(render_data->enemies_x, render_data->player_x))
		win_kill(2, render_data);


	/// игрок столкнулся с врагом (убить игрока)

	/// враг столкнулся с игроком (убить игрока)


	return (0);
}
