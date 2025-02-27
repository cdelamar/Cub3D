/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:43:15 by lgalloux          #+#    #+#             */
/*   Updated: 2025/01/18 16:43:17 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_closed(char **bigmap, int y, int x, int depth)
{
	if (ft_strchr("X ", bigmap[y][x]))
		return (false);
	bigmap[y][x] = 'O';
	if (ft_strchr("0 X", bigmap[y + 1][x]))
		if (is_closed(bigmap, y + 1, x, depth + 1) == false)
			return (false);
	if (ft_strchr("0 X", bigmap[y][x + 1]))
		if (is_closed(bigmap, y, x + 1, depth + 1) == false)
			return (false);
	if (ft_strchr("0 X", bigmap[y - 1][x]))
		if (is_closed(bigmap, y - 1, x, depth + 1) == false)
			return (false);
	if (ft_strchr("0 X", bigmap[y][x - 1]))
		if (is_closed(bigmap, y, x - 1, depth + 1) == false)
			return (false);
	return (true);
}
