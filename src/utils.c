#include "cub3d.h"

bool is_numbr(char *str)
{
    int i = 0;

    if (!str || *str == '\0')
        return (false);
    str = skip_spaces(str);
    while (str[i])
    {
        if (!isdigit(str[i]) && str[i] != '\n')
            return (false);
        i++;
    }
    return (true);
}

bool	is_rgb(int c)
{
	if (c >= 0 && c <= 255)
		return (true);
	else
		return (false);
}

char *skip_spaces(char *line)
{
    while (*line == ' ')
        line++;
    return line;
}