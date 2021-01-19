#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int     main(int argc, char **argv)
{
    int fd = open("test.txt",O_RDONLY);
    char *line;

    while (get_next_line(fd, &line) > 0)
    {
        get_next_line(fd, &line);
        printf("%s\n", line);
    }
}