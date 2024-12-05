#include "cub3d.h"

bool is_empty_line(char *line)
{
    if (!line)
        return (true);
    while (*line)
    {
        if (*line != ' ' && *line != '\n')
            return (false);
        line++;
    }
    return (true);
}

bool is_map_line(char *line)
{
    int i;

    line = skip_spaces(line);
    i = 0;
    while (line [i] && line[i] != '\n')
    {
        if (line[i] != '1')
            return (false);
        i++;
    }
    return (true);
}

int find_map_start(int fd)
{
    char *line;
    int line_num = 0;

    while ((line = get_next_line(fd)))
    {
        line_num++;
        // printf("Processing line %d: \"%s\"\n", line_num, line);

        if (line && *line != '\0' && (is_empty_line(line) == false) && is_map_line(skip_spaces(line)))
        {
            printf("Map start found on line %d: \"%s\"\n", line_num, line);
            free(line);
            return (line_num); // Return the first valid map line number
        }

        free(line);
    }
    printf("No valid map line found.\n");
    return (-1);
}