/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:33:01 by gradagas          #+#    #+#             */
/*   Updated: 2022/06/10 20:33:03 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void			appoint_exits_textures(t_list **all_exits,
					t_render_data *render_data);
void			appoint_collectibles_textures(t_list **all_collectibles,
					t_render_data *render_data);
void			appoint_enemies_textures(t_list **all_enemies,
					t_render_data *render_data);
void			add_obj(t_list **list_objs, char type, unsigned int x,
					unsigned int y);
t_list			*create_list_objs(char **map, char type);
t_coordinates	find_windows_pos(t_coordinates map_pos);

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

t_map_object	*init_player(t_render_data *render_data, char **map_char)
{
	t_map_object	*player;

	player = (t_map_object *) malloc(sizeof(t_map_object));
	if (!player)
		error("Error : failed malloc (player)\n");
	player->type = 'P';
	player->x_current_map_pos = find_player_position(map_char);
	player->x_target_map_pos = player->x_current_map_pos;
	player->x_windows_pos = find_windows_pos(player->x_current_map_pos);
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

void	init_map_objects(t_render_data **render_data, char **map_char)
{
	(*render_data)->space_x = init_space(*render_data);
	(*render_data)->wall_x = init_wall(*render_data);
	(*render_data)->player = init_player(*render_data, map_char);
	(*render_data)->exits_x = create_list_objs(map_char, 'E');
	appoint_exits_textures(&(*render_data)->exits_x, *render_data);
	(*render_data)->collectibles_x = create_list_objs(map_char, 'C');
	appoint_collectibles_textures(&(*render_data)->collectibles_x,
		*render_data);
	(*render_data)->enemies_x = create_list_objs(map_char, 'B');
	appoint_enemies_textures(&(*render_data)->enemies_x, *render_data);
}
