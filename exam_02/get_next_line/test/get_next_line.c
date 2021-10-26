#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	ft_is_line(char *str)
{
	char	*iter;

	iter = str;
	while (*iter)
		if (*iter++ == '\n')
			return (iter - str -1);
	return (-1);
}

int	ft_strlen(char *str)
{
	char *iter;

	iter = str;
	while (*iter++)
		;
	return (iter - str -1);
}

char	*ft_strdup(char *s)
{
	int		n;
	char	*iter;
	char	*str;

	n = ft_strlen(s);
	str = (char*)malloc(sizeof(char) * (n + 1));
	iter = str;
	while (*s)
		*iter++ = *s++;
	*iter = 0;
	return (str);
}

char *ft_strjoin(char *s1, char *s2)
{
	int		n;
	char	*ret;
	char	*iter;

	n = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char*)malloc(sizeof(char) * n);
	iter = ret;
	while (*s1)
		*iter++ = *s1++;
	while (*s2)
		*iter++ = *s2++;
	*iter = 0;
	return (ret);
}

char	*ft_fill(char **line, char **rest)
{
	char	*str;
	int		indice;
	int		len;
	char	*iter;

	str = ft_strdup(*line);
	free(*line);
	len = ft_strlen(str);
	indice = ft_is_line(str);
	*line = (char*)malloc(sizeof(char) * (indice + 2));
	iter = *line;
	while (*str && *str != '\n')
		*iter++ = *str++;
	*iter++ = *str++;
	*iter = 0;
	*rest = (char*)malloc(sizeof(char) * (len - indice + 1));
	iter = *rest;
	while (*str)
		*iter++ = *str++;
	*iter = 0;
	free(str - len);
	return	(*line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest = NULL;
	char		*tmp;
	char		*buffer;
	int			n;

	if (!rest)
		rest = ft_strdup("");
	line = ft_strdup(rest);
	free(rest);
	rest = NULL;
	while(42)
	{
		if(ft_is_line(line) >= 0)
			return (ft_fill(&line, &rest));
		buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		n = read(fd, buffer, BUFFER_SIZE);
		buffer[n] = 0;
		tmp = ft_strjoin(line, buffer);
		free(line);
		free(buffer);
		line = tmp;
		if (!n && *line == 0)
		{	
			free(line);
			return (NULL);
		}
		if (!n)
			return(line);
		
	}
}


