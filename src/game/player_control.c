/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:42:38 by lgalloux          #+#    #+#             */
/*   Updated: 2025/01/18 16:42:40 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_game *game, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * move_speed;
	new_y = game->player.pos_y + game->player.dir_y * move_speed;
	if ((int)game->player.pos_y >= 0
		&& (int)game->player.pos_y < game->map_height
		&& (int)new_x >= 0 && (int)new_x < game->map_width
		&& game->map[(int)game->player.pos_y][(int)new_x] == '0')
	{
		game->player.pos_x = new_x;
	}
	if ((int)new_y >= 0 && (int)new_y < game->map_height
		&& (int)game->player.pos_x >= 0
		&& (int)game->player.pos_x < game->map_width
		&& game->map[(int)new_y][(int)game->player.pos_x] == '0')
	{
		game->player.pos_y = new_y;
	}
}

void	strafe_player(t_game *game, double move_speed)
{
	double	strafe_x;
	double	strafe_y;

	strafe_x = game->player.dir_y * move_speed;
	strafe_y = -game->player.dir_x * move_speed;
	if (game->map[(int)game->player.pos_y]
		[(int)(game->player.pos_x + strafe_x)] == '0')
		game->player.pos_x += strafe_x;
	if (game->map[(int)(game->player.pos_y + strafe_y)]
		[(int)game->player.pos_x] == '0')
		game->player.pos_y += strafe_y;
}

void	rotate_player(t_game *game, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->ray.plane_x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed)
		- game->player.dir_y * sin(rot_speed);
	game->player.dir_y = old_dir_x * sin(rot_speed)
		+ game->player.dir_y * cos(rot_speed);
	game->ray.plane_x = game->ray.plane_x * cos(rot_speed)
		- game->ray.plane_y * sin(rot_speed);
	game->ray.plane_y = old_plane_x * sin(rot_speed)
		+ game->ray.plane_y * cos(rot_speed);
}

int	player_controls(int keycode, t_game *game)
{
	const double	move_speed = 0.1;
	const double	rot_speed = 0.05;

	if (keycode == ARROW_UP)
		move_player(game, move_speed);
	else if (keycode == ARROW_DOWN)
		move_player(game, -move_speed);
	else if (keycode == ARROW_LEFT)
		rotate_player(game, -rot_speed);
	else if (keycode == ARROW_RIGHT)
		rotate_player(game, rot_speed);
	else if (keycode == 'd' || keycode == 'D')
		strafe_player(game, -move_speed);
	else if (keycode == 'a' || keycode == 'A')
		strafe_player(game, move_speed);
	else if (keycode == KEY_ESCAPE || keycode == 'q')
		close_mlx(game);
	return (0);
}
