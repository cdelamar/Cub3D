#include "cub3d.h"

int parse_line(char *line, t_game *game)
{
	// Ignorer les lignes vides ou contenant uniquement des espaces
	line = skip_spaces(line);
	if (*line == '\0')
		return (EXIT_SUCCESS); // TODO line[i] plus joli

	if (parse_texture(line, game) == EXIT_FAILURE)
		return(EXIT_FAILURE);

	if (parse_color(line, game) == EXIT_FAILURE)
		return(EXIT_FAILURE);

	//return parse_map(line, game);
	return (EXIT_SUCCESS);
}

int parse_file(char *file_name, t_game *game)
{
	char *line;

	game->fd = open(file_name, O_RDONLY);
	if (game->fd < 0)
	{
		ft_putendl_fd("Error\nCannot open file.", 2);
		return (false);
	}
	while ((line = get_next_line(game->fd)))
	{
		if (parse_line(line, game) == EXIT_FAILURE)
		{
			free(line);
			return (false);
		}
		free(line);
	}
	close(game->fd);
	if (check_texture(game) == EXIT_FAILURE)
		return(EXIT_FAILURE);
	if(check_color(game) == EXIT_FAILURE)
		return(EXIT_FAILURE);
	// if (check_map(game->map))
		// return (false);
	return (true);
}
