/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:37:59 by gradagas          #+#    #+#             */
/*   Updated: 2021/10/30 20:38:02 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*arr;
	size_t			len;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s) + 1;
	arr = (char *) malloc(sizeof (char) * len);
	if (!arr)
		return (NULL);
	arr = ft_memcpy(arr, s, len);
	while (arr[i])
	{
		arr[i] = (*f)(i, s[i]);
		i++;
	}
	return (arr);
}
