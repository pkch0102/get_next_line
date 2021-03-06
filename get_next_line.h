/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicpark <emmet.urssu@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:33:14 by kicpark           #+#    #+#             */
/*   Updated: 2021/03/05 01:08:27 by kicpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		get_next_line(int fd, char **line);

char	*ft_strchr(char *s, int c);
int		ft_strlen(char *c);
char	*ft_strcpy(char	*dst, char *src, int n);
char	*ft_strndup(char *s1, int size);
char	*ft_strjoin(char *s1, char *s2);

#endif
