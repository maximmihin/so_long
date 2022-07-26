/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:32:29 by gradagas          #+#    #+#             */
/*   Updated: 2021/10/30 20:32:32 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			n;
	unsigned char	str;
	unsigned char	*ptr;

	n = 0;
	str = (unsigned char)c;
	ptr = (unsigned char *)b;
	while (len > n)
	{
		ptr[n] = str;
		n++;
	}
	return (b);
}
