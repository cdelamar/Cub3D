#include "cub3d.h"

bool is_map_line(char *line)
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

int find_map_start(int fd)
{
	char *line;
	int line_num = 0;

	while ((line = get_next_line(fd)))
	{
		line_num++;
		if (line && (is_empty_line(line) == false) && is_map_line(skip_spaces(line)))
		{
			printf("Map start found on line %d: \"%s\"\n", line_num, line);
			free(line);
			return (line_num); // Return the first valid map line number
		}

		//free(line);
	}
	ft_putendl_fd("Error\n Proper map unsettled\n", 2);
	return (-1);
}


int check_map(t_game *game)
{
	char   *line;
	int     map_start;
	int		i;

	i = 0;
	map_start = find_map_start(game->map_fd);
	printf("debug test after find map\n");
	if (map_start == -1)
		return (EXIT_FAILURE);
	line = get_next_line(game->map_fd);

	while (line)
	{
		game->map_buffer = ft_realloc(game->map, sizeof(char *) * (i + 2));
		if (!game->map_buffer)
			return(EXIT_FAILURE);
		game->map = game->map_buffer;
		game->map[i] = line;
		i++;
		line = get_next_line(game->map_fd);
		printf("i number %d\n" , i);
	}

	game->map_buffer = ft_realloc(game->map, sizeof(char *) * (i + 2));
	game->map = game->map_buffer;
	game->map[i] = NULL;
	free(line);
	/*while (line)
	{
		i++;
		free(line);
		line = get_next_line(game->map_fd);
	}

	printf("size i = %d\n", i);
	game->map = malloc(sizeof(char *) * i + 1);
	*/

	return(EXIT_SUCCESS);
}
