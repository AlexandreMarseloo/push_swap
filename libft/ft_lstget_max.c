#include "libft.h"

int	ft_lstget_max(t_list *lst)
{
	int	max;

	if (!lst)
		return (0);
	max = lst->data;
	while (lst)
	{
		if (lst->data > max)
			max = lst->data;
		lst = lst->next;
	}
	return (max);
}
