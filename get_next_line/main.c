#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		ret;
	int		fd;

	if (argc == 0)
		return(0);
//	fd = 0;

	fd = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_RDONLY);
	int fd3 = open(argv[3], O_RDONLY);


/*	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("get_next_line : %s\n", line);
		printf("return value : %d\n\n", ret);
		free(line);
	}
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n", ret);
	free(line);
	char *line2;
	ret = get_next_line(fd, &line2);
	printf("get_next_line : %s\n", line2);
	printf("return value : %d\n", ret);
	free(line2);
	char *line3;
	ret = get_next_line(fd, &line3);
	printf("get_next_line : %s\n", line3);
	printf("return value : %d\n", ret);
	free(line3);
*/

	ret = get_next_line(fd, &line);
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n\n", ret);
	free(line);

	ret = get_next_line(fd2, &line);
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n\n", ret);
	free(line);

	ret = get_next_line(fd3, &line);
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n\n", ret);
	free(line);

	ret = get_next_line(fd, &line);
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n\n", ret);
	free(line);

	ret = get_next_line(fd2, &line);
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n\n", ret);
	free(line);

	ret = get_next_line(fd3, &line);
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n\n", ret);
	free(line);

	ret = get_next_line(fd, &line);
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n", ret);
	free(line);

	ret = get_next_line(fd, &line);
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n", ret);
	free(line);
	while(1)
		;

	return (0);
}
