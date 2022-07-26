/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:42:30 by gradagas          #+#    #+#             */
/*   Updated: 2021/10/30 20:42:32 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int ch)
{
	if ((ch > 64 && ch < 91) || (ch > 96 && ch < 123))
		return (1);
	else
		return (0);
}
