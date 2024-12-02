#include "cub3d.h"

bool	file_exists(char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (false);
    close(fd);
    return (true);
}

bool	valid_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd(INVALID_ARGC, 2);
		return (false);
	}
	if (rev_strncmp(argv[1], ".cub", 4) != 0)
	{
		ft_putendl_fd(FILE_NOT_FOUND, 2);
		return (false);
	}
	if (file_exists(argv[1]) == false)
	{
		ft_putendl_fd(FILE_NOT_FOUND, 2);
		return (false);
	}
	return (true);
}

bool valid_setup(int argc, char **argv)
{
	if (valid_args(argc, argv) == false)
		return (false);

	// TODO lire le fichier dans valid_map avant de copier quoi que ce soit
	//if (valid_map() == false)
		//return fals
	return (true);
}