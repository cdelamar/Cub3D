#include "cub3d.h"

static int	free_values_and_fail(char **values)
{
	ft_freetab(values);
	return (EXIT_FAILURE);
}

static int	assign_colors(char **values, int color[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb_color(values[i], &color[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	path_color(char *line, int color[3])
{
	char	**values;

	line = skip_spaces(line);
	values = ft_split(line, ',');
	if (!values)
	{
		ft_putendl_fd("Error\nMemory allocation failed for color parsing.", 2);
		return (EXIT_FAILURE);
	}
	if (color[0] == -1 || color[1] == -1
		|| color[2] == -1)
	{
		ft_putendl_fd("Error\nCheh.", 2);
		ft_freetab(values);
		return (EXIT_FAILURE);
	}
	if (three_colors(values) == EXIT_FAILURE)
		return (free_values_and_fail(values));
	if (assign_colors(values, color) == EXIT_FAILURE)
		return (free_values_and_fail(values));
	ft_freetab(values);
	return (EXIT_SUCCESS);
}
