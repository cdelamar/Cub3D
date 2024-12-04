#include "cub3d.h"

int three_colors(char **values)
{
    int i = 0;

    while (values[i] != NULL)
        i++;

    if (i != 3)
    {
        ft_putendl_fd("Error\nInvalid color format (expected 3 values).", 2);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int rgb_color(char *value, int *color)
{
    if (is_numbr(value) == false)
    {
        ft_putendl_fd("Error\nInvalid character in color value. Only digits are allowed.", 2);
        return (EXIT_FAILURE);
    }
    *color = ft_atoi(value);
    if (is_rgb(*color) == false)
    {
        ft_putendl_fd("Error\nPlease enter proper Color value (0-255).", 2);
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}

int check_color(t_game *game)
{
	if (game->floor_color[0] == -1 || game->floor_color[1] == -1 || game->floor_color[2] == -1)
	{
		ft_putendl_fd("Error\nMissing floor color (F).", 2);
		return (EXIT_FAILURE);
	}

	if (game->ceiling_color[0] == -1 || game->ceiling_color[1] == -1 || game->ceiling_color[2] == -1)
	{
		ft_putendl_fd("Error\nMissing ceiling color (C).", 2);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

int path_color(char *line, int color[3])
{
	char **values;
	int i = 0;

	line = skip_spaces(line);

	values = ft_split(line, ',');
	if (!values)
	{
		ft_putendl_fd("Error\nMemory allocation failed for color parsing.", 2);
		return (EXIT_FAILURE);
	}

	if(three_colors(values) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	i = 0;
	while (i < 3)
	{
        if (rgb_color(values[i], &color[i]) == EXIT_FAILURE)
        {
            free_split(values);
            return (EXIT_FAILURE);
        }
		i++;
	}

	free_split(values);
	return (EXIT_SUCCESS);
}

int parse_color(char *line, t_game *game)
{
	if (ft_strncmp(line, "F ", 2) == 0)
		return path_color(line + 2, game->floor_color);
	if (ft_strncmp(line, "C ", 2) == 0)
		return path_color(line + 2, game->ceiling_color);
	else
		return(EXIT_SUCCESS);
}