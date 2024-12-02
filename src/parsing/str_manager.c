#include "cub3d.h"

int	rev_strncmp(char *s1, char *s2, size_t n)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 < n || len2 < n)
		return (-1);
	while (len1 && len2 && n)
	{
		if (s1[len1 -1] != s2[len2 -1])
			return (s1[len1 -1] - s2[len2 -1]);
		len1--;
		len2--;
		n--;
	}
	if (n == 0)
		return (0);
	return (len1 - len2);
}