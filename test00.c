#include <stdio.h>
#include "push_swap.h"

int	main(int ac, char **av)
{
	int	i = 0;
	int	tab[ac];
	printf("ac = %d\n", ac);
	while (i + 1 < ac)
	{
		tab[i] = ft_atoi(av[i + 1]);
		printf("tab[i] = %d et i = %d\n", tab[i], i);
		i++;
	}
	int num = 87;
	printf("%d\n", num>>3);
	return (0);
}
