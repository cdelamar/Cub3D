#include "cub3d.h"

bool	is_valid_map_char(char c)
{
	return (c == '0' || c == '1'
		|| c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == '\n' 
		|| c == ' ' || c == '\t');
}

bool	first_map_line(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '\0')
		return (false);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != '0' && !is_valid_map_char(line[i]))
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
