/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:37:48 by gradagas          #+#    #+#             */
/*   Updated: 2022/06/10 20:37:52 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_fd(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		error("Error : can't open file\n");
	return (fd);
}

char	*init_buff(void)
{
	char	*buff;

	buff = (char *) malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buff)
		error("Error : malloc failed\n");
	return (buff);
}
