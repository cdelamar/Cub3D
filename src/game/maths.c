#include "cub3d.h"

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

void	draw_line(void *img, int x, int start, int end, int color)
{
	int	y;

	y = start;
	while (y < end)
	{
		draw_pixel(img, x, y, color);
		y++;
	}
}

void	calc_step(t_game *game, t_ray *ray, int *mapX, int *mapY)
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

void	dda(t_game *game, t_ray *ray, int *mapX, int *mapY)
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

		if (*mapY < 0 || *mapY >= game->map_height || *mapX < 0 || *mapX >= game->map_width)
		{
			ray->hit = 1;
			break;
		}

		if (game->map[*mapY][*mapX] != '0')
			ray->hit = 1;
	}
}
