NAME = so_long

HEADER = include/so_long.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = src/parser.c \
		src/map_validation.c src/map_validation_utils.c \
		src/errors.c \
		src/main.c

OBJ = $(SRC:%.c= %.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	cd libft && make
	$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)

%.o	: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean	:
	cd libft && make clean
	@rm -f $(OBJ)

fclean	:	clean
	cd libft && make fclean
	@$(RM) $(NAME)

re	:	fclean all