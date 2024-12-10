/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:13:14 by cdelamar          #+#    #+#             */
/*   Updated: 2023/10/19 15:14:49 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*ft_substr*/
/*sur la chaine '*s' copie en commencant a
partir de 'start' sur 'len' caracteres*/

char *ft_substr(const char *s, unsigned int start, size_t len)
{
    char *substr;
    size_t i;
    size_t s_len;

    i = 0;
    s_len = 0;
    if (!s)
        return (NULL);
    while (s[s_len])
        s_len++;
    if (start >= s_len)
        len = 0;
    if (start + len > s_len)
        len = s_len - start;
    substr = (char *)malloc(len + 1);
    if (!substr)
        return (NULL);
    while (i < len)
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}

