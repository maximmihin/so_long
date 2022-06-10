#include "../include/so_long.h"

int	win_kill(int keycode, t_render_data *render_data)
{
	if (keycode == 0)
		ft_putstr_fd("\nYou are Exit!\n",1);
	if (keycode == 1)
		ft_putstr_fd("\nYou won!\n", 1);
	if (keycode == 2)
		ft_putstr_fd("\nYou lose!\n", 1);
	keycode = render_data->y_length;
	exit(0);
}

int	x_get_move_dir(int keycode)
{
	int move_dir;

	move_dir = 9;
	if (keycode == KEY_W || keycode == ARROW_UP)
		move_dir = 0;
	else if (keycode == KEY_A || keycode == ARROW_LEFT)
		move_dir = 1;
	else if (keycode == KEY_S || keycode == ARROW_DOWN)
		move_dir = 2;
	else if (keycode == KEY_D || keycode == ARROW_RIGHT)
		move_dir = 3;
	return (move_dir);
}

int	is_move_possible5(t_map_object ****map, t_coordinates target_pos)
{
	if (map[target_pos.y][target_pos.x][0]->type == '1')
		return (0);
	return (1);
}

void	*x_get_texture_player(int move_dir, t_render_data *render_data)
{
	return (render_data->image_textures.player_x[move_dir]);
}

int	key_press_processing_x(int keycode, t_render_data *render_data)
{
	int				x_move_dir;
	t_coordinates	tmp_target_pos;

	if (keycode == ESC)
		win_kill(0, render_data);
	x_move_dir = x_get_move_dir(keycode);
	if (x_move_dir == 9)
		return (0);
	if (render_data->player_freez)
		return (0);
	tmp_target_pos = x_get_target_pos(render_data->player_x->x_current_map_pos,
									  x_move_dir);
	if (!is_move_possible5(render_data->map_new, tmp_target_pos))
		return (0);
	render_data->player_freez = 1;
	render_data->player_speed = PLAYER_ANIMATION_STEPS - 1;
	render_data->player_x->x_texture = x_get_texture_player
			(x_move_dir, render_data);
	render_data->player_x->x_target_map_pos = tmp_target_pos;
	render_data->player_x->move_dir = x_move_dir;
	render_data->map_new[tmp_target_pos.y][tmp_target_pos.x][2] =
			render_data->player_x;
	config_shift_texture(&render_data->player_x, x_move_dir);
	*render_data->player_x->ptr_shift_coord += render_data->player_x->shift_value;
	return (0);
}



