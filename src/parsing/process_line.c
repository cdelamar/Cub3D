#include "cub3d.h"

int	validate_line(char *line)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (!is_valid_map_char(line[j]))
		{
			free(line);
			return (EXIT_FAILURE);
		}
		j++;
	}
	return (EXIT_SUCCESS);
}

int	process_line(t_game *game, char **line, int *i)
{
	if (validate_line(*line) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	game->map[*i] = ft_strdup(*line);
	if (!game->map[*i])
	{
		free(*line);
		return (EXIT_FAILURE);
	}
	if (game->map[*i][ft_strlen(game->map[*i]) - 1] == '\n')
		game->map[*i][ft_strlen(game->map[*i]) - 1] = '\0';
	(*i)++;
	free(*line);
	*line = get_next_line(game->map_fd);
	return (EXIT_SUCCESS);
}
