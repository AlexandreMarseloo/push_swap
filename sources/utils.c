#include "../includes/push_swap.h"

void	ft_exit(int code, t_list **stack_a, t_list **stack_b)
{
	(void)stack_a;
	(void)stack_b;
	if (code == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_putstr("Error\n");
		exit(EXIT_FAILURE);
	}
}

void	parse_arg(char **av, int ac, t_list **stack_a)
{
	t_list	*elem;
	int	i;
	long long	tmp;

	i = 0;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "") == 0)
			ft_exit(1, stack_a, 0);
		if (!is_number(av[i]))
			ft_exit(1, stack_a, 0);
		tmp = ft_atoll(av[i]);
		if (!is_int(tmp))
			ft_exit(1, stack_a, 0);
		elem = ft_lstnew((int)tmp);
		if (!elem)
			ft_exit(1, stack_a, 0);
		ft_lstadd_back(stack_a, elem);
		i++;
	}
	if (has_doublon(*stack_a))
		ft_exit(1, stack_a, 0);
}

int	is_sorted(t_list *stack)
{
	int	tmp;

	if (!stack)
		return (0);
	if (!stack->next)
		return (1);
	while (stack->next)
	{
		tmp = stack->data;
		stack = stack->next;
		if (tmp >= stack->data)
			return (0);
	}
	return (1);
}

void	ft_split_stack(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	len;

	len = ft_lstsize(*stack_a);
	while (len >= 4)
	{
		min = ft_lstget_min(*stack_a);
		while ((*stack_a)->data != min)
		{
			if (is_closer_to_top(*stack_a, min))
				ft_rotate(stack_a, "ra\n");
			else
				ft_rev_rotate(stack_a, "rra\n");
		}
		ft_push(stack_a, stack_b, "pb\n");
		len--;
	}
}
