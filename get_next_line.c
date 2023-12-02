/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:13:31 by mait-elk          #+#    #+#             */
/*   Updated: 2023/12/02 12:01:47 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	checkosf(int fd)
{
	return (fd < 0 || BUFFER_SIZE <= 0 
		|| read(fd, 0, 0) < 0 || BUFFER_SIZE > INT_MAX);
}

char	*get_next_line(int fd)
{
	static char	*s_bfr;
	char		*r_bfr;
	char		*result;
	int			read_len;

	read_len = 1;
	result = 0;
	if (checkosf(fd))
		return (free(s_bfr), s_bfr = NULL, NULL);
	result = _nsx_join(result, s_bfr);
	s_bfr = (free(s_bfr), NULL);
	r_bfr = malloc((size_t)BUFFER_SIZE + 1);
	if (!r_bfr)
		return (free(result), free(s_bfr), s_bfr = NULL, NULL);
	while (_nsx_there_nwline(result) != 1 && read_len)
	{
		read_len = read(fd, r_bfr, BUFFER_SIZE);
		if (read_len == -1)
			return (free(result), free(s_bfr), free(r_bfr), s_bfr = 0, NULL);
		r_bfr[read_len] = '\0';
		result = _nsx_join(result, r_bfr);
		if (!result)
			break ;
	}
	return (free(r_bfr), _nsx_trimnl(result, &s_bfr));
}
