#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include "../libft/libft.h"

# ifndef BUFF_SIZE
#  define BUFF_SIZE 42
# endif

typedef struct s_map_data
{
	char	**map;
	int 	player_x;
	int 	player_y;
	int 	map_height;
	int 	map_width;
	int		collectibles;
}	t_map_data;

void	error1(char *str);

char		**map_parser(char *map_file);
void		map_validation(char const **map);
t_map_data	extract_map_data(t_map_data map_data);

#endif
