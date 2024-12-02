#include "cub3d.h"

// concerne la partie :
// F 220,100,0
// C 225,30,0
bool valid_color(char *line, int *color)
{
    char	**components;
	int		i;

    components = ft_split(line + 2, ',');
    if (!components || ft_array_len(components) != 3)
	{
        ft_putendl_fd(INVALID_COLOR, 2);
        return (false);
    }

	// on met  3 pour faire les 3 couleurs et pas plus
	while(i < 3)
	{
        color[i] = ft_atoi(components[i]);
        if (color[i] < 0 || color[i] > 255)
		{
            ft_putendl_fd(WRONG_COLOR_VALUE, 2);
            return (false);
        }
		i++;
    }
    return (true);
}