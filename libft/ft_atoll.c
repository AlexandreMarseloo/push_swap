/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:23:59 by almarsel          #+#    #+#             */
/*   Updated: 2020/10/08 08:18:05 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *str)
{
	int		i;
	long long	res;
	int		signe;

	res = 0;
	i = 0;
	signe = 1;
	while (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (signe * res);
}
