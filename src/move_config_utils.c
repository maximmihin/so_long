#include "../include/so_long.h"

void	config_shift_texture(t_map_object **map_obj, int move_dir, int shift)
{
	(*map_obj)->shift_value = shift;
	if (move_dir == 0 || move_dir == 1)
		(*map_obj)->shift_value *= -1;
	if (move_dir == 0 || move_dir == 2)
		(*map_obj)->ptr_shift_coord = &((*map_obj)->x_windows_pos.y);
	else if (move_dir == 1 || move_dir == 3)
		(*map_obj)->ptr_shift_coord = &((*map_obj)->x_windows_pos.x);
}

t_coordinates	x_get_target_pos(t_coordinates current_map_pos, int move_dir)
{
	t_coordinates	ret_target_pos;

	ret_target_pos = current_map_pos;
	if (move_dir == 0)
		ret_target_pos.y--;
	else if (move_dir == 1)
		ret_target_pos.x--;
	else if (move_dir == 2)
		ret_target_pos.y++;
	else if (move_dir == 3)
		ret_target_pos.x++;
	return (ret_target_pos);
}
