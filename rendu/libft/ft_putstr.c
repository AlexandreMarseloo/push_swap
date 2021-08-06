#include "libft.h"

void	ft_putstr(char const *str)
{
	if (str == NULL)
		return ;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}