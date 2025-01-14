#include "cub3d.h"

int	validate_line(char *trimmed, char *line)
{
	int	j;

	j = 0;
	while (trimmed[j])
	{
		if (!is_valid_map_char(trimmed[j]))
		{
			free(trimmed);
			free(line);
			return (EXIT_FAILURE);
		}
		j++;
	}
	return (EXIT_SUCCESS);
}

int	handle_map_error(char **line, char *trimmed)
{
	free(trimmed);
	free(*line);
	return (EXIT_FAILURE);
}

int	process_line(t_game *game, char **line, int *i)
{
	char	*trimmed;

	trimmed = remove_spaces(*line);
	if (!trimmed)
		return (handle_map_error(line, trimmed));
	if (validate_line(trimmed, *line) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	game->map[*i] = ft_strdup(trimmed);
	if (!game->map[*i])
		return (handle_map_error(line, trimmed));
	if (game->map[*i][ft_strlen(game->map[*i]) - 1] == '\n')
		game->map[*i][ft_strlen(game->map[*i]) - 1] = '\0';
	(*i)++;
	free(trimmed);
	free(*line);
	*line = get_next_line(game->map_fd);
	return (EXIT_SUCCESS);
}
