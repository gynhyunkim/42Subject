#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str, size_t n);
int		ft_strchr(const char *str, char c);
char	*ft_strjoin(const char *s1, const char *s2);
int	get_next_line(int fd, char **line);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif