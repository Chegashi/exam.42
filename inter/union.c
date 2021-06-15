#include <unistd.h>
#include <stdio.h>
int main(int ac, char **av)
{

	if (ac == 3)
	{	
		char ascii[128];
		int i;
		int j;
		int k;
		int l;

		l = -1;
		i = -1;
		k = 0;
		while (++i <128)
			ascii[i] = 0;
		while (++k < 3)
		{
			j = -1;
			while(av[k][++j])
				if(!ascii[av[k][j]])
				{
					ascii[av[k][j]] = 1;
					write(1,&av[k][j], 1);
				}
		}
	}
	write(1, "\n", 1);
	return 0;
}