/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:36:17 by gradagas          #+#    #+#             */
/*   Updated: 2021/10/30 20:36:20 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*arr;
	size_t	len;

	len = ft_strlen((char *)s1) + 1;
	arr = (char *) malloc(len * sizeof(char));
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, s1, len);
	return (arr);
}
