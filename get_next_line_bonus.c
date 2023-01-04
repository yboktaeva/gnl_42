/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:25:00 by yuboktae          #+#    #+#             */
/*   Updated: 2023/01/03 14:35:23 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	while (buf && buf[i] && buf[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (free(line), NULL);
	i = 0;
	while (buf && buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf && buf[i] && buf[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*line_read(char *stash, int fd)
{
	int		n_bytes;
	char	*temp;
	char	*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (free(buf), NULL);
	n_bytes = 1;
	while (n_bytes > 0)
	{
		n_bytes = read(fd, buf, BUFFER_SIZE);
		if (n_bytes == -1)
			return (free(buf), NULL);
		buf[n_bytes] = 0;
		temp = stash;
		stash = ft_strjoin(temp, buf);
		free(temp);
		if (stash[n_bytes] == '\n')
			break ;
	}
	free(buf);
	return (stash);
}

static char	*left(char *buf)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	line = malloc((ft_strlen(buf) - i + 1) * sizeof(char));
	if (!line)
		return (free(line), NULL);
	j = 0;
	while (buf[i])
		line[j++] = buf[++i];
	line[j] = '\0';
	free (buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = line_read(stash[fd], fd);
	if (ft_strlen(stash[fd]) == 0)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = get_line(stash[fd]);
	stash[fd] = left(stash[fd]);
	return (line);
}

// int	main(void)
// {
// 	int fd1 = open("if.txt", O_RDONLY);
// 	int fd2 = open("test.txt", O_RDONLY);
// 	char *line;
// 	int i = 1;
// 	while (i < 6)
// 	{
// 		line = get_next_line(fd1);
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }