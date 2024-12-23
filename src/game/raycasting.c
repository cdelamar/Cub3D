#include "cub3d.h"

char	*get_texture_addr(void *img, int *bpp, int *size_line, int *endian)
{
	return (mlx_get_data_addr(img, bpp, size_line, endian));
}

void	cast_ray(t_game *game, void *img, int x)
{
	t_draw	d;

	game->ray.camX = 2 * x / (double)WIN_WIDTH - 1;
	game->ray.rayX = game->player.dirX + game->ray.planeX * game->ray.camX;
	game->ray.rayY = game->player.dirY + game->ray.planeY * game->ray.camX;
	game->ray.deltaDistX = fabs(1 / game->ray.rayX);
	game->ray.deltaDistY = fabs(1 / game->ray.rayY);
	calc_step(game, &game->ray, &game->mapX, &game->mapY);
	dda(game, &game->ray, &game->mapX, &game->mapY);
	calc_wall_dist(game);
	compute_line_dimensions(game, &d);
	d.texture_data = select_texture_data(game, &d.bpp, &d.size_line, &d.endian);
	compute_wallX_and_texX(game, &d);
	d.step = (1.0 * game->textures.tex_height) / d.height;
	d.texPos = (d.start - WIN_HEIGHT / 2 + d.height / 2) * d.step;
	draw_column(game, img, x, &d);
}

void	raycaster(t_game *game)
{
	void	*img;
	int		x;

	img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img)
	{
		ft_putendl_fd("Error\nFailed to create image.", 2);
		exit(EXIT_FAILURE);
	}
	draw_floor_and_ceiling(game, img);
	x = 0;
	while (x < WIN_WIDTH)
	{
		cast_ray(game, img, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, img, 0, 0);
	mlx_destroy_image(game->mlx, img);
}
