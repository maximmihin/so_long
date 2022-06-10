#include "../include/so_long.h"

void	minus_collectibles_first(t_list **collectibles_addresses)
{
	t_list	*tmp_coll_address;

	tmp_coll_address = *collectibles_addresses;
	*collectibles_addresses = (*collectibles_addresses)->next;
	free(tmp_coll_address->content);
	free(tmp_coll_address);
}
