#include "../includes/push_swap.h"
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

void	ft_sort_rank(t_stack *a, int size)
{
	int	*tab;
	t_list	*tmp;
	int	i;

	if (!(tab = malloc(sizeof(int) * (size))))
		return ;
	tmp = a->first;
	i = 0;
	while (tmp->next)
	{
		tab[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	tab[i] = tmp->content;
	ft_bubble_sort(tab, size);
	tmp = a->first;
	i = 0;
	while (i < size)
	{
		tmp = a->first;
		while (tmp->content != tab[i])
			tmp = tmp->next;
		tmp->rank = i;
		i++;
	}

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

void	ft_rotate(t_stack *src)
{
	t_list	*tmp;

	tmp = src->first;
	src->first = src->first->next;
	ft_lstadd_back(&src->first, tmp);
}

void	ft_reverse_rotate(t_stack *src)
{
	t_list	*tmp;

	tmp = src->first;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(&src->first, ft_lstlast(src->first));
	tmp->next = NULL;
}

void	ft_swap(t_stack	*src)
{
	t_list	*tmp0;
	t_list	*tmp1;

	if (src->first == NULL || src->first->next == NULL)
		return ;
	tmp0 = src->first->next->next;
	tmp1 = src->first->next;
	src->first->next->next = src->first;
	src->first->next = tmp0;
	src->first = tmp1;
}

void	ft_push(t_stack *src, t_stack *dst)
{
	t_list	*tmp;

	if (src->first == NULL)
		return ;
	tmp = src->first->next;
	ft_lstadd_front(&dst->first, src->first);
	src->first = tmp;
}

int	ft_get_maxnum(t_stack *a)
{
	t_list	*tmp;
	int	max_num;

	if (a->first == NULL)
		return (0);
	tmp = a->first;
	max_num = tmp->rank;
	while (tmp->next)
	{
		if (max_num < tmp->rank)
			max_num = tmp->rank;
		tmp = tmp->next;
	}
	return (max_num);
}

int	ft_get_maxbits(int max_num)
{
	int	max_bits;

	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int	ft_is_sorted(t_stack *a, t_stack *b)
{
	int	res;
	int	val;
	t_list	*tmp;

	if (a->first == NULL || a->first->next == NULL)
	{
		if (b->first == NULL)
			return (1);
		return (0);
	}
	res = 1;
	tmp = a->first;
	val = tmp->content;
	tmp = tmp->next;
	while (tmp->next)
	{
		if (val > tmp->content)
			res = 0;
		val = tmp->content;
		tmp = tmp->next;
	}
	if (val > tmp->content)
		return (0);
	if (b->first == NULL && res == 1)
		return (1);
	return(0);
}

void	printstacks(t_stack *a, t_stack *b)
{
	t_list	*tmpa;
	t_list	*tmpb;

	tmpa = a->first;
	tmpb = b->first;;
	while (tmpa != NULL && tmpb != NULL)
	{
		printf("| val = %d rank = %d |     | val = %d rank = %d |\n", tmpa->content, tmpa->rank, tmpb->content, tmpb->rank);
		tmpa = tmpa->next;
		tmpb = tmpb->next;
	}
	while (tmpa != NULL)
	{
		printf("| val = %d rank = %d |     |                    |\n", tmpa->content, tmpa->rank);
		tmpa = tmpa->next;
	}
	while (tmpb != NULL)
	{
		printf("|                    |     | val = %d rank = %d |\n", tmpb->content, tmpb->rank);
		tmpb = tmpb->next;
	}
	printf("---------------\n| A |     | B |\n");
}

int	ft_radix_sort(t_stack *a, t_stack *b,  int max_bits, int size)
{
	int	i;
	int	j;
	int	ret;

	ret = 0;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (ft_is_sorted(a, b) == 1)
				return (ret);
			if ((((a->first->rank >> i) & 1) == 1))
			{
				ft_rotate(a);
				ret++;
				ft_putstr("ra\n");
			}
			else
			{
				ft_push(a, b);
				ret++;
				ft_putstr("pb\n");
			}
			j++;
			//printstacks(a, b);
		}
		while (b->first != NULL)
		{
			ft_push(b, a);
			ret++;
			ft_putstr("pa\n");
			//printstacks(a, b);
		}
		i++;
	}
	return (ret);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int	max_num;
	int	max_bits;
	//int	ret;

	a = init_stack();
	b = init_stack();
	a->first = parse_arg(ac, av);
	ft_sort_rank(a, ac - 1);
	max_num = ft_get_maxnum(a);
	max_bits = ft_get_maxbits(max_num);
	ft_radix_sort(a, b, max_bits, ac - 1);
	//printf("nombre d'opérations : %d\n", ret);
	//printstacks(a, b);
	return (0);
}
