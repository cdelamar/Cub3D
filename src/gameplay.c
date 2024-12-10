#include "cub3d.h"

int	close_mlx (t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_game(game);
	free(game);
	exit(0);
}

int	player_controls(int keysym, t_game *game)
{
	(void)game;
	if (keysym == KEY_ESCAPE)
	{
		close_mlx(game);
		exit (0);
		// free_img_map(img);
		// on_destroy(img);
	}
	// if (keysym == ARROW_UP)
	// 	player_move(img, img->player_y - 1, img->player_x);
	// if (keysym == ARROW_DOWN)
	// 	player_move(img, img->player_y + 1, img->player_x);
	// if (keysym == ARROW_LEFT)
	// 	player_move(img, img->player_y, img->player_x - 1);
	// if (keysym == ARROW_RIGHT)
	// 	player_move(img, img->player_y, img->player_x + 1);
	return (0);
}