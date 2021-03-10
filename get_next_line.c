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

/*
** - Read the text available on a file descriptor, one line without newline.
** - Read file only once.
** - Do not read whole file and then process each line.
** - Try to read as little as possible each time get_next_line is called.
*/

static int	handle_line(char **line, char **res, char *tmp_line)
{
	char	*tmp;

	if (tmp_line != NULL)
	{
		*line = ft_strndup(*res, tmp_line - *res);
		tmp = ft_strndup(tmp_line + 1, ft_strlen(tmp_line + 1));
		free(*res);
		*res = tmp;
		return (CON);
	}
	if (*res != NULL)
	{
		*line = *res;
		*res = NULL;
	}
	else
		*line = ft_strndup("", 1);
	return (_EOF);
}

int			get_next_line(int fd, char **line)
{
	static char	*res[OPEN_MAX];
	static char	buff[BUFFER_SIZE + 1];
	int			byte;
	char		*tmp;
	char		*tmp_line;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (ERROR);
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
		return (ERROR);
	return (handle_line(line, &res[fd], tmp_line));
}
