/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:31:03 by gradagas          #+#    #+#             */
/*   Updated: 2021/10/30 20:31:08 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbrlen(int nbr)
{
	int	i;

	i = 1;
	if (nbr == -2147483648)
		return (10);
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void	getnbr(char *arr, int nbr, int len)
{
	if (nbr == -2147483648)
	{
		ft_strlcpy(arr - 9, "2147483648", len - 1);
		return ;
	}
	if (nbr > 9 && len)
		getnbr(arr - 1, nbr / 10, len - 1);
	*arr = (char)(nbr % 10 + '0');
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		len;
	int		minus;
	int		i;

	minus = 0;
	if (n < 0)
	{
		minus++;
		n *= -1;
		len = nbrlen(n) + 2;
	}
	else
		len = nbrlen(n) + 1;
	arr = (char *) malloc(sizeof (char) * len);
	if (!arr)
		return (NULL);
	i = 0;
	if (minus)
		arr[i] = '-';
	getnbr(&arr[len - 2], n, len);
	arr[len - 1] = '\0';
	return (arr);
}
