/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanier <almanier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:27:26 by almanier          #+#    #+#             */
/*   Updated: 2026/01/14 13:58:30 by almanier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>  // open, O_RDONLY
#include <stdio.h>  // printf si tu fais des tests
#include <stdlib.h> // malloc, free, NULL
#include <string.h> // strdup, strchr
#include <unistd.h> // read, close

static char	*ft_extract(char **statiic)
{
	char	*line;
	char	*rest;
	int		i;

	i = 0;
	if (*statiic == NULL || (*statiic)[0] == '\0')
		return (NULL);
	while ((*statiic)[i] && (*statiic)[i] != '\n')
		i++;
	if ((*statiic)[i] == '\n')
		line = ft_substr(*statiic, 0, i + 1);
	else
		line = ft_substr(*statiic, 0, i);
	if ((*statiic)[i] == '\0')
	{
		free(*statiic);
		*statiic = NULL;
		return (line);
	}
	rest = ft_strdup(&(*statiic)[i + 1]);
	free(*statiic);
	*statiic = rest;
	return (line);
}

static char	*ft_fusion(char *statiic, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(statiic, buf);
	free(statiic);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*statiic[1024];
	ssize_t		countr;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd < 1024)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	countr = 1;
	while (countr > 0 && (statiic[fd] == NULL || ft_strchr(statiic[fd],
				'\n') == NULL))
	{
		countr = read(fd, buf, BUFFER_SIZE);
		if (countr <= 0)
			break ;
		buf[countr] = '\0';
		if (statiic[fd] == NULL)
			statiic[fd] = ft_strdup(buf);
		else
			statiic[fd] = ft_fusion(statiic[fd], buf);
	}
	line = ft_extract(&statiic[fd]);
	return (free(buf), line);
}

/*
int	main(void)
{
	int		fd;
	char	*buf;

	fd = 0;
	buf = 0;
	fd = open("./file.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("erreur\n");
		return (1);
	}
	buf = get_next_line(fd);
	while(buf != NULL)
	{
		printf("%s", buf);
		free (buf);
		buf = get_next_line(fd);
	}
	return (0);
}
*/
