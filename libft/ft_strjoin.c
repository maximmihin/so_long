/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:36:51 by gradagas          #+#    #+#             */
/*   Updated: 2021/10/30 20:36:53 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)malloc(sizeof (*s1) * (i + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		arr[i] = *s2++;
		i++;
	}
	arr[i] = 0;
	return (arr);
}
