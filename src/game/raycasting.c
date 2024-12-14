#include "cub3d.h"

void	cast_ray(t_game *game, void *img, int x)
{
	int		mapX;
	int		mapY;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;

	game->ray.camX = 2 * x / (double)WIN_WIDTH - 1;
	game->ray.rayX = game->player.dirX + game->ray.planeX * game->ray.camX;
	game->ray.rayY = game->player.dirY + game->ray.planeY * game->ray.camX;
	game->ray.deltaDistX = fabs(1 / game->ray.rayX);
	game->ray.deltaDistY = fabs(1 / game->ray.rayY);
	calc_step(game, &game->ray, &mapX, &mapY);
	dda(game, &game->ray, &mapX, &mapY);
	lineHeight = calc_wall_dist(game, &game->ray, mapX, mapY);
	drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
	if (drawEnd >= WIN_HEIGHT)
		drawEnd = WIN_HEIGHT - 1;
	color = (game->ray.side == 0) ? 0xFF0000 : 0x800000; //  ternaire ici
	draw_line(img, x, drawStart, drawEnd, color);
}


void	raycaster(t_game *game)
{
	void	*img;
	int		x;

	img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	x = 0;
	while (x < WIN_WIDTH)
	{
		cast_ray(game, img, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, img, 0, 0);
	mlx_destroy_image(game->mlx, img);
}

