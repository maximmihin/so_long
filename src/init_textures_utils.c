#include "../include/so_long.h"

void	check_size_texture(int x, int y, int width_texture, int height_texture)
{
	if (x != width_texture || y != height_texture)
	{
		error("Error : texture is not square or different size\n");
		win_kill(0, NULL);
	}
}

void	add_texture(t_list **list_texture, char *path_to_texture, void *mlx)
{
	int		width_texture;
	int		height_texture;
	void	*tmp_texture;
	t_list	*tmp_list;

	tmp_texture = mlx_xpm_file_to_image(mlx,
			path_to_texture, &width_texture, &height_texture);
	if (!tmp_texture)
		error("Error : failed xpm to image\n");
	check_size_texture(width_texture, height_texture,
		SCALE, SCALE);
	tmp_list = ft_lstnew(tmp_texture);
	if (!tmp_list)
		error("Error : failed create new t_list\n");
	if (*list_texture == NULL)
		*list_texture = tmp_list;
	else
		ft_lstadd_front(list_texture, tmp_list);
}

void	loop_list(t_list **list_texture)
{
	t_list	*last_list;

	last_list = ft_lstlast(*list_texture);
	last_list->next = *list_texture;
}

t_list	*get_texture_pack(char *path_to_texture, int num_textures_in_pack,
							void *mlx)
{
	t_list	*list_texture;
	char	*y_pos;
	int		index_texture;

	index_texture = 0;
	list_texture = NULL;
	y_pos = ft_strchr(path_to_texture, 'Y');
	while (index_texture < num_textures_in_pack)
	{
		*y_pos = index_texture + '0';
		add_texture(&list_texture, path_to_texture, mlx);
		index_texture++;
	}
	*y_pos = 'Y';
	loop_list(&list_texture);
	return (list_texture);
}
