#include "cub3d.h"

char	*select_texture_data(t_game *game, int *bpp, int *sl, int *end)
{
	if (game->ray.side == 0 && game->ray.ray_x < 0)
		return (get_texture_addr(game->textures.west_img, bpp, sl, end));
	else if (game->ray.side == 0 && game->ray.ray_x > 0)
		return (get_texture_addr(game->textures.east_img, bpp, sl, end));
	else if (game->ray.side == 1 && game->ray.ray_y < 0)
		return (get_texture_addr(game->textures.north_img, bpp, sl, end));
	return (get_texture_addr(game->textures.south_img, bpp, sl, end));
}

void	compute_line_dimensions(t_game *game, t_draw *d)
{
	d->height = (int)(WIN_HEIGHT / game->ray.perp_walldist);
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
		d->tex_y = (int)d->tex_pos & (game->textures.tex_height - 1);
		d->tex_pos += d->step;
		color = *(int *)(d->texture_data
				+ (d->tex_y * d->size_line + d->tex_x * (d->bpp / 8)));
		if (game->ray.side == 1)
			color = (color >> 1) & 0x7F7F7F;
		draw_pixel(img, x, y, color);
		y++;
	}
}

void	calc_wall_dist(t_game *game)
{
	if (game->ray.side == 0)
		game->ray.perp_walldist = (game->map_x - game->player.pos_x
				+ (1 - game->ray.step_x) / 2) / game->ray.ray_x;
	else
		game->ray.perp_walldist = (game->map_y - game->player.pos_y
				+ (1 - game->ray.step_y) / 2) / game->ray.ray_y;
}

void	compute_wallx_and_texx(t_game *game, t_draw *d)
{
	if (game->ray.side == 0)
		d->wall_x = game->player.pos_y
			+ game->ray.perp_walldist * game->ray.ray_y;
	else
		d->wall_x = game->player.pos_x
			+ game->ray.perp_walldist * game->ray.ray_x;
	d->wall_x -= floor(d->wall_x);
	d->tex_x = (int)(d->wall_x * (double)game->textures.tex_width);
	if ((game->ray.side == 0 && game->ray.ray_x > 0)
		|| (game->ray.side == 1 && game->ray.ray_y < 0))
		d->tex_x = game->textures.tex_width - d->tex_x - 1;
}
