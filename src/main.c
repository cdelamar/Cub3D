#include "cub3d.h"

int main (int argc, char **argv)
{
	if(valid_setup(argc, argv) == false)
		return(EXIT_FAILURE);
	printf("Launching Cub3d with map : %s", argv[1]);
		//cub3d(void)
	return (EXIT_SUCCESS);
}