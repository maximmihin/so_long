#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../libft/libft.h"

# ifndef BUFF_SIZE
#  define BUFF_SIZE 42
# endif

typedef struct s_map
{
	char	**map;
}	t_map;

void	error1(char *str);

char	**map_parser(char *map_file);
int		is_map_valid(static char **map);

#endif
