#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av, char **env)
{
	execve("/bin/echo", av +1, env);
	return (0);
}
