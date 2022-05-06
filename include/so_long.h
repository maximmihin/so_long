#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include "../libft/libft.h"

# ifndef BUFF_SIZE
#  define BUFF_SIZE 42
# endif

#define SCALE 150
#define EMPTY_SPACE "../textures/empty_space.xpm"
#define WALL "../textures/wall.xpm"
#define COLLECTIBLE "../textures/collectible.xpm"
#define EXIT "../textures/exit.xpm"
#define PLAYER "../textures/player.xpm"

typedef struct s_map_data
{
	char	**map;
	int 	player_x;
	int 	player_y;
	int 	map_height;
	int 	map_width;
	int		collectibles;
}	t_map_data;

typedef struct s_image_textures
{
	void	*empty_space;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player;
}	t_image_textures;

typedef struct s_render_data
{
	void				*mlx;
	void				*mlx_win;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	t_image_textures	image_textures;
}	t_render_data;




void	error1(char *str);

char		**map_parser(char *map_file);
void		map_validation(char const **map);
t_map_data	extract_map_data(t_map_data map_data);

t_image_textures	init_textures(void	*mlx);
void 				render_map(void *mlx, void *mlx_win, char **map,
								t_image_textures image_textures);

#endif
