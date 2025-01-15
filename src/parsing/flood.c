#include "cub3d.h"

bool	is_closed(char **bigmap, int y, int x)
{
	printf("la value de y et x est: %d, %d\n", y, x);
	if (ft_strchr("X ", bigmap[y][x]))
		return (false);
	bigmap[y][x] *= -1;
	if (ft_strchr("0", bigmap[y + 1][x]))
		is_closed(bigmap, y + 1, x);
	if (ft_strchr("0", bigmap[y][x + 1]))
		is_closed(bigmap, y, x + 1);
	if (ft_strchr("0", bigmap[y - 1][x]))
		is_closed(bigmap, y - 1, x);
	if (ft_strchr("0", bigmap[y][x - 1]))
		is_closed(bigmap, y, x - 1);
	return (true);
}
