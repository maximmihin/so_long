NAME = so_long

HEADER = include/so_long.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = src/parser.c \
		src/map_validation.c src/map_validation_utils.c \
		src/extract_map_data.c \
		src/errors.c \
		src/main.c

OBJ = $(SRC:%.c= %.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	@cd libft && make
	$(CC) $(OBJ) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o	: %.c $(HEADER)
	@$(CC) $(FLAGS) -Imlx -c $< -o $@

clean	:
	@cd libft && make clean
	@rm -f $(OBJ)

fclean	:	clean
	@cd libs/libft && make fclean
	@$(RM) $(NAME)

re	:	fclean all