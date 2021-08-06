#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	main()
{
	char	*str;
	char	*str1 = "test";
	int	ret;
	int	test;

	test = 0;
	str = malloc(sizeof(char) * 50);
	if (!str)
		return (0);
	ret = read(0, str, 50);
	printf("buffer : %s\nret = %d\n", str, ret);
	int i = 0;
	if (ft_strcmp(str1, str) == 0)
		test += 5;
	printf("%d\n", test);
	return (0);
}
