#include <unistd.h>
int main(int ac, char **av)
{
	int read[255];
	int i, j;
	for (i = 0;i < 255; i++)
		read[i] = 0;
	if (ac == 3)
	{
		for (i = 1; i < 3; i++)
			for (j = 0; av[i][j]; j++)
				read[(int)av[i][j]] |= i;
		for (i = 0; av[1][i]; i++)
			if (read[(int)av[1][i]] == (1 | 2))
			{		
				write(1, &av[1][i], 1);
				read[(int)av[1][i]] = 0;
			}
	}
	write(1, "\n", 1);
	return (0);
}
