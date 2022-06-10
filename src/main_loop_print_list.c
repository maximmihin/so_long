#include "../include/so_long.h"

void	render_sector(t_render_data *render_data, int x, int y);

void	add_coordinates_to_print_list(t_list **print_list, t_coordinates *coord)
{
	t_list			*tmp_list;

	tmp_list = ft_lstnew(coord);
	if (!tmp_list)
		error("Error : failed malloc t_list\n");
	ft_lstadd_front(print_list, tmp_list);
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

void	render_list(t_list **to_print, t_render_data *render_data)
{
	t_coordinates	tmp_coord;
	t_list			*tmp_list;

	while (*to_print)
	{
		tmp_list = (*to_print)->next;

		tmp_coord = *((t_coordinates *)(*to_print)->content);
		render_sector(render_data, tmp_coord.x, tmp_coord.y);

		free(*to_print);
		(*to_print) = tmp_list;
	}
}
