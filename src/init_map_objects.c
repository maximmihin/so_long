#include "../include/so_long.h"


t_coordinates	find_player_position(char **map)
{
	t_coordinates	player_pos;

	player_pos.x = 1;
	player_pos.y = 1;
	while (map[player_pos.y])
	{
		while (map[player_pos.y][player_pos.x])
		{
			if (map[player_pos.y][player_pos.x] == 'P')
				return (player_pos);
			player_pos.x++;
		}
		player_pos.y++;
		player_pos.x = 1;
	}
	return (player_pos);
}

t_coordinates	find_windows_pos(t_coordinates map_pos)
{
	t_coordinates	windows_pos;

	windows_pos.x = map_pos.x * SCALE;
	windows_pos.y = map_pos.y * SCALE;
	return (windows_pos);
}

t_map_object	*init_player(t_render_data *render_data, char **map_char)
{
	t_map_object	*player;

	player = (t_map_object *) malloc(sizeof(t_map_object));
	if (!player)
		error("Error : failed malloc (player)\n");
	/// type
	player->type = 'P';
	/// x_current_map_pos
	player->x_current_map_pos = find_player_position(map_char);
	/// x_target_map_pos
	player->x_target_map_pos = player->x_current_map_pos;
	/// window_pos
	player->x_windows_pos = find_windows_pos(player->x_current_map_pos);
	/// texture
	player->x_texture = render_data->image_textures.player_x[3];
	return (player);
}



t_map_object	*init_space(t_render_data *render_data)
{
	t_map_object	*space;

	space = (t_map_object *) malloc(sizeof(t_map_object));
	if (!space)
		error("Error : failed malloc (space)\n");
	space->type = '0';
	space->x_texture = render_data->image_textures.space_x;
	return (space);
}

t_map_object	*init_wall(t_render_data *render_data)
{
	t_map_object	*wall;

	wall = (t_map_object *) malloc(sizeof(t_map_object));
	if (!wall)
		error("Error : failed malloc (wall)\n");
	wall->type = '1';
	wall->x_texture = render_data->image_textures.wall_x;
	return (wall);
}


void	add_obj(t_list **list_objs, char type, unsigned int x, unsigned int y)
{
	t_map_object	*map_obj;
	t_list			*tmp_list;

	map_obj = (t_map_object *) malloc(sizeof(t_map_object));
	if (!map_obj)
		error("Error : failed to create list of map_objects\n");
	tmp_list = ft_lstnew(map_obj);
	if (!tmp_list)
		error("Error : failed to create t_list\n");
	map_obj->type = type;
	map_obj->x_current_map_pos.x = x;
	map_obj->x_current_map_pos.y = y;
	map_obj->move_dir = 0;
	map_obj->x_windows_pos = find_windows_pos(map_obj->x_current_map_pos);
	if (*list_objs)
		ft_lstadd_front(list_objs, tmp_list);
	else
		*list_objs = tmp_list;
}

t_list	*create_list_objs(char **map, char type)
{
	t_list			*list_obj;
	unsigned int	y;
	unsigned int	x;

	list_obj = NULL;
	y = 1;
	x = 1;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == type)
				add_obj(&list_obj, type, x, y);
			x++;
		}
		y++;
		x = 1;
	}
	return (list_obj);
}

void	appoint_exits_textures(t_list **all_exits, t_render_data *render_data)
{
	t_map_object	*tmp_obj;
	t_list			*tmp_list;

	tmp_list = *all_exits;
	while(tmp_list)
	{
		tmp_obj = tmp_list->content;
		tmp_obj->x_texture = render_data->image_textures.exit_x;
		tmp_list = tmp_list->next;
	}
}

t_list	*init_exits(t_render_data *render_data, char **map_char)
{
	t_list	*all_exits;

	all_exits = create_list_objs(map_char, 'E');
	appoint_exits_textures(&all_exits, render_data);
	return (all_exits);
}









void	appoint_collectibles_textures(t_list **all_collectibles,
									  t_render_data *render_data)
{
	t_map_object	*tmp_obj;
	t_list			*tmp_list;
	int				i;

	i = 0;
	tmp_list = *all_collectibles;
	while(tmp_list)
	{
		tmp_obj = tmp_list->content;

		tmp_obj->x_texture = render_data->image_textures.coll_x[i];

		i++;
		if (i == NUM_COLL_TEXTURES_PACK)
			i = 0;

		tmp_list = tmp_list->next;
	}
}



t_list	*init_collectibles(t_render_data *render_data, char **map_char)
{
	t_list	*all_collectibles;

	all_collectibles = create_list_objs(map_char, 'C');
	appoint_collectibles_textures(&all_collectibles, render_data);
	return (all_collectibles);
}

void	appoint_enemies_textures(t_list **all_enemies,
								 t_render_data *render_data)
{
	t_map_object	*tmp_obj;
	t_list			*tmp_list;

	tmp_list = *all_enemies;
	while(tmp_list)
	{
		tmp_obj = tmp_list->content;
		tmp_obj->x_texture = render_data->image_textures.enemy_x[0];
		tmp_list = tmp_list->next;
	}
}

t_list	*init_enemies(t_render_data *render_data, char **map_old)
{
	t_list	*all_enemies;

	all_enemies = create_list_objs(map_old, 'B');
	appoint_enemies_textures(&all_enemies, render_data);
	return (all_enemies);
}





void	init_map_objects(t_render_data **render_data, char **map_char)
{
	(*render_data)->space_x = init_space(*render_data);
	(*render_data)->wall_x = init_wall(*render_data);
	(*render_data)->player_x = init_player(*render_data, map_char);
	(*render_data)->exits_x = init_exits(*render_data, map_char);
	(*render_data)->collectibles_x = init_collectibles(*render_data, map_char);
	if (!(*render_data)->collectibles_x)
		error("Error : failed init collectibles\n");
	(*render_data)->enemies_x = init_enemies(*render_data, map_char);
}
