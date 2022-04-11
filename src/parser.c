#include "../include/so_long.h"



int		is_ber_file(char *map_file)
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
	long 	was_read;
	char	*tmp;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		error1("Error : can't open file\n");

	buff = (char *) malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buff)
		error1("Error : malloc failed\n");

	was_read = read(fd, buff, BUFF_SIZE);
	if (was_read == -1)
		error1("Error : read file failed\n");
	buff[was_read] = '\0';
	map_in_line = ft_strdup(buff);
	while (was_read == BUFF_SIZE)
	{
//		ft_bzero(buff, BUFF_SIZE);
		was_read = read(fd, buff, BUFF_SIZE);
		if (was_read == -1)
			error1("Error : read file failed\n");
		buff[was_read] = '\0';
		tmp = map_in_line;
		map_in_line = ft_strjoin(map_in_line, buff);
//		map_in_line = ft_substr(buff, 0, was_read);
		free(tmp);
	}
	free(buff);
	return (map_in_line);
}

char	**map_parser(char *map_file)
{
	char	*map_in_line;
	char	**map;

	if (!is_ber_file(map_file))
		error1("Error : if not .ber file\n");

	map_in_line = get_map_in_line(map_file);
	map = ft_split(map_in_line, '\n');
	free(map_in_line);
	return (map);
}
