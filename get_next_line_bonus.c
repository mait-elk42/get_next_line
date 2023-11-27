/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:13:31 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/27 10:47:08 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*static_buffer[OPEN_MAX];
	char		*read_buffer;
	char		*result;
	int			read_len;

	read_len = 1;
	result = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(static_buffer[fd]), static_buffer[fd] = NULL, NULL);
	_nsx_join(&result, static_buffer[fd]);
	static_buffer[fd] = (free(static_buffer[fd]), NULL);
	read_buffer = malloc(BUFFER_SIZE + 1);
	if (!read_buffer)
		return (free(static_buffer[fd]), static_buffer[fd] = NULL, NULL);
	while (read_len)
	{
		read_len = read(fd, read_buffer, BUFFER_SIZE);
		read_buffer[read_len] = '\0';
		_nsx_join(&result, read_buffer);
		if (_nsx_there_nwline(read_buffer))
			break ;
	}
	if (_nsx_there_nwline(result))
		static_buffer[fd] = _nsx_get_next(result);
	return (free(read_buffer), _nsx_trimnl(result));
}
