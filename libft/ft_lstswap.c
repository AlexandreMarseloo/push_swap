#include "libft.h"

void	ft_lstswap(t_list *lst0, t_list *lst1)
{
	t_list	*tmp;

	tmp->data = lst0->data;
	lst0->data = lst1->data;
	lst1->data = tmp->data;
}
