#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include "../libft/libft.h"

/// del
# include <stdio.h>
# include <time.h>

# ifndef BUFF_SIZE
#  define BUFF_SIZE 42
# endif

# define ENEMY_DENSITY 10
# define MAP_LAYERS 4


# define PLAYER_SHIFT 10

# define SCALE 100

# define PLAYER_FREEZ 250
# define PLAYER_ANIMATION_STEPS 10
# define ANIMATION_SPEED 4000

# define ENEMY_FREEZ 500
# define ENEMY_ANIMATION_STEPS 10


/// change path
# define EMPTY_SPACE "../textures/space/space.xpm"
# define WALL "../textures/wall/wall.xpm"


# define PLAYER_X_Y "../textures/player/X/Y.xpm"
# define COLLECTIBLE_X_Y "../textures/collectible/X/Y.xpm"
# define ENEMY_X_Y "../textures/enemy/X/Y.xpm"

# define EXIT_0_Y "../textures/exit/0/Y.xpm"


# define NUMBER_OF_SPRITES 5

# define NUM_COLL_TEXTURES_PACK 3
# define NUM_PLAYER_TEXTURES_PACK 4
# define NUM_ENEMY_TEXTURES_PACK 4

# define NUM_TEXTURES_IN_PLAYERS_PACK 1
# define NUM_TEXTURES_IN_COLLECTIBLES_PACK 4
# define NUM_TEXTURES_IN_ENEMY_PACK 1

# define COUNTER_HEAD "../textures/steps_counter/counter_head.xpm"

# define COUNTER_X "../textures/steps_counter/X.xpm"



typedef struct s_coordinates
{
	unsigned int	x;
	unsigned int	y;
}	t_coordinates;

typedef struct s_image_textures
{
	t_list	*coll_x[NUM_COLL_TEXTURES_PACK];
	t_list	*player_x[NUM_PLAYER_TEXTURES_PACK];
	t_list	*enemy_x[NUM_ENEMY_TEXTURES_PACK];

	t_list 	*wall_x;
	t_list	*exit_x;
	t_list	*space_x;

	void	*space_h;
	void	*space_v;
	void	*counter_head;
	void	*counter[10];
}	t_image_textures;

typedef struct s_map_object
{
	char			type;
	t_coordinates	x_current_map_pos;
	t_coordinates	x_target_map_pos;

	t_coordinates	x_windows_pos;

	t_list			*x_texture;

	int 			move_dir;
	unsigned int	*ptr_shift_coord;
	int 			shift_value;
}	t_map_object;

typedef struct s_render_data
{
	char				**map_old;
	t_map_object		****map_new;
	unsigned int 		y_length;
	unsigned int 		x_length;

	void				*mlx;
	void				*mlx_win;
	t_image_textures	image_textures;

	unsigned int		moves;
	unsigned int		loop_iteration;

	unsigned int		player_freez;
	unsigned int		player_speed;

	unsigned int		enemy_freez;
	unsigned int		enemy_animation_steps;

	unsigned int		collectibles_speed;


	t_map_object		*space_x;
	t_map_object		*wall_x;
	t_map_object		*player_x;

	t_list				*exits_x;
	t_list				*collectibles_x;
	t_list				*enemies_x;

}	t_render_data;

enum
{
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	ARROW_UP = 126,
	ARROW_LEFT = 123,
	ARROW_DOWN = 125,
	ARROW_RIGHT = 124,
	ESC = 53
};


void	error(char *error_message);

char		**map_parser(char *map_file);
void		map_validation(char const **map);
void		extract_map_data(t_render_data *render_data);

t_image_textures	init_all_textures(void	*mlx);
void 				render_map2(t_render_data *render_data);




void	render_map(t_render_data *render_data);
int		key_press_processing_x(int keycode, t_render_data *render_data);
int		main_loop_x(t_render_data *render_data);



void	find_map_size(unsigned int *map_height, unsigned int *map_width,
					  char **map);
void	init_map_objects(t_render_data **render_data, char **map_char);
t_map_object	****init_map(unsigned int y_length, unsigned int x_length);
void			filling_map(t_render_data *render_data, char **map_char);
void	del_map_char(char **map_char, int y_len);
void	init_render_counters(t_render_data *render_data);


int	win_kill(int keycode, t_render_data *render_data);

t_coordinates	x_get_target_pos(t_coordinates current_map_pos, int move_dir);
void	config_shift_texture(t_map_object **map_obj, int move_dir);

void	print_moves(t_render_data *render_data);




#endif
