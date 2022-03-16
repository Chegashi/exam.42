#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_cmds
{
	char			**arg;
	int				std_in;
	int				std_out;
	int				ac;
	struct s_cmds	*next;
}				t_cmds;

int	ft_strlen(char *str)
{
	char *itr = str;
	while (*itr++)
		;
	return (itr - str -1);
}

void ft_putsr(char *str)
{
	write(1, str, ft_strlen(str));
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

t_cmds *init_cmd(int ac)
{
	t_cmds *cmd;
	cmd = (t_cmds *)malloc(sizeof(t_cmds));
	cmd->std_in = -1;
	cmd->std_out = -1;
	cmd->ac = 0;
	cmd->arg = (char**)malloc(sizeof(char *) * ac);
	cmd->next = NULL;
	return (cmd);
}

void add_cmd(t_cmds *cmd, char *av)
{
	if (!cmd->ac && cmd->std_in < 0)
		cmd->std_in = 1;
	if (!cmd->ac && cmd->std_out < 0)
		cmd->std_out = 0;
	cmd->arg[(cmd->ac)++] = ft_strdup(av);
}
void	ft_pipe(t_cmds **cmd, int ac)
{
	int fds[2];

	pipe(fds);
	(*cmd)->std_in = fds[0];
	(*cmd)->next = init_cmd(ac);
	(*cmd)->next->ac = 0;
	(*cmd)->next->std_out = fds[1];
	(*cmd)->next->std_in = 0;
	(*cmd) = (*cmd)->next;
}

int main(int ac, char **av, char **env)
{
	t_cmds *head;
	t_cmds *current;
	int		start = 1;

	ac--;
	current = init_cmd(ac);
	head = current;
	while (*++av)
	{
		if(strcmp(*av, ";") && strcmp(*av, "|"))
		{
			add_cmd(current, *av);
			continue;
		}
		if (*av && strcmp(*av, "|"))
			ft_pipe(&current, ac);
		if (*av && strcmp(*av, ";"))
		{
			current->next = init_cmd(ac);
			current = current->next;
		}
	}

	current = head;
	while (current)
	{
		for (int i = 0; i < current->ac; i++)
		{
			printf("%s ", current->arg[i]);
		}
		printf("\n");
		current = current->next;
	}
	system("leaks microshell");
	return (0);
}