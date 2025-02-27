/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:42:17 by lgalloux          #+#    #+#             */
/*   Updated: 2025/01/18 16:42:18 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**build_bigmap(t_game *game)
{
	char	**bigmap;
	int		total_height;
	int		y;

	y = 0;
	total_height = game->map_height + 2;
	bigmap = allocate_bigmap_memory(total_height);
	if (!bigmap)
		return (NULL);
	while (y < total_height)
	{
		bigmap[y] = allocate_bigmap_row(game->map_width + 2);
		if (!bigmap[y])
			return (NULL);
		y++;
	}
	return (bigmap);
}
