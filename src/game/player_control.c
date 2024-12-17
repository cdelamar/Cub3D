#include "cub3d.h"

void	move_player(t_game *game, double move_speed)
{
	double newX = game->player.posX + game->player.dirX * move_speed;
	double newY = game->player.posY + game->player.dirY * move_speed;

	// Collision check before moving forward/backward
	if (game->map[(int)newX][(int)game->player.posY] == '0')
		game->player.posX = newX;
	if (game->map[(int)game->player.posX][(int)newY] == '0')
		game->player.posY = newY;
}

void	strafe_player(t_game *game, double move_speed)
{
	double strafeX = game->player.dirY * move_speed; // Perpendicular direction
	double strafeY = -game->player.dirX * move_speed;

	// Collision check before strafing
	if (game->map[(int)(game->player.posX + strafeX)][(int)game->player.posY] == '0')
		game->player.posX += strafeX;
	if (game->map[(int)game->player.posX][(int)(game->player.posY + strafeY)] == '0')
		game->player.posY += strafeY;
}

void	rotate_player(t_game *game, double rot_speed)
{
	double oldDirX = game->player.dirX;
	double oldPlaneX = game->ray.planeX;

	// Rotate the player's direction vector
	game->player.dirX = game->player.dirX * cos(rot_speed) - game->player.dirY * sin(rot_speed);
	game->player.dirY = oldDirX * sin(rot_speed) + game->player.dirY * cos(rot_speed);

	// Rotate the camera plane
	game->ray.planeX = game->ray.planeX * cos(rot_speed) - game->ray.planeY * sin(rot_speed);
	game->ray.planeY = oldPlaneX * sin(rot_speed) + game->ray.planeY * cos(rot_speed);
}

int	player_controls(int keycode, t_game *game)
{
	const double move_speed = 0.1; // Adjust speed as necessary
	const double rot_speed = 0.05; // Adjust rotation speed as necessary

	if (keycode == ARROW_UP)       // Forward
		move_player(game, move_speed);
	else if (keycode == ARROW_DOWN) // Backward
		move_player(game, -move_speed);
	else if (keycode == ARROW_LEFT) // Rotate left
		rotate_player(game, -rot_speed);
	else if (keycode == ARROW_RIGHT) // Rotate right
		rotate_player(game, rot_speed);
	else if (keycode == 'a' || keycode == 'A') // Strafe left
		strafe_player(game, -move_speed);
	else if (keycode == 'd' || keycode == 'D') // Strafe right
		strafe_player(game, move_speed);
	else if (keycode == KEY_ESCAPE || keycode == 'q')           // Exit game
		close_mlx(game);
	return (0);
}
