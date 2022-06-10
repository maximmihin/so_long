#include "../include/so_long.h"

void	print_moves(t_render_data *render_data)
{
	render_data->moves++;
	if (render_data->moves == 10000)
		render_data->moves = 0;
	write(1, "\rsteps : ", 9);
	ft_putnbr_fd(render_data->moves, 1);
}
