#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int		ft_strlen(char *s)
{
	char *start;

	start = s;
	while (*s++)
		;
	return (s - start);
}

char	*ft_strdup(char *s)
{
	int 	n;
	char	*str;
	char	*start;

	n = ft_strlen(s);
	str = malloc(sizeof(char) * (1 + n));
	start = str;
	while(*s)
		*str++ = *s++;
	*str = 0;
	return (start);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int n;
	char *str;
	int i;

	n = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char*)malloc(sizeof(char) * n);
	i = -1;
	while(*s1)
		str[++i] = *s1++;
	while(*s2)
		str[++i] = *s2++;
	str[++i] = 0;
	return (str);
}

int	ft_strchr(char *s, char c)
{
	char	*start;

	start = s;
	while(*s)
		if (*s++ == c)
			return (s - start);
	return (-1);
}

char	*ft_fill(char **line)
{
	int i;
	char *tmp;
	char	*rest;
	int indice;
	int	len;

	tmp =  ft_strdup(*line);
	indice = ft_strchr(*line, '\n');
	*line = (char*)malloc(sizeof(char) * (indice + 1));
	i = -1;
	while (++i < indice)
		(*line)[i] = tmp[i];
	len = ft_strlen(tmp);
	rest = (char*)malloc(sizeof(char) * (len - indice + 1));
	i = -1;
	while (++i < len)
		rest[i] = tmp[i + indice];
	rest[i] = 0;
	return (rest);
}

int get_next_line(int fd, char **line)
{
	static char *rest = NULL;
	char 		*buffer;
	int 		n;

	if (fd < 0 || !line || BUFFER_SIZE < 0 || read(fd, NULL, 0))
			return (-1);
	if (!rest)
			rest = ft_strdup("");
	while (1337)
	{
		buffer = (char*)malloc(sizeof(char) *  (BUFFER_SIZE + 1));
		n = read(fd, buffer, BUFFER_SIZE);
		buffer[n] = 0;
		*line = ft_strjoin(rest, buffer);
		free(rest);
		if (ft_strchr(*line, '\n') > 0)
		{
			rest = ft_fill(line);
			return (1);
		}
		if (!n)
			return (0);
		rest = ft_strdup("");
	}
	return (n);
}

int main()
{
	char **s;
	get_next_line(0, s);
	printf("|%s|", *s);
	return (0);
}
