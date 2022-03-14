#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define Error_1 "Error: FATAL\n"

typedef struct s_token
{
	char	**cmd;
	int		std_input;
	int		std_output;
}	t_token;

int ft_strlen(char *s)
{
	char *iter = s;
	while (*iter++)
		;
	return (iter - s - 1);
}

char *ft_strdup(char *s)
{
	char *str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	char *iter = str;
	while (*s)
		*iter++ = *s++;
	*iter = 0;
	return (str);
}

int	print_error(char *error)
{
	write(1, error, ft_strlen(error));
		return (1);
}

t_token	*init_tokens(char **av, int ac)
{
	t_token	*tokens;
	int		k = 0;

	tokens = (t_token*)malloc(sizeof(t_token) * ac);
	for (int i = 0; i < ac; i++)
	{
		tokens[i].cmd = (char**)malloc(sizeof(char*) * ac);
		for (int j = 0; av[k] && strcmp(av[k], ";") && strcmp(av[k], "|"); j++)
		{
			if (av[k])
			{
				printf("%s\n", av[k]);
				tokens[i].cmd[j] = ft_strdup(av[k++]);
			}
		}
	}

	// t = (t_token*)malloc(sizeof(t_token));
	// t->cmd = (char**)malloc(sizeof(char*) * 1024);
	// if (!t || !t->cmd)
	// 	print_error(Error_1);
	// for (size_t i = 0; i < 1024; i++)
	// 	t->cmd[i] = NULL;	
	// t->std_input = 1;
	// t->std_output = 0;
	return (tokens);
}

// void	add_cmd(char *av, t_token *token)
// {
// 	static int i = 0;
// 	if (!i)
// 		token->cmd = ' ';
// 	for(; av[i] && av[i] != ';' && av[i] != '|'; i++)
// 		token->cmd[i] = av[i];
// 	token->cmd[i] = 0;
// }

// void	exec_cmd(t_token *curent)
// {
// 	write(1, curent->cmd, ft_strlen(curent->cmd));
// 	write(1, "\n", 1);
// }

// void	ft_pipe(t_token *token)
// {
// 	int fds[2];

// 	pipe(fds);
// 	token->next =  init_token();
// 	token->next->std_input = fds[0];
// 	token->std_output = fds[1];
// }

int main(int ac, char **av)
{
	t_token *tokens;

	tokens = init_tokens(av + 1, ac);
	return (0);
}
