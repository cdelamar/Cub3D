/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:42:33 by lgalloux          #+#    #+#             */
/*   Updated: 2025/01/18 16:42:35 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_texture_paths(t_game *game)
{
	if (game->textures.north)
	{
		free(game->textures.north);
		game->textures.north = NULL;
	}
	if (game->textures.south)
	{
		free(game->textures.south);
		game->textures.south = NULL;
	}
	if (game->textures.west)
	{
		free(game->textures.west);
		game->textures.west = NULL;
	}
	if (game->textures.east)
	{
		free(game->textures.east);
		game->textures.east = NULL;
	}
}

int	render_frame(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	raycaster(game);
	return (0);
}

int	close_mlx(t_game *game)
{
	free_textures(game);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_freetab(game->map);
	free_texture_paths(game);
	free(game->mlx);
	free(game);
	exit(0);
}

void	ft_mlx(t_game *game)
{
	mlx_loop_hook(game->mlx, &render_frame, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &player_controls, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &close_mlx, game);
	mlx_loop(game->mlx);
}
