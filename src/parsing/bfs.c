/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:42:52 by lgalloux          #+#    #+#             */
/*   Updated: 2025/01/18 16:42:54 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		printf("%s\n", map[y]);
		y++;
	}
	write(1, "\n", 1);
}

bool	map_is_closed(t_game *game)
{
	char	**bigmap;
	int		closed;
	int		i;

	closed = 1;
	i = 0;
	bigmap = build_bigmap(game);
	if (!bigmap)
	{
		ft_putendl_fd("Error\nMemory allocation bigmap", 2);
		free(bigmap);
		return (false);
	}
	copy_map_into_bigmap(game, bigmap);
	if (find_player_spawn(game, bigmap) == EXIT_FAILURE)
		error_pos(game, bigmap);
	closed = is_closed(bigmap, game->player.pos_y, game->player.pos_x, 0);
	while (bigmap[i])
	{
		free(bigmap[i]);
		i++;
	}
	free(bigmap);
	return (closed);
}
