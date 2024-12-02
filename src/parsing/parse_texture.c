#include "cub3d.h"

// concerne la partie :
// NO ./path_to_the_north_texture
// SO ./path_to_the_south_texture
// WE ./path_to_the_west_texture
// EA ./path_to_the_east_texture
bool valid_texture(char *line, char **texture_path)
{
    char	*path;

	path = ft_strchr(line, ' ');
    if (!path || !file_exists(path + 1))
	{
        ft_putendl_fd(INVALID_TEXTURE, 2);
        return (false);
    }
	// stock le chemin dans le tableau pour les charger plus tard
	// (attention a bien le free)
    *texture_path = ft_strdup(path + 1);
    return (true);
}