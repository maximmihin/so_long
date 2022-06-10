#include "../include/so_long.h"

void	add_coordinates_to_print_list(t_list **print_list,
			t_coordinates *coord);
void	enemies_to_print(t_list **print_list, t_list *enemies);
void	collectibles_to_print(t_list **print_list, t_list *collectibles);
void	shift_enemies(t_list *enemies);
void	configure_enemies_move(t_list *enemies, t_map_object ****map,
			t_image_textures image_textures);

void	player_mod(t_list **to_print, t_render_data *render_data)
{
	*render_data->player->ptr_shift_coord += render_data->player
		->shift_value;
	add_coordinates_to_print_list(to_print,
		&render_data->player->x_current_map_pos);
	add_coordinates_to_print_list(to_print,
		&render_data->player->x_target_map_pos);
	render_data->player_speed--;
	if (!render_data->player_speed)
		render_data->player->move_dir = 42;
	render_data->player_freez = PLAYER_FREEZ;
}

void	enemies_mod(t_list **to_print, t_render_data *render_data)
{
	if (!(render_data->enemy_animation_steps))
	{
		configure_enemies_move(render_data->enemies_x,
			render_data->map,
			render_data->image_textures);
		render_data->enemy_freez = ENEMY_FREEZ;
		render_data->enemy_animation_steps = ENEMY_ANIMATION_STEPS;
	}
	shift_enemies(render_data->enemies_x);
	enemies_to_print(to_print, render_data->enemies_x);
	render_data->enemy_freez = ENEMY_FREEZ;
	render_data->enemy_animation_steps--;
}

void	collectibles_mod(t_list **to_print, t_render_data *render_data)
{
	collectibles_to_print(to_print, render_data->collectibles_x);
	render_data->collectibles_speed = ANIMATION_SPEED;
}
