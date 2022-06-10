#include "../include/so_long.h"

t_coordinates	x_get_target_pos(t_coordinates current_map_pos, int move_dir);
void			config_shift_texture(t_map_object **map_obj, int move_dir,
					int shift);

int	is_enemy_move_possible(t_map_object ****map, t_coordinates target_pos)
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
	if (is_enemy_move_possible(map, target_pos))
		return (target_pos);
	if ((*enemy)->move_dir == 2)
		(*enemy)->move_dir = 0;
	else
		(*enemy)->move_dir = 2;
	target_pos = x_get_target_pos((*enemy)->x_current_map_pos,
			(*enemy)->move_dir);
	if (!is_enemy_move_possible(map, target_pos))
		(*enemy)->move_dir = -1;
	return (target_pos);
}

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
			config_shift_texture(&tmp_map_obj, tmp_map_obj->move_dir,
				ENEMY_SHIFT);
		}
		enemies = enemies->next;
	}
}

void	shift_enemies(t_list *enemies)
{
	while (enemies)
	{
		if (((t_map_object *)enemies->content)->move_dir != -1)
			*((t_map_object *)enemies->content)->ptr_shift_coord
				+= ((t_map_object *)enemies->content)->shift_value;
		enemies = enemies->next;
	}
}
