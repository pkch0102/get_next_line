/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicpark <emmet.urssu@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:33:04 by kicpark           #+#    #+#             */
/*   Updated: 2021/03/02 10:33:04 by kicpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	func(char **line, char **res, char *tmp_line)
{
	char	*tmp;

	if (tmp_line != NULL)
	{
		*line = ft_strndup(*res, tmp_line - *res);
		tmp = ft_strndup(tmp_line + 1, ft_strlen(tmp_line + 1));
		free(*res);
		*res = tmp;
		return (1);
	}
	if (*res != NULL)
	{
		*line = *res;
		*res = NULL;
	}
	else
		*line = ft_strndup("", 1);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*res[OPEN_MAX];
	static char	buff[BUFFER_SIZE + 1];
	int			byte;
	char		*tmp;
	char		*tmp_line;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((tmp_line = ft_strchr(res[fd], '\n')) == 0
			&& (byte = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[byte] = 0;
		tmp = res[fd] == NULL ? ft_strndup(buff, byte) :
			ft_strjoin(res[fd], buff);
		if (res[fd] != 0)
			free(res[fd]);
		res[fd] = tmp;
	}
	if (byte < 0)
		return (-1);
	return (func(line, &res[fd], tmp_line));
}
