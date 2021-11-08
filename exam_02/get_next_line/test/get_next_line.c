#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int		ft_is_line(char *str)
{
	char	*iter;

	iter = str;
	while (*iter)
		if (*iter++ == '\n')
			return (iter - str -1);
	return (-1);
}

int		ft_strlen(char *str)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*iter;

	str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	iter = str;
	while (*s1)
		*iter++ = *s1++;
	while (*s2)
		*iter++ = *s2++;
	*iter = 0;
	return (str);
}

char	*before_end_l(char *str)
{
	int		len;
	char	*line;
	char	*iter;

	if ((len = ft_is_line(str)) < 0)
		len = ft_strlen(str);
	line = (char*)malloc(sizeof(char) * (len + 2));
	iter = line;
	while (*str && *str != '\n')
		*iter++ = *str++;
	*iter++ = *str;
	*iter = 0;
	return (line);
}

char	*after_end_l(char *str)
{
	int		indice;
	char	*line;
	char	*iter;

	indice = ft_is_line(str);
	if ((indice = ft_is_line(str)) < 0)
		return (NULL);
	line = (char*)malloc(sizeof(char) * (ft_strlen(str) - indice + 2));
	iter = line;
	str += indice + 1;
	while (*str)
		*iter++ = *str++;
	*iter = 0;
	return (line);
}

char	*ft_get_line(char **line, char **rest)
{
	char	*str;

	str = before_end_l(*line);
	*rest = after_end_l(*line);
	free(*line);
	return (str);
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
			return (ft_get_line(&line, &rest));
		buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		n = read(fd, buffer, BUFFER_SIZE);
		buffer[n] = 0;
		tmp = ft_strjoin(line, buffer);
		free(line);
		free(buffer);
		line = tmp;
		if (!n)
		{
			if (*line)
				return(line);
			else
			{
				free(line);
				return (NULL);
			}
		}
	}
}
