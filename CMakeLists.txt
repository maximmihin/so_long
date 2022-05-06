cmake_minimum_required(VERSION 3.20)
project(so_long C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -framework OpenGL -framework AppKit")

include_directories(include)
include_directories(libs/libft)
include_directories(libs/MinilibX)

add_library(ft STATIC
        libs/libft/ft_atoi.c
        libs/libft/ft_atoi.c
        libs/libft/ft_atoll.c
        libs/libft/ft_bzero.c
        libs/libft/ft_calloc.c
        libs/libft/ft_isalnum.c
        libs/libft/ft_isalpha.c
        libs/libft/ft_isascii.c
        libs/libft/ft_isdigit.c
        libs/libft/ft_isprint.c
        libs/libft/ft_itoa.c
        libs/libft/ft_lstadd_back.c
        libs/libft/ft_lstadd_front.c
        libs/libft/ft_lstclear.c
        libs/libft/ft_lstdelone.c
        libs/libft/ft_lstiter.c
        libs/libft/ft_lstlast.c
        libs/libft/ft_lstmap.c
        libs/libft/ft_lstnew.c
        libs/libft/ft_lstsize.c
        libs/libft/ft_memchr.c
        libs/libft/ft_memcmp.c
        libs/libft/ft_memcpy.c
        libs/libft/ft_memmove.c
        libs/libft/ft_memset.c
        libs/libft/ft_putchar_fd.c
        libs/libft/ft_putendl_fd.c
        libs/libft/ft_putnbr_fd.c
        libs/libft/ft_putstr_fd.c
        libs/libft/ft_split.c
        libs/libft/ft_strchr.c
        libs/libft/ft_strdup.c
        libs/libft/ft_striteri.c
        libs/libft/ft_strjoin.c
        libs/libft/ft_strlcat.c
        libs/libft/ft_strlcpy.c
        libs/libft/ft_strlen.c
        libs/libft/ft_strmapi.c
        libs/libft/ft_strncmp.c
        libs/libft/ft_strnstr.c
        libs/libft/ft_strrchr.c
        libs/libft/ft_strtrim.c
        libs/libft/ft_substr.c
        libs/libft/ft_tolower.c
        libs/libft/ft_toupper.c
        )

add_library(mlx STATIC
        libs/MinilibX/mlx_shaders.c
        libs/MinilibX/mlx_new_window.m
        libs/MinilibX/mlx_init_loop.m
        libs/MinilibX/mlx_new_image.m
        libs/MinilibX/mlx_xpm.c
        libs/MinilibX/mlx_int_str_to_wordtab.c
        libs/MinilibX/mlx_png.c
        libs/MinilibX/mlx_mouse.m
        )

add_executable(so_long
        src/main.c
        src/parser.c
        src/map_validation.c
        src/map_validation_utils.c
        src/errors.c
        src/extract_map_data.c
        )

#find_library(FT ft cmake-build-debug)
#find_library(MLX mlx cmake-build-debug)
#
#target_link_libraries(so_long LINK_PUBLIC ${FT})
#target_link_libraries(so_long LINK_PUBLIC ${MLX})
