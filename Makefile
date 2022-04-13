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
	@cd libs/libft && make
	@cd libs/MinilibX && make
	@$(CC) $(OBJ) libs/libft/libft.a libs/MinilibX/libmlx.a -o $(NAME) -framework OpenGL -framework AppKit

%.o	: %.c $(HEADER)
	@$(CC) $(FLAGS) -Imlx -c $< -o $@

clean	:
	@cd libs/libft && make clean
	@rm -f $(OBJ)

fclean	:	clean
	@cd libs/libft && make fclean
	@cd libs/MinilibX && make clean
	@$(RM) $(NAME)

re	:	fclean all