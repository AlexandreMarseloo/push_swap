#include "libft.h"

int	ft_lstget_min(t_list *lst)
{
	int	min;

	if (!lst)
		return (0);
	min = lst->data;
	while (lst)
	{
		if (lst->data < min)
			min = lst->data;
		lst = lst->next;
	}
	return (min);
}
