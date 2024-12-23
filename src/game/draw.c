#include "cub3d.h"

char	*select_texture_data(t_game *game, int *bpp, int *sl, int *end)
{
	if (game->ray.side == 0 && game->ray.rayX < 0)
		return (get_texture_addr(game->textures.west_img, bpp, sl, end));
	else if (game->ray.side == 0 && game->ray.rayX > 0)
		return (get_texture_addr(game->textures.east_img, bpp, sl, end));
	else if (game->ray.side == 1 && game->ray.rayY < 0)
		return (get_texture_addr(game->textures.north_img, bpp, sl, end));
	return (get_texture_addr(game->textures.south_img, bpp, sl, end));
}

void	compute_line_dimensions(t_game *game, t_draw *d)
{
	d->height = (int)(WIN_HEIGHT / game->ray.perpWallDist);
	d->start = -(d->height) / 2 + WIN_HEIGHT / 2;
	if (d->start < 0)
		d->start = 0;
	d->end = d->height / 2 + WIN_HEIGHT / 2;
	if (d->end >= WIN_HEIGHT)
		d->end = WIN_HEIGHT - 1;
}
void	draw_column(t_game *game, void *img, int x, t_draw *d)
{
	int	y;
	int	color;

	y = d->start;
	while (y < d->end)
	{
		d->texY = (int)d->texPos & (game->textures.tex_height - 1);
		d->texPos += d->step;
		color = *(int *)(d->texture_data
				+ (d->texY * d->size_line + d->texX * (d->bpp / 8)));
		if (game->ray.side == 1)
			color = (color >> 1) & 0x7F7F7F;
		draw_pixel(img, x, y, color);
		y++;
	}
}

void	calc_wall_dist(t_game *game)
{
	if (game->ray.side == 0)
		game->ray.perpWallDist = (game->mapX - game->player.posX
				+ (1 - game->ray.stepX) / 2) / game->ray.rayX;
	else
		game->ray.perpWallDist = (game->mapY - game->player.posY
				+ (1 - game->ray.stepY) / 2) / game->ray.rayY;
}

void	compute_wallX_and_texX(t_game *game, t_draw *d)
{
	if (game->ray.side == 0)
		d->wallX = game->player.posY
			+ game->ray.perpWallDist * game->ray.rayY;
	else
		d->wallX = game->player.posX
			+ game->ray.perpWallDist * game->ray.rayX;
	d->wallX -= floor(d->wallX);
	d->texX = (int)(d->wallX * (double)game->textures.tex_width);
	if ((game->ray.side == 0 && game->ray.rayX > 0)
		|| (game->ray.side == 1 && game->ray.rayY < 0))
		d->texX = game->textures.tex_width - d->texX - 1;
}