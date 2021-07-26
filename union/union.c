#include <unistd.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	char readed[255];
	int i = -1;
	int j = 0;

	if (argc == 3)
	{
		while (++i < 255)
			readed[i] = 0;
	  	while (++j < 3)
		{
			i = -1;
			while (argv[j][++i])
				if (readed[(int)argv[j][i]] == 0)
				{
					readed[(int)(argv[j][i])] = 1;
					write(1, &argv[j][i], 1);
				}
		}
		  
	}
	write(1, "\n", 1);
	return (0);
}