cmake_minimum_required(VERSION 3.20)
project(so_long C)

set(CMAKE_C_STANDARD 99)

set(LIBFT_PATH libs/libft)
set(MLX_PATH libs/MinilibX)

include_directories(include)
include_directories(${LIBFT_PATH})
include_directories(${MLX_PATH})

add_library(ft STATIC
        ${LIBFT_PATH}/ft_atoi.c
        ${LIBFT_PATH}/ft_atoi.c
        ${LIBFT_PATH}/ft_atoll.c
        ${LIBFT_PATH}/ft_bzero.c
        ${LIBFT_PATH}/ft_calloc.c
        ${LIBFT_PATH}/ft_isalnum.c
        ${LIBFT_PATH}/ft_isalpha.c
        ${LIBFT_PATH}/ft_isascii.c
        ${LIBFT_PATH}/ft_isdigit.c
        ${LIBFT_PATH}/ft_isprint.c
        ${LIBFT_PATH}/ft_itoa.c
        ${LIBFT_PATH}/ft_lstadd_back.c
        ${LIBFT_PATH}/ft_lstadd_front.c
        ${LIBFT_PATH}/ft_lstclear.c
        ${LIBFT_PATH}/ft_lstdelone.c
        ${LIBFT_PATH}/ft_lstiter.c
        ${LIBFT_PATH}/ft_lstlast.c
        ${LIBFT_PATH}/ft_lstmap.c
        ${LIBFT_PATH}/ft_lstnew.c
        ${LIBFT_PATH}/ft_lstsize.c
        ${LIBFT_PATH}/ft_memchr.c
        ${LIBFT_PATH}/ft_memcmp.c
        ${LIBFT_PATH}/ft_memcpy.c
        ${LIBFT_PATH}/ft_memmove.c
        ${LIBFT_PATH}/ft_memset.c
        ${LIBFT_PATH}/ft_putchar_fd.c
        ${LIBFT_PATH}/ft_putendl_fd.c
        ${LIBFT_PATH}/ft_putnbr_fd.c
        ${LIBFT_PATH}/ft_putstr_fd.c
        ${LIBFT_PATH}/ft_split.c
        ${LIBFT_PATH}/ft_strchr.c
        ${LIBFT_PATH}/ft_strdup.c
        ${LIBFT_PATH}/ft_striteri.c
        ${LIBFT_PATH}/ft_strjoin.c
        ${LIBFT_PATH}/ft_strlcat.c
        ${LIBFT_PATH}/ft_strlcpy.c
        ${LIBFT_PATH}/ft_strlen.c
        ${LIBFT_PATH}/ft_strmapi.c
        ${LIBFT_PATH}/ft_strncmp.c
        ${LIBFT_PATH}/ft_strnstr.c
        ${LIBFT_PATH}/ft_strrchr.c
        ${LIBFT_PATH}/ft_strtrim.c
        ${LIBFT_PATH}/ft_substr.c
        ${LIBFT_PATH}/ft_tolower.c
        ${LIBFT_PATH}/ft_toupper.c
        )

add_library(mlx STATIC
        ${MLX_PATH}/mlx_shaders.c
        ${MLX_PATH}/mlx_new_window.m
        ${MLX_PATH}/mlx_init_loop.m
        ${MLX_PATH}/mlx_new_image.m
        ${MLX_PATH}/mlx_xpm.c
        ${MLX_PATH}/mlx_int_str_to_wordtab.c
        ${MLX_PATH}/mlx_png.c
        ${MLX_PATH}/mlx_mouse.m
        )

add_executable(so_long
        src/main.c
        src/parser.c
        src/map_validation.c
        src/map_validation_utils.c
        src/error.c
        src/render_map.c
        src/init_all_textures.c
        src/init_textures_utils.c
        src/key_press_processing.c
        src/init_map_objects.c
        src/print_moves.c
        src/init_render_data_utils.c
        src/init_map_object_utils.c
        src/appoint_textures.c
        src/filling_map.c
        src/init_textures.c
        src/move_config_utils.c
        src/main_loop_x.c
        src/main_loop_event.c
        src/main_loop_mod_utils.c
        src/main_loop_print_list.c
        src/enemies_mod_utils.c
        src/main_loop_event_utils.c
        src/minus_collectibles_first.c
        src/parser_utils.c)

add_executable(so_long_bonus
        bonus/main_bonus.c
        bonus/print_moves_bonus.c
        src/parser.c
        src/map_validation.c
        src/map_validation_utils.c
        src/error.c
        src/render_map.c
        src/init_all_textures.c
        src/init_textures_utils.c
        src/key_press_processing.c
        src/init_map_objects.c
        src/init_render_data_utils.c
        src/init_map_object_utils.c
        src/appoint_textures.c
        src/filling_map.c
        src/init_textures.c
        src/move_config_utils.c
        src/main_loop_x.c
        src/main_loop_event.c
        src/main_loop_mod_utils.c
        src/main_loop_print_list.c
        src/enemies_mod_utils.c
        src/main_loop_event_utils.c
        src/minus_collectibles_first.c
        src/parser_utils.c)

target_compile_options(mlx PRIVATE -O2)
target_compile_options(ft PRIVATE -O2)
target_compile_options(so_long PRIVATE -O2
        -Wall
        -Wextra
        -Werror)

target_link_libraries(so_long ft)
target_link_libraries(so_long mlx "-framework OpenGL" "-framework AppKit")

target_link_libraries(so_long_bonus ft)
target_link_libraries(so_long_bonus mlx "-framework OpenGL" "-framework AppKit")
