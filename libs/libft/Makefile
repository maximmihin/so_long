# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gradagas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/30 20:41:43 by gradagas          #+#    #+#              #
#    Updated: 2021/10/30 20:41:46 by gradagas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

CC = gcc

FLAGS = -Wall -Wextra -Werror -I$(HEADER)

SRC = ft_isalpha.c		ft_isdigit.c		ft_isalnum.c\
	  ft_isascii.c		ft_isprint.c		ft_strlen.c\
	  ft_memset.c		ft_bzero.c			ft_memcpy.c\
	  ft_memmove.c		ft_strlcpy.c		ft_strlcat.c\
	  ft_toupper.c		ft_tolower.c		ft_strchr.c\
	  ft_strrchr.c		ft_strncmp.c		ft_memchr.c\
      ft_memcmp.c		ft_strnstr.c		ft_atoi.c\
      ft_calloc.c		ft_strdup.c			ft_substr.c\
	  ft_strjoin.c		ft_strtrim.c		ft_split.c\
	  ft_itoa.c			ft_strmapi.c		ft_striteri.c\
	  ft_putchar_fd.c	ft_putstr_fd.c		ft_putendl_fd.c\
	  ft_putnbr_fd.c	ft_atoll.c

SRC_B = ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c\
		ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c\
		ft_lstclear.c	ft_lstiter.c		ft_lstmap.c

OBJ = $(SRC:%.c= %.o)
OBJ_B = $(SRC_B:%.c=%.o)

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o	: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

bonus : $(OBJ_B)
		@make OBJ='$(OBJ_B)' SRC='$(SRC_B)' all

clean	:
	@rm -f $(OBJ) $(OBJ_B)

fclean	:	clean
	@$(RM) $(NAME)

re	:	fclean all