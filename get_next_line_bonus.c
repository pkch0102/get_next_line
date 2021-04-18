/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicpark <emmet.urssu@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:33:27 by kicpark           #+#    #+#             */
/*   Updated: 2021/03/02 10:33:27 by kicpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	handle_line(char** line, char** note, char* nl_here)
{
	char* tmp;

	if (nl_here != NULL)
	{
		*line = ft_strndup(*note, nl_here - *note);
		tmp = ft_strndup(nl_here + 1, ft_strlen(nl_here + 1));
		free(*note);
		*note = tmp;
		return (1);
	}
	if (*note != NULL)
	{
		*line = *note;
		*note = NULL;
	}
	else
		*line = ft_strndup("", 1);
	return (0);
}

int			get_next_line(int fd, char** line)
{
	static char* note[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int			byte;
	char* tmp;
	char* tmp_line;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((tmp_line = ft_strchr(note[fd], '\n')) == 0
		&& (byte = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[byte] = 0;
		tmp = note[fd] == NULL ? ft_strndup(buff, byte) :
			ft_strjoin(note[fd], buff);
		if (note[fd] != 0)
			free(note[fd]);
		note[fd] = tmp;
	}
	if (byte < 0)
		return (-1);
	return (handle_line(line, &note[fd], tmp_line));
}