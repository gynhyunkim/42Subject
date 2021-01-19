#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int     main(int argc, char **argv)
{
    int fd = open("test.txt",O_RDONLY);
    char *line;

    get_next_line(fd, &line);
    printf("%s\n", line);
}