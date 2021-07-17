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
	t_list	*tmp;
	int 	i = 0;
	stack_a = parse_arg(ac, av);
	tmp = stack_a;
	while (tmp != NULL)
	{
		tmp->rank = i;
		i = i + 5;
		tmp = tmp->next;
	}
	printlst(stack_a);
	return (0);
}