#include "../include/so_long.h"

t_coordinates	find_windows_pos(t_coordinates map_pos)
{
	t_coordinates	windows_pos;

	windows_pos.x = map_pos.x * SCALE;
	windows_pos.y = map_pos.y * SCALE;
	return (windows_pos);
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
