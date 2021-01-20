#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int fd1;
    char *line;

    fd1 = open(argv[1], O_RDONLY);
    while (get_next_line(fd1, &line) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
    printf("%s\n", line);
    free(line);
    return (0);
}
