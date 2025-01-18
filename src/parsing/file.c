/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:43:07 by lgalloux          #+#    #+#             */
/*   Updated: 2025/01/18 16:43:09 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_line(char *line, t_game *game)
{
	line = skip_spaces(line);
	if (*line == '\0')
		return (EXIT_SUCCESS);
	if (parse_texture(line, game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (parse_color(line, game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_texture_colors(t_game *game)
{
	char	*line;

	line = get_next_line(game->fd);
	while (line)
	{
		if (parse_line(line, game) == EXIT_FAILURE)
		{
			free(line);
			return (EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(game->fd);
	}
	if (check_texture(game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_color(game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

bool	parse_file(char *file_name, t_game *game)
{
	game->fd = open(file_name, O_RDONLY);
	if (check_texture_colors(game) == EXIT_FAILURE)
	{
		flush_gnl(game->fd);
		close(game->fd);
		return (false);
	}
	flush_gnl(game->fd);
	close(game->fd);
	game->map_fd = open(file_name, O_RDONLY);
	if (check_map(game, file_name) == EXIT_FAILURE)
	{
		flush_gnl(game->map_fd);
		close(game->map_fd);
		return (false);
	}
	flush_gnl(game->map_fd);
	close(game->map_fd);
	return (true);
}
