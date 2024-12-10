/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:12:43 by cdelamar          #+#    #+#             */
/*   Updated: 2023/10/20 15:56:29 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>


char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*dst;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((dst = ft_calloc(sizeof(char), size)) == NULL)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(dst + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (*(s2 + j))
	{
		*(dst + i + j) = *(s2 + j);
		j++;
	}
	*(dst + i + j) = '\0';
	return (dst);
}
