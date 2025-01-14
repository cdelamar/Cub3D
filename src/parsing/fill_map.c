#include "cub3d.h"

bool is_valid_map_char(char c)
{
    return (c == '0' || c == '1'
         || c == 'N' || c == 'S'
         || c == 'E' || c == 'W' || c== '\n');
}

static char	*remove_spaces(const char *line)
{
	char	*new_line;
	int		i;
	int		j;

	if (!line)
		return (NULL);
	new_line = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			new_line[j] = line[i];
			j++;
		}
		i++;
	}
	new_line[j] = '\0';
	return (new_line);
}

static int	process_line(t_game *game, char **line, int *i)
{
	char	*trimmed;
	int		j;

	trimmed = remove_spaces(*line);
	if (!trimmed)
	{
		free(*line);
		return (EXIT_FAILURE);
	}

	j = 0;
	while (trimmed[j])
	{
		if (!is_valid_map_char(trimmed[j]))
		{
			free(trimmed);
			free(*line);
			return (EXIT_FAILURE);
		}
		j++;
	}
	game->map[*i] = ft_strdup(trimmed);
	free(trimmed);
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


static int	fill_map_block(t_game *game, char **line, int line_count, int *i)
{
	while (*line && *i < line_count)
	{
		if (process_line(game, line, i) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	game->map[*i] = NULL;
	free(*line);
	return (EXIT_SUCCESS);
}

static int	fill_map(t_game *game, int line_count)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(game->map_fd);
	while (line)
	{
		if (!is_empty_line(line)
			&& first_map_line(skip_spaces(line)))
		{
			if (fill_map_block(game, &line, line_count, &i) == EXIT_SUCCESS)
				return (EXIT_SUCCESS);
			else
			{
				printf("je passe ici\n\n");
				return (EXIT_FAILURE);
			}
		}
		free(line);
		line = get_next_line(game->map_fd);
	}
	printf("sortie de loop\n");
	return (EXIT_FAILURE);
}

int	parse_map(t_game *game, char *file_name)
{
	int	map_fd_copy;
	int	line_count;
	int	i;

	map_fd_copy = open(file_name, O_RDONLY);
	if (map_fd_copy < 0)
		return (EXIT_FAILURE);
	line_count = count_map_lines(map_fd_copy);
	close(map_fd_copy);
	game->map = malloc(sizeof(char *) * (line_count + 1));
	if (!game->map)
		return (EXIT_FAILURE);
	i = 0;
	while (i <= line_count)
	{
		game->map[i] = NULL;
		i++;
	}
	if (fill_map(game, line_count) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
	{
		ft_putendl_fd("Error\nMap unsettled (invalid characters or bad format).", 2);
		return (EXIT_FAILURE);
	}
}
