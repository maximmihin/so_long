#include "../include/so_long.h"

void	player_mod(t_list **to_print, t_render_data *render_data);
void	enemies_mod(t_list **to_print, t_render_data *render_data);
void	collectibles_mod(t_list **to_print, t_render_data *render_data);

void	render_list(t_list **to_print, t_render_data *render_data);

void	event_player_end_move(t_render_data *render_data);
void	event_enemies_end_move(t_render_data *render_data);
int		is_player_eaten(t_list *enemies, t_map_object *player);

int		main_loop_x(t_render_data *render_data)
{
	t_list	*to_print;

	if (render_data->player_freez)
		render_data->player_freez--;
	if (render_data->enemy_freez)
		render_data->enemy_freez--;
	if (render_data->collectibles_speed)
		render_data->collectibles_speed--;

	to_print = NULL;
	/// collectibles
	if (render_data->collectibles_x && !(render_data->collectibles_speed))
		collectibles_mod(&to_print, render_data);
	/// enemies
	if (render_data->enemies_x 	&& !(render_data->enemy_freez))
		enemies_mod(&to_print, render_data);
	/// player
	if (render_data->player_speed && !(render_data->player_freez))
		player_mod(&to_print, render_data);

	/// печать
	render_list(&to_print, render_data);

	/// обработка событий - плеер дошёл
	if (render_data->player_x->move_dir == 9)
		event_player_end_move(render_data);
	/// обработка событий - враг дошёл
	if (render_data->enemy_animation_steps == 0)
		event_enemies_end_move(render_data);
	/// обработка событий - пойман ли игрок
	if (is_player_eaten(render_data->enemies_x, render_data->player_x))
		win_kill(2, render_data);
	return (0);
}