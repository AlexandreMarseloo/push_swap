#include <stdlib.h>
#include <stdio.h>

int	main()
{
	int	*lst;
	int	i;

	lst = random.sample((1,500), 100);
	i = 0;
	while (i < 100)
	{
		printf("%d ", lst[i]);
		i++;
	}
	return (0);
}
