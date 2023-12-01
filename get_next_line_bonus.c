/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:38:14 by mait-elk          #+#    #+#             */
/*   Updated: 2023/12/01 18:42:25 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*_nsx_checkerror(int fd, char **static_buffer)
{
	if (static_buffer[fd] && fd >= 0)
		free(static_buffer[fd]);
	static_buffer[fd] = NULL;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer[OPEN_MAX];
	char		*read_buffer;
	char		*result;
	int			read_len;

	read_len = 1;
	result = 0;
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1 || BUFFER_SIZE > INT_MAX)
		return (_nsx_checkerror(fd, static_buffer));
	result = _nsx_join(result, static_buffer[fd]);
	static_buffer[fd] = (free(static_buffer[fd]), NULL);
	read_buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!read_buffer)
		return (free(result), free(static_buffer[fd]),
			static_buffer[fd] = NULL, NULL);
	while (read_len)
	{
		read_len = read(fd, read_buffer, BUFFER_SIZE);
		read_buffer[read_len] = '\0';
		result = _nsx_join(result, read_buffer);
		if (_nsx_there_nwline(read_buffer))
			break ;
	}
	static_buffer[fd] = _nsx_get_next(result);
	return (free(read_buffer), _nsx_trimnl(result, &static_buffer[fd]));
}
