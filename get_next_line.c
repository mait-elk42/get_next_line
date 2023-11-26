/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:13:31 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/26 10:01:23 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*_nsx_join(char	*s1, char	*s2)
{
	char	*res;
	int		len;
	int		i;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	len = _nsx_strlen(s1) + _nsx_strlen(s2);
	res = malloc(len + 1);
	if (!res)
	{
    	if (s1)
			free(s1);
    	if (s2)
			free(s2);
    	return (NULL);
	}
	res[len] = '\0';
	i = 0;
	len = 0;
	while (s1[i])
		res[len++] = s1[i++];
	i = 0;
	while (s2[i])
		res[len++] = s2[i++];
	// if (s1)
	// 	free(s1);
    // if (s2)
	// 	free(s2);
	return (res);
}

int	_nsx_there_nwline(char	*s)
{
	if (s)
	{
		while (*s)
		{
			if (*s == '\n')
				return (1);
			s++;
		}
	}
	return (0);
}

char	*_nsx_get_next(char	*res)
{
	char	*result;
	int		nl_index;
	int		i;

	i = 0;
	nl_index = 0;
	if (!res)
		return (0);
	while (res[nl_index] && res[nl_index] != '\n')
		nl_index++;
	nl_index++;
	if (res[nl_index] == '\0')
		return (0);
	result = malloc(_nsx_strlen(res + nl_index) + 1);
	if (!result)
		return (0);
	while (res[nl_index])
		result[i++] = res[nl_index++];
	result[i] = '\0';
	return (result);
}

char	*_nsx_trimnl(char	*res)
{
	char	*result;
	int		i;

	i = 0;
	if (!res)
		return (0);
	if (!_nsx_there_nwline(res))
		return (res);
	while (res[i] && res[i] != '\n')
		i++;
	i++;
	result = malloc(i + 1);
	if (!result)
		return (0);
	i = 0;
	while (res[i])
	{
		result[i] = res[i];
		i++;
		if (result[i - 1] == '\n')
			break ;
	}
	result[i] = '\0';
	free(res);
	return (result);
}

char	*get_next_line(int fd)
{
	int			there_nl;
	static char	*static_buffer;
	char		*read_buff;
	char		*res;
	int			readlen;

	readlen = 1;
	res = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	res = _nsx_join(res, static_buffer);
	while (readlen)
	{
		read_buff = 0;
		read_buff = malloc(BUFFER_SIZE + 1);
		if (!read_buff)
		{
			if (res != NULL)
				free(res);
			return (NULL);
		}
		readlen = read(fd, read_buff, BUFFER_SIZE);
		read_buff[readlen] = '\0';
		there_nl = _nsx_there_nwline(read_buff);
		res = _nsx_join(res, read_buff);
		if (!res)
			return (0);
		if (there_nl)
			break ;
	}
	if (there_nl)
		static_buffer = _nsx_get_next(res);
	res = _nsx_trimnl(res);
	if (!*res)
		return (free(res), NULL);
	return (res);
}

