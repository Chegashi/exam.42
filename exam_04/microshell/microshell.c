#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

typedef struct	s_cmds
{
	char	**arg;
	int		in;
	int		out;
	int		len;
	int		pipe;
}				t_cmds;

int	ft_strlen(char *str)
{
	char *itr = str;
	while (*itr++)
		;
	return (itr - str -1);
}

char *ft_strdup(char *str)
{
	char *s = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	char *iter = s;
	while (*str)
		*iter++ = *str++;
	*iter = 0;
	return (s);
}

void print_error(char *error, char *path) 
{
    write(2, error, ft_strlen(error));
	if (*path)
	{
		write(2, " ", 1);
		write(2, path, ft_strlen(path));
	}
	write(2, "\n", 1);
	exit(1);
}

t_cmds *init_cmd(int ac)
{
	t_cmds *cmd = (t_cmds*)malloc(sizeof(t_cmds) * ac);
	for (int i = 0; i < ac; i++)
	{
		cmd[i].in = 0;
		cmd[i].out = 1;
		cmd[i].len = 0;
		cmd[i].pipe = 0;
		cmd[i].arg = (char**)malloc(sizeof(char *) * ac);
		for (int j = 0; j < ac; j++)
			cmd[i].arg[j] = NULL;
	}
	return (cmd);
}

void	ft_pipe(t_cmds *cmd)
{
	int fds[2];
	pipe(fds);
	cmd->out = fds[1];
	(++cmd)->in = fds[0];
}

void ft_free(t_cmds *cmds, int ac)
{
	for (int i = 0; i < ac; i++)
	{
		for (int j = 0; j < cmds[i].len; j++)
			free(cmds[i].arg[j]);
		free(cmds[i].arg);
	}
	free (cmds);
}

void ft_exec_cmd(t_cmds *cmds, char **env)
{
	for (int i = 0; cmds[i].arg[0]; i++)
	{
		if (!strcmp(cmds[i].arg[0], "cd"))
		{
			if (cmds[i].len != 2 || cmds[i + 1].len)
				print_error("Error cd: Bad arguments", "");
			else if (chdir(cmds[i].arg[1]) != 0)
				print_error("Error cd: cannot change directory", cmds[i].arg[1]);
			continue;
		}
		if (cmds[i].pipe)
			ft_pipe(cmds + i);
		int pid = fork();
		if (pid < 0)
			print_error("Error: FATAL\n", "");
		if (!pid)
		{
			if (cmds[i].in != 0)
				if (dup2(cmds[i].in , 0) == -1)
					print_error("Error : FATAL\n", "");
			if (cmds[i].out != 1)
				if (dup2(cmds[i].out , 1) == -1)
					print_error("Error : FATAL\n", "");
			execve(cmds[i].arg[0], cmds[i].arg, env);
		}
		waitpid(0, NULL, 0);
		if (cmds[i].in)
			close(cmds[i].in);
		if (cmds[i].out != 1)
			close(cmds[i].out);
	}
}

int main(int ac, char **av, char **env)
{
	t_cmds *cmds;
	cmds = init_cmd(++ac);
	int k = 0;
	while (*++av)
	{
		if (!strcmp(*av, ";"))
		{
			if (cmds[k].arg[0])
				k++;
		}
		else if (!strcmp(*av, "|"))
			cmds[k++].pipe++;
		else
			cmds[k].arg[cmds[k].len++] = ft_strdup(*av);
	}
	ft_exec_cmd(cmds, env);
 	ft_free(cmds, ac);
	return (0);
}