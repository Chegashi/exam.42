#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	char *s;
	int fd;

	(void)ac;
	(void)av;
	fd = open(av[1], O_RDONLY);
	while ((s = get_next_line(fd)))
	{
		write (1, s, strlen(s));
		free(s);
	}
	return (0);
}