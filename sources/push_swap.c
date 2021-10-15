#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (ac == 1)
		return (1);
	parse_arg(av + 1, ac - 1, &stack_a);
	if (!is_sorted(stack_a))
		ft_sort(&stack_a, &stack_b);
	ft_exit(0, &stack_a, &stack_b);
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if (len <= 1)
		return ;
	else if (len <= 3)
		sort_little_stack(stack_a);
	else if (len <= 5)
		sort_medium_stack(stack_a, stack_b);
	else
		sort_big_stack(stack_a, stack_b);
}

void	sort_little_stack(t_list **stack_a)
{
	int	min;
	int	max;

	min = ft_lstget_min(*stack_a);
	max = ft_lstget_max(*stack_a);

	while (!is_sorted(*stack_a))
	{
		if ((*stack_a)->data < (*stack_a)->next->data || ((*stack_a)->data == max && (*stack_a)->next->data == min))
			ft_rotate(stack_a, "ra\n");
		else
			ft_swap(stack_a, "sa\n");
	}
}

void	sort_medium_stack(t_list **stack_a, t_list **stack_b)
{
	ft_split_stack(stack_a, stack_b);
	sort_little_stack(stack_a);
	while (*stack_b)
		ft_push(stack_b, stack_a, "pa\n");
}
