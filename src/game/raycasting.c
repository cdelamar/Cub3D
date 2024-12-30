#include "cub3d.h"

char	*get_texture_addr(void *img, int *bpp, int *size_line, int *endian)
{
	return (mlx_get_data_addr(img, bpp, size_line, endian));
}

void	cast_ray(t_game *game, void *img, int x)
{
	t_draw	d;

	game->ray.cam_x = 2 * x / (double)WIN_WIDTH - 1;
	game->ray.ray_x = game->player.dir_x + game->ray.plane_x * game->ray.cam_x;
	game->ray.ray_y = game->player.dir_y + game->ray.plane_y * game->ray.cam_x;
	game->ray.delta_dist_x = fabs(1 / game->ray.ray_x);
	game->ray.delta_dist_y = fabs(1 / game->ray.ray_y);
	calc_step(game, &game->ray, &game->map_x, &game->map_y);
	dda(game, &game->ray, &game->map_x, &game->map_y);
	calc_wall_dist(game);
	compute_line_dimensions(game, &d);
	d.texture_data = select_texture_data(game, &d.bpp, &d.size_line, &d.endian);
	compute_wallx_and_texx(game, &d);
	d.step = (1.0 * game->textures.tex_height) / d.height;
	d.tex_pos = (d.start - WIN_HEIGHT / 2 + d.height / 2) * d.step;
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
