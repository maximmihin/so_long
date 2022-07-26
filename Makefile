NAME = so_long
NAME_BONUS = so_long_bonus

HEADER = include/so_long.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC_SHARED = src/parser.c \
			src/map_validation.c \
			src/map_validation_utils.c \
			src/error.c \
			src/render_map.c \
			src/init_all_textures.c \
			src/init_textures_utils.c \
			src/key_press_processing.c \
			src/init_map_objects.c \
			src/init_render_data_utils.c \
			src/init_map_object_utils.c \
			src/appoint_textures.c \
			src/filling_map.c \
			src/init_textures.c \
			src/move_config_utils.c \
			src/main_loop_x.c \
			src/main_loop_event.c \
			src/main_loop_mod_utils.c \
			src/main_loop_print_list.c \
			src/enemies_mod_utils.c \
			src/main_loop_event_utils.c \
			src/minus_collectibles_first.c \
			src/parser_utils.c \

SRC_COMMON = src/main.c src/print_moves.c

SRC_BONUS = bonus/main_bonus.c bonus/print_moves_bonus.c



OBJ_SHARED = $(SRC_SHARED:%.c= %.o)

OBJ_COMMON = $(SRC_COMMON:%.c= %.o)

OBJ_BONUS = $(SRC_BONUS:%.c= %.o)

.PHONY : all bonus clean fclean re

all : $(NAME)

$(NAME) : $(OBJ_COMMON) $(OBJ_SHARED) $(HEADER)
	@cd libs/libft && make bonus && make
	@cd libs/MinilibX && make
	$(CC) $(OBJ_COMMON) $(OBJ_SHARED) libs/libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
#
bonus	: $(NAME_BONUS)

$(NAME_BONUS)	: $(OBJ_BONUS) $(OBJ_SHARED) $(HEADER)
	@cd libs/libft && make bonus && make
	@cd libs/MinilibX && make
	$(CC) $(OBJ_BONUS) $(OBJ_SHARED) libs/libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

%.o	: %.c $(HEADER)
	@$(CC) $(FLAGS) -Imlx -c $< -o $@

clean	:
	@cd libs/libft && make clean
	@cd libs/MinilibX && make clean
	@rm -f $(OBJ_COMMON) $(OBJ_SHARED) $(OBJ_BONUS)

fclean	:	clean
	@cd libs/libft && make fclean
	@cd libs/MinilibX && make clean
	@$(RM) $(NAME) $(NAME_BONUS)

re	:	fclean all