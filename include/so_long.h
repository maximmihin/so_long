#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../libft/libft.h"

# ifndef BUFF_SIZE
#  define BUFF_SIZE 42
# endif

typedef struct s_map_data
{
	char	**map;
}	t_map_data;

void	error1(char *str);

char	**map_parser(char *map_file);
void	map_validation(char const **map);

#endif
