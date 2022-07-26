/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:37:04 by gradagas          #+#    #+#             */
/*   Updated: 2021/10/30 20:37:07 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;

	d_len = 0;
	while (*dst && d_len < dstsize)
	{
		dst++;
		d_len++;
	}
	s_len = ft_strlen(src);
	if (dstsize <= d_len)
		return (dstsize + s_len);
	dstsize -= d_len + 1;
	while (dstsize && *src)
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}
	*dst = '\0';
	return (d_len + s_len);
}
