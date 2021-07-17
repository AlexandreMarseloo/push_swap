#include "push_swap.h"
#include <stdio.h>

t_stack	*init_stack()
{
	t_stack	*ret;

	ret = malloc(sizeof(t_stack));
	if (ret == NULL)
		return (NULL);
	ret->first = NULL;
	return (ret);
}

t_list	*parse_arg(int ac, char **av)
{
	int	i;
	t_list	*start;

	start = ft_lstnew(ft_atoi(av[ac - 1]));
	i = ac - 2;
	while (i > 0)
	{
		ft_lstadd_front(&start, ft_lstnew(ft_atoi(av[i])));
		i--;
	}
	return (start);
}

void	ft_push(t_stack *src, t_stack *dst)
{
	t_list	*tmp;

	tmp = src->first->next;
	ft_lstadd_front(&dst->first, src->first);
	src->first = tmp;
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
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = init_stack();
	stack_b = init_stack();
	stack_a->first = parse_arg(ac, av);
	ft_push(stack_a, stack_b);
	ft_push(stack_a, stack_b);
	ft_push(stack_a, stack_b);
	printlst(stack_a->first);
	printf("---\n");
	printlst(stack_b->first);
		
	return (0);
}