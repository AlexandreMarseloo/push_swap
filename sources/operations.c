#include "../includes/push_swap.h"

void	ft_push(t_list **src, t_list **dst, char *str)
{
	t_list	*tmp;

	tmp = *src;
	if (!tmp)
		return ;
	*src = tmp->next;
	tmp->next = 0;
	ft_lstadd_front(dst, tmp);
	ft_putstr(str);
}

void	ft_swap(t_list **stack, char *str)
{
	t_list	*tmp0;
	t_list	*tmp1;

	tmp0 = *stack;
	if (!tmp0 || !tmp0->next)
		return ;
	tmp1 = tmp0->next;
	*stack = tmp1;
	tmp0->next = tmp1->next;
	tmp1->next = tmp0;
	ft_putstr(str);
}

void	ft_rotate(t_list **stack, char *str)
{
	t_list	*tmp;

	tmp = *stack;
	if (!tmp || !tmp->next)
		return ;
	*stack = tmp->next;
	tmp->next = 0;
	ft_lstadd_back(stack, tmp);
	ft_putstr(str);
}

void	ft_rev_rotate(t_list **stack, char *str)
{
	t_list	*tmp0;
	t_list	*tmp1;

	tmp0 = *stack;
	if (!tmp0 || !tmp0->next)
		return ;
	while (tmp0->next->next)
		tmp0 = tmp0->next;
	tmp1 = tmp0->next;
	tmp0->next = 0;
	ft_lstadd_front(stack, tmp1);
	ft_putstr(str);
}
