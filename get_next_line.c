/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:13:31 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/26 17:20:18 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*read_buffer;
	char		*result;
	int			read_len;

	read_len = 1;
	result = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(static_buffer), static_buffer = NULL, NULL);
	_nsx_join(&result, static_buffer);
	static_buffer = (free(static_buffer), NULL);
	read_buffer = malloc(BUFFER_SIZE + 1);
	if (!read_buffer)
		return (free(static_buffer), static_buffer = NULL, NULL);
	while (read_len)
	{
		read_len = read(fd, read_buffer, BUFFER_SIZE);
		read_buffer[read_len] = '\0';
		_nsx_join(&result, read_buffer);
		if (_nsx_there_nwline(read_buffer))
			break ;
	}
	free(read_buffer);
	if (_nsx_there_nwline(result))
		static_buffer = _nsx_get_next(result);
	result = _nsx_trimnl(result);
	return (result);
}
