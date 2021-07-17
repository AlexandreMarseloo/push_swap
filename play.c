#include "push_swap.h"
#include <stdio.h>

t_list	*parse_arg(int ac, char **av)
{
	int	i;
	t_list	*start;

	start = ft_lstnew(ft_atoi(av[ac - 1]));
	i = ac - 2;
	while (i > 0)
	{
		start->rank = -1;
		ft_lstadd_front(&start, ft_lstnew(ft_atoi(av[i])));
		i--;
	}
	start->rank = -1;
	return (start);
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

void	ft_sort_rank(t_list *stack_a, int size)
{	
	int	tab[size];
	t_list	*tmp;	
	int	i;

	i = 0;
	tmp = stack_a;
	while (tmp != NULL && i < size)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	ft_bubble_sort(tab, size);
	tmp = stack_a;
	while (tmp != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] == tmp->content)
				tmp->rank = i;
			i++;
		}
		tmp = tmp->next;
	}
}

void	printlst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		printf("| value : %d | rank : %d |\n", tmp->content, tmp->rank);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;

	stack_a = parse_arg(ac, av);
	ft_sort_rank(stack_a, ft_lstsize(stack_a));
	printlst(stack_a);
	return (0);
}
