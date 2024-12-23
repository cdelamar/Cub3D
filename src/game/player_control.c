#include "cub3d.h"

void	move_player(t_game *game, double move_speed)
{
	double new_x = game->player.posX + game->player.dirX * move_speed;
	double new_y = game->player.posY + game->player.dirY * move_speed;

    if ((int)game->player.posY >= 0 && (int)game->player.posY < game->map_height &&
        (int)new_x >= 0 && (int)new_x < game->map_width &&
        game->map[(int)game->player.posY][(int)new_x] == '0')
    {
        game->player.posX = new_x;
    }

    if ((int)new_y >= 0 && (int)new_y < game->map_height &&
        (int)game->player.posX >= 0 && (int)game->player.posX < game->map_width &&
        game->map[(int)new_y][(int)game->player.posX] == '0')
    {
        game->player.posY = new_y;
    }
}

void	strafe_player(t_game *game, double move_speed)
{
	double	strafeX;
	double	strafeY;

	strafeX = game->player.dirY * move_speed;
	strafeY = -game->player.dirX * move_speed;
	if (game->map[(int)game->player.posY]
		[(int)(game->player.posX + strafeX)] == '0')
		game->player.posX += strafeX;
	if (game->map[(int)(game->player.posY + strafeY)]
		[(int)game->player.posX] == '0')
		game->player.posY += strafeY;
}

void	rotate_player(t_game *game, double rot_speed)
{
	double oldDirX = game->player.dirX;
	double oldPlaneX = game->ray.planeX;

	game->player.dirX = game->player.dirX * cos(rot_speed)
		- game->player.dirY * sin(rot_speed);
	game->player.dirY = oldDirX * sin(rot_speed) + game->player.dirY * cos(rot_speed);

	game->ray.planeX = game->ray.planeX * cos(rot_speed)
		- game->ray.planeY * sin(rot_speed);
	game->ray.planeY = oldPlaneX * sin(rot_speed) + game->ray.planeY * cos(rot_speed);
}

int	player_controls(int keycode, t_game *game)
{
	const double move_speed = 0.1;
	const double rot_speed = 0.05;

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
