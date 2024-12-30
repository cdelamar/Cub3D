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

void	calc_step(t_game *game, t_ray *ray, int *map_x, int *map_y)
{
	*map_x = (int)game->player.pos_x;
	*map_y = (int)game->player.pos_y;
	if (ray->ray_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.pos_x - *map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x
			= (*map_x + 1.0 - game->player.pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.pos_y - *map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y
			= (*map_y + 1.0 - game->player.pos_y) * ray->delta_dist_y;
	}
}

void	dda(t_game *game, t_ray *ray, int *map_x, int *map_y)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			*map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			*map_y += ray->step_y;
			ray->side = 1;
		}
		if (*map_y < 0 || *map_y >= game->map_height
			|| *map_x < 0 || *map_x >= game->map_width)
		{
			ray->hit = 1;
			break ;
		}
		if (game->map[*map_y][*map_x] != '0')
			ray->hit = 1;
	}
}
