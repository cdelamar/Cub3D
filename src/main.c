#include "cub3d.h"

int main (int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Please insert 1 map file name : ./cub3d <map.cub>\n");
		return (EXIT_FAILURE);
	}
	printf("Launching Cub3d with map : %s", argv[1]);
		//cub3d(void)
	return (EXIT_SUCCESS);
}