#include "cub3d.h"

bool	first_map_line(char *line)
{
	int	i;

	line = skip_spaces(line);
	i = 0;
	while (line [i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (false);
		i++;
	}
	return (true);
}

char	*copy_gnl_line(char *line)
{
	char	*result;
	int		len;

	len = ft_strlen(line);
	result = ft_strdup(line);
	if (result[len - 1] == '\n')
		result[len - 1] = '\0';
	return (result);
}

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
