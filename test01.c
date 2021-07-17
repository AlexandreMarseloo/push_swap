#include "push_swap.h"
#include <stdio.h>

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

int	main(int ac, char **av)
{
	int tab[7] = {10, 5, 45, 96, 2, 1, 777};
	ft_bubble_sort(tab, 7);
	int i = 0;
	while (i < 7)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	return (0);
}