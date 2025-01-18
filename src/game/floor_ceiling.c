/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:42:31 by lgalloux          #+#    #+#             */
/*   Updated: 2025/01/18 16:42:32 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_ceiling(t_game *game, void *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			draw_pixel(img, x, y, (game->ceiling_color[0] << 16)
				| (game->ceiling_color[1] << 8)
				| (game->ceiling_color[2]));
			x++;
		}
		y++;
	}
}

static void	draw_floor(t_game *game, void *img)
{
	int	x;
	int	y;

	y = WIN_HEIGHT / 2;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			draw_pixel(img, x, y, (game->floor_color[0] << 16)
				| (game->floor_color[1] << 8)
				| (game->floor_color[2]));
			x++;
		}
		y++;
	}
}

void	draw_floor_and_ceiling(t_game *game, void *img)
{
	draw_ceiling(game, img);
	draw_floor(game, img);
}
