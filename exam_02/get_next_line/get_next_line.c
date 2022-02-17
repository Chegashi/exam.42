#include "get_next_line.h"

#include <stdio.h>

int ft_strlen(char *str)
{
	char *iter;

	iter = str;
	while (*iter++)
		;
	return (iter - str -1);
}

int ft_is_line(char *str)
{
	char *iter;

	iter = str;
	while (*iter)
		if (*iter++ == '\n')
			return (iter - str - 1);
	return (-1);
}

char *ft_strdup(char *str)
{
	char *iter;
	char *s;

	s = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	iter = s; 
	while(*str)
		*iter++ = *str++;
	*iter = 0;
	return (s);
}

char *ft_strjoin(char *s1, char* s2)
{
	char	*s;
	char	*iter;

	s = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	iter = s;
	while (*s1)
		*iter++ = *s1++;
	while (*s2)
		*iter++ = *s2++;
	*iter = 0;
	return (s);
}

char *ft_befor_endl(char *str)
{
	char *iter;
	char *s;
	int n;

	if ((n = ft_is_line(str)) < 0)
		return (ft_strdup("str"));
	s = (char*)malloc(sizeof(char) * (n + 2));
	iter = s;
	while (*str && *str != '\n')
		*iter++ = *str++;
	*iter++ = *str;
	*iter = 0;
	return (s);
}

char *ft_fill(char **line, char **rest)
{
	char *str;

	str = ft_befor_endl(*line);
	*rest = ft_strdup(*line + ft_strlen(str));
	free(*line);
	return (str);
}

char *get_next_line(int fd)
{
	char		*line;
	char 		*buffer;
	static char *rest = NULL;
	char 		*tmp;
	int			n;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, NULL, BUFFER_SIZE) > 0)
		return NULL;
	if (!rest)
		rest = ft_strdup("");
	line = ft_strdup(rest);
	free(rest);
	rest = NULL;
	while (1337)
	{
		if (ft_is_line(line) >= 0)
			return (ft_fill(&line, &rest));
		buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		n = read(fd, buffer, BUFFER_SIZE);
		buffer[n] = 0;
		tmp = ft_strjoin(line, buffer);
		free(buffer);
		free(line);
		line = tmp;
		if (!n)
		{
			if (*line)
				return (line);
			else
			{
				free(line);
				return (NULL);
			}
		}
	}

}
