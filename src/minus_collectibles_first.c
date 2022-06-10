/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_collectibles_first.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:36:57 by gradagas          #+#    #+#             */
/*   Updated: 2022/06/10 20:37:02 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	minus_collectibles_first(t_list **collectibles_addresses)
{
	t_list	*tmp_coll_address;

	tmp_coll_address = *collectibles_addresses;
	*collectibles_addresses = (*collectibles_addresses)->next;
	free(tmp_coll_address->content);
	free(tmp_coll_address);
}
