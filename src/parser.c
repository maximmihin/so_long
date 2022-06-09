#include "../include/so_long.h"

int	is_ber_file(char *map_file)
{
	char	*dot;

	dot = ft_strrchr(map_file, '.');
	if (!dot)
		return (0);
	return (!ft_strncmp(dot, ".ber\0", 5));
}

char	*get_map_in_line(char *map_file)
{
	int		fd;
	char	*buff;
	char	*map_in_line;
	long	was_read;
	char	*tmp;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		error("Error : can't open file\n");
	buff = (char *) malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buff)
		error("Error : malloc failed\n");
	was_read = read(fd, buff, BUFF_SIZE);
	if (was_read == -1)
		error("Error : read file failed\n");
	buff[was_read] = '\0';
	map_in_line = ft_strdup(buff);
	while (was_read == BUFF_SIZE)
	{
		was_read = read(fd, buff, BUFF_SIZE);
		if (was_read == -1)
			error("Error : read file failed\n");
		buff[was_read] = '\0';
		tmp = map_in_line;
		map_in_line = ft_strjoin(map_in_line, buff);
		free(tmp);
	}
	free(buff);
	return (map_in_line);
}

void	preproc_double_player(char **map_in_line)
{
	int	i;

	i = 0;
	while ((*map_in_line)[i] && (*map_in_line)[i] != 'P')
		i++;
	i++;
	while ((*map_in_line)[i])
	{
		if ((*map_in_line)[i] == 'P')
			(*map_in_line)[i] = '0';
		i++;
	}
}

void	preproc_double_b_slash(char **map_in_line)
{
	if (ft_strnstr(*map_in_line, "\n\n", ft_strlen(*map_in_line)))
		error("Error : the map_old is not rectangle (double b-slash)\n");
}

char	**map_parser(char *map_file)
{
	char	*map_in_line;
	char	**map;

	if (!is_ber_file(map_file))
		error("Error : is not .ber file\n");
	map_in_line = get_map_in_line(map_file);
	preproc_double_b_slash(&map_in_line);
	preproc_double_player(&map_in_line);
	map = ft_split(map_in_line, '\n');
	free(map_in_line);
	return (map);
}
