#include "../includes/push_swap.h"

void	sort_big_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	max_bit;

	size = ft_lstsize(*stack_a);
	ft_sort_rank(stack_a, size);
	max_bit = 0;
	while (((size - 1) >> max_bit) != 0)
		max_bit++;
	ft_radix_sort(stack_a, stack_b, max_bit, size);
}

void	ft_bubble_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = size - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (tab[j + 1] < tab[j])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i--;
	}
}

void	ft_fill_tab(int	*tab, t_list **stack_a)
{
	t_list	*tmp;
	int	i;

	tmp = *stack_a;
	i = 0;
	while (tmp->next)
	{
		tab[i] = tmp->data;
		i++;
		tmp = tmp->next;
	}
	tab[i] = tmp->data;
}

void	ft_sort_rank(t_list **stack_a, int size)
{
	t_list	*tmp;
	int	*tab;
	int	i;

	if (!(tab = malloc(sizeof(int) * (size))))
		return ;
	ft_fill_tab(tab, stack_a);
	ft_bubble_sort(tab, size);
	i = 0;
	while (i < size)
	{
		tmp = *stack_a;
		while (tmp->data != tab[i])
			tmp = tmp->next;
		tmp->rank = i;
		i++;
	}
	free(tab);
}

void	ft_radix_sort(t_list **stack_a, t_list **stack_b,  int max_bits, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (is_sorted(*stack_a) && !(*stack_b))
				return ;
			if ((((*stack_a)->rank >> i) & 1) == 1)
				ft_rotate(stack_a, "ra\n");
			else
				ft_push(stack_a, stack_b, "pb\n");
			j++;
		}
		while (*stack_b)
			ft_push(stack_b, stack_a, "pa\n");
		i++;
	}
	return ;
}
