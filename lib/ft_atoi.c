/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:11:14 by cdelamar          #+#    #+#             */
/*   Updated: 2025/01/18 16:37:37 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

/* ft_atoi */
/* converti une chaine de caractere en un entier */

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		if (result > INT_MAX || result * -1 < INT_MIN)
			return (-1);
		nptr++;
	}
	return ((int)result * sign);
}

/*int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	num;

	sign = 1;
	i = 0;
	num = 0;
	while (nptr[i])
	{
		while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
			i++;
		if (nptr[i] == '-')
		{
			sign = -sign;
			i++;
		}
		else if (nptr[i] == '+')
			i++;
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			num = num * 10 + (nptr[i] - '0');
			i++;
		}
		return (num * sign);
	}
	return (num * sign);
}

int	main(void)
{
	char	tab[] = " 	13445abds557";

	printf("%d\n", atoi(tab));
	printf("%d\n", ft_atoi(tab));
	return (0);
}
*/