#include "cub3d.h"

bool first_map_line(char *line)
{
	int i;

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

int parse_map(t_game *game)
{
	char *line;
	int line_num = 0;
	int	i = 0;
	int len = 0;

	while ((line = get_next_line(game->map_fd)))
	{
		line_num++;
		if (line && (is_empty_line(line) == false) && first_map_line(skip_spaces(line)))
		{
			while (line)
			{
				len = ft_strlen(line);
				game->map_buffer = ft_realloc(game->map, sizeof(char *) * (len));
				if (!game->map_buffer)
				{
					free(line);
					return(EXIT_FAILURE);
				}
				game->map = game->map_buffer;
				game->map[i] = line;
				if(game->map[i][len - 1] == '\n')
					game->map[i][len - 1] = '\0';
				i++;
				line = get_next_line(game->map_fd);
			}

			game->map_buffer = ft_realloc(game->map, sizeof(char *) * (i + 2));
			game->map = game->map_buffer;
			game->map[i] = NULL;
			free(line);
			return (EXIT_SUCCESS);
		}
		free(line);
	}
	ft_putendl_fd("Error\n Proper map unsettled\n", 2);
	return (-1);
}


int check_map(t_game *game)
{
	if (parse_map(game) == -1)
		return (EXIT_FAILURE);
	// ici on rajoutera tous les prerequis
	// pour bien verifier la map :
	//. les bordures a 1
	//. ft_strchr ("01NSEW", map[i][j])
	//. etc
	return(EXIT_SUCCESS);
}
