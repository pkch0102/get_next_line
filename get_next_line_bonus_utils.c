/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicpark <emmet.urssu@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:33:54 by kicpark           #+#    #+#             */
/*   Updated: 2021/03/02 10:33:54 by kicpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char* ft_strchr(char* s, int c)
{
	size_t i;

	if (s == 0)
		return (0);
	i = 0;
	if (c == 0)
		return ((char*)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char*)s + i);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char* s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char* ft_strcpy(char* dst, char* src, size_t n)
{
	size_t i;

	if (dst == 0 && src == 0)
		return (dst);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char* ft_strndup(char* s1, size_t size)
{
	char* dup;

	dup = (char*)malloc(sizeof(char) * (size + 1));
	if (dup == 0)
		return (0);
	ft_strcpy(dup, s1, size);
	dup[size] = 0;
	return (dup);
}

char* ft_strjoin(char* s1, char* s2)
{
	char* res;
	size_t	len1;
	size_t	len2;

	if (s1 == 0 && s2 == 0)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
	if (res == 0)
		return (0);
	ft_strcpy(res, s1, len1);
	ft_strcpy(res + len1, s2, len2);
	res[len1 + len2] = 0;
	return (res);
}