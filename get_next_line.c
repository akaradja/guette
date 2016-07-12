#include <unistd.h>
#include <stdlib.h> 
#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

static char	*ligne(char *line, char *buf)
{
	int		i;
	int		j;
	char		*tmp;
	
	tmp = line;
	while (buf[i] && buf[i] != '\n')
		i++;
	line = ft_memalloc(i + ft_strlen(tmp) + 1);
	i = 0;
	j = 0;
	while (tmp[i])
	{
		line[i] = tmp[i];
		i++;
	}
	while (buf[j] != '\n' && buf[j])
	{
		line[i] = buf[j];
		i++;
		j++;
	}
	free(tmp);
	return (line);
}

void	cut(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\n')
		i++;
	buf[i] = 0;
}

int	get_next_line(int const fd, char **line)
{
	char	*buf;
	int	ret;
	char	*test;

	test = NULL;
	*line = ft_memalloc(sizeof(char*));
	buf = ft_strnew(BUFF_SIZE + 1);
	while (ret = read(fd, buf, BUFF_SIZE) && !test)
	{
		if (ret < 0)
			return (-1);
		if (test = ft_strchr(buf, '\n'))
			cut(buf);
		printf("%s\n", buf);
		buf[ret] = '\0';
		*line = ligne(*line, buf);
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	**line;
	
	line = malloc(sizeof(char**));
	get_next_line(open(av[1], O_RDONLY), line);
//	ft_putstr(*line);
//	ft_putchar('\n');
	return (0);
}
