#include "libft.h"

int	ft_strcmp(char *str0, char *str1)
{
	int	i;

	i = 0;
	if (!str0 || !str1)
		return (0);
	while (str0[i] && str1[i] && str0[i] == str1[i])
		i++;
	return (str0[i] - str1[i]);
}

