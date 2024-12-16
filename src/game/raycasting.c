#include "cub3d.h"

void draw_floor_and_ceiling(t_game *game, void *img)
{
    int x, y;

    // Dessiner le plafond (Ceiling)
    y = 0;
    while (y < WIN_HEIGHT / 2)
    {
        x = 0;
        while (x < WIN_WIDTH)
        {
            draw_pixel(img, x, y, (game->ceiling_color[0] << 16) |
                                       (game->ceiling_color[1] << 8) |
                                       (game->ceiling_color[2]));
            x++;
        }
        y++;
    }

    // Dessiner le sol (Floor)
    while (y < WIN_HEIGHT)
    {
        x = 0;
        while (x < WIN_WIDTH)
        {
            draw_pixel(img, x, y, (game->floor_color[0] << 16) |
                                      (game->floor_color[1] << 8) |
                                      (game->floor_color[2]));
            x++;
        }
        y++;
    }
}

void cast_ray(t_game *game, void *img, int x)
{
    int mapX, mapY, lineHeight, drawStart, drawEnd;
    double wallX;
    int texX, texY, color;
    char *texture_data;
    int bpp, size_line, endian;

    // Calcul initial du rayon
    game->ray.camX = 2 * x / (double)WIN_WIDTH - 1;
    game->ray.rayX = game->player.dirX + game->ray.planeX * game->ray.camX;
    game->ray.rayY = game->player.dirY + game->ray.planeY * game->ray.camX;
    game->ray.deltaDistX = fabs(1 / game->ray.rayX);
    game->ray.deltaDistY = fabs(1 / game->ray.rayY);

    calc_step(game, &game->ray, &mapX, &mapY);
    dda(game, &game->ray, &mapX, &mapY);

    // Calcul de la distance perpendiculaire au mur
    if (game->ray.side == 0)
        game->ray.perpWallDist = (mapX - game->player.posX + (1 - game->ray.stepX) / 2) / game->ray.rayX;
    else
        game->ray.perpWallDist = (mapY - game->player.posY + (1 - game->ray.stepY) / 2) / game->ray.rayY;

    // Calcul de la hauteur de ligne projetée
    lineHeight = (int)(WIN_HEIGHT / game->ray.perpWallDist);
    drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
    if (drawStart < 0) drawStart = 0;
    drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
    if (drawEnd >= WIN_HEIGHT) drawEnd = WIN_HEIGHT - 1;

    // Sélection de la texture
    if (game->ray.side == 0 && game->ray.rayX < 0)
        texture_data = mlx_get_data_addr(game->textures.north_img, &bpp, &size_line, &endian);
    else if (game->ray.side == 0 && game->ray.rayX > 0)
        texture_data = mlx_get_data_addr(game->textures.south_img, &bpp, &size_line, &endian);
    else if (game->ray.side == 1 && game->ray.rayY < 0)
        texture_data = mlx_get_data_addr(game->textures.west_img, &bpp, &size_line, &endian);
    else
        texture_data = mlx_get_data_addr(game->textures.east_img, &bpp, &size_line, &endian);

    // Calcul de wallX
    if (game->ray.side == 0)
        wallX = game->player.posY + game->ray.perpWallDist * game->ray.rayY;
    else
        wallX = game->player.posX + game->ray.perpWallDist * game->ray.rayX;
    wallX -= floor(wallX);

    // Calcul de texX
    texX = (int)(wallX * (double)game->textures.tex_width);
    if (game->ray.side == 0 && game->ray.rayX > 0)
        texX = game->textures.tex_width - texX - 1;
    if (game->ray.side == 1 && game->ray.rayY < 0)
        texX = game->textures.tex_width - texX - 1;

    // Interpolation verticale pour texY
    double step = 1.0 * game->textures.tex_height / lineHeight;
    double texPos = (drawStart - WIN_HEIGHT / 2 + lineHeight / 2) * step;

    for (int y = drawStart; y < drawEnd; y++)
    {
        texY = (int)texPos & (game->textures.tex_height - 1);
        texPos += step;

        // Extraction de la couleur depuis la texture
        color = *(int *)(texture_data + (texY * size_line + texX * (bpp / 8)));

        // Assombrir les murs est-ouest
        if (game->ray.side == 1)
            color = (color >> 1) & 0x7F7F7F;

        draw_pixel(img, x, y, color);
    }
}







void raycaster(t_game *game)
{
    void *img;
    int x;

    // Création d'une nouvelle image pour chaque frame
    img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
    if (!img)
    {
        ft_putendl_fd("Error\nFailed to create image.", 2);
        exit(EXIT_FAILURE);
    }

    // Dessiner le sol et le plafond
    draw_floor_and_ceiling(game, img);

    // Lancer le raycasting pour les murs
    x = 0;
    while (x < WIN_WIDTH)
    {
        cast_ray(game, img, x); // Appel de cast_ray pour chaque colonne
        x++;
    }

    // Affichage de l'image dans la fenêtre
    mlx_put_image_to_window(game->mlx, game->win, img, 0, 0);

    // Libération de l'image pour éviter les fuites de mémoire
    mlx_destroy_image(game->mlx, img);
}





