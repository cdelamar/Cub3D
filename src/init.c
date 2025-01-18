/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:43:45 by lgalloux          #+#    #+#             */
/*   Updated: 2025/01/18 16:43:46 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_player *player)
{
	player->pos_x = -1;
	player->pos_y = -1;
	player->dir_x = -1;
	player->dir_y = 0;
	player->time = 0;
	player->old_time = 0;
}

void	init_ray(t_ray *ray)
{
	ray->cam_x = 0;
	ray->ray_x = 0;
	ray->ray_y = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->perp_walldist = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->plane_x = 0;
	ray->plane_y = 0.66;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	init_game(t_game *game)
{
	game->textures.north = NULL;
	game->textures.south = NULL;
	game->textures.west = NULL;
	game->textures.east = NULL;
	game->textures.north_img = NULL;
	game->textures.south_img = NULL;
	game->textures.west_img = NULL;
	game->textures.east_img = NULL;
	game->textures.tex_width = 0;
	game->textures.tex_height = 0;
	game->floor_color[0] = -1;
	game->floor_color[1] = -1;
	game->floor_color[2] = -1;
	game->ceiling_color[0] = -1;
	game->ceiling_color[1] = -1;
	game->ceiling_color[2] = -1;
	game->map = NULL;
	game->map_buffer = NULL;
	game->mlx = NULL;
	init_player(&game->player);
	init_ray(&game->ray);
}
