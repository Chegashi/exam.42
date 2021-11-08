#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	*get_next_line(int fd);

int main(int ac, char **av)
{
	char *s;
	int fd;
	(void)ac;
	fd = open(av[1], O_RDONLY);
	while ((s = get_next_line(fd)))
	{
		printf("%s", s);
		free(s);
	}
	return (0);
}