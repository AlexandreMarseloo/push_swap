#include "../includes/push_swap.h"

int	is_number(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_int(long long nb)
{
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	return (1);
}

int	has_doublon(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->data == tmp->data)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	is_closer_to_top(t_list *lst, int n)
{
	int	len;
	int	i;

	len = ft_lstsize(lst);
	i = 0;
	while (lst && lst->data != n)
	{
		lst = lst->next;
		i++;
	}
	if (i <= len/2)
		return (1);
	return (0);
}
