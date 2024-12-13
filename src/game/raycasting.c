#include "cub3d.h"

/*
** draw_pixel: Engraves a single pixel of a chosen color upon the canvas.
*/
void	draw_pixel(void *data_addr, int x, int y, int color)
{
	char	*pixel;
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;

	data = mlx_get_data_addr(data_addr, &bpp, &size_line, &endian);
	pixel = data + (y * size_line + x * (bpp / 8));
	*(int *)pixel = color;
}

static void	draw_line(void *img, int x, int start, int end, int color)
{
	int	y;

	y = start;
	while (y < end)
	{
		draw_pixel(img, x, y, color);
		y++;
	}
}

static void	calc_step(t_game *game, t_ray *ray, int *mapX, int *mapY)
{
	*mapX = (int)game->player.posX;
	*mapY = (int)game->player.posY;
	if (ray->rayX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (game->player.posX - *mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (*mapX + 1.0 - game->player.posX) * ray->deltaDistX;
	}
	if (ray->rayY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (game->player.posY - *mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (*mapY + 1.0 - game->player.posY) * ray->deltaDistY;
	}
}

static void	dda(t_game *game, t_ray *ray, int *mapX, int *mapY)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			*mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			*mapY += ray->stepY;
			ray->side = 1;
		}
		if (game->map[*mapX] && game->map[*mapX][*mapY] && game->map[*mapX][*mapY] != '0')
			ray->hit = 1;
	}
}

static int	calc_wall_dist(t_game *game, t_ray *ray, int mapX, int mapY)
{
	double	perpWallDist;
	int		lineHeight;

	if (ray->side == 0)
		perpWallDist = (mapX - game->player.posX + (1 - ray->stepX) / 2) / ray->rayX;
	else
		perpWallDist = (mapY - game->player.posY + (1 - ray->stepY) / 2) / ray->rayY;
	lineHeight = (int)(WIN_HEIGHT / perpWallDist);
	return (lineHeight);
}

/*
** cast_ray: A single ray is cast
**  - Calculate direction
**  - Run DDA
**  - Compute wall height
**  - Draw the line
*/
static void	cast_ray(t_game *game, void *img, int x)
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
	color = (game->ray.side == 0) ? 0xFF0000 : 0x800000;
	draw_line(img, x, drawStart, drawEnd, color);
}

static void	forge_frame(t_game *game)
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

void	raycast(t_game *game, t_player *player, t_ray *ray)
{
	(void)player;
	(void)ray;
	forge_frame(game);
}
