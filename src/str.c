#include "cub3d.h"

char *copy_gnl_line(char *line)
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

void print_int_array(int *array, int size)
{
    int i = 0;

    if (!array || size <= 0) // Vérification des entrées
    {
        printf("Invalid array or size.\n");
        return;
    }

    printf("Array: [");
    while (i < size)
    {
        printf("%d", array[i]);
        if (i < size - 1)
            printf(", ");
        i++;
    }
    printf("]\n");
}

void print_char_array(char **array)
{
    if (!array)
        return;
    while (*array)
	{
        printf("%s\n", *array);
        array++;
    }
}

void free_split(char **tab)
{
	int i;

	i = 0;
	if(!tab[i])
		return ;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
}