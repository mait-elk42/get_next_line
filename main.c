/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:54:40 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/21 12:59:33 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 5
#include "get_next_line.h"

int	_nsx_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	_nsx_strcmp(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (0);
	if (!s2)
		return (1);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}

char	*_nsx_strdup(char *s)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(_nsx_strlen(s) + 1);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

char	*_nsx_strjoin(char *str1, char *str2)
{
	int		i;
	char	*res;

	i = 0;
	if (!str1)
		return (_nsx_strdup(str2));
	res = malloc(_nsx_strlen(str1) + _nsx_strlen(str2) + 1);
	if (!res)
		return (0);
	while (*str1)
	{
		res[i++] = *str1++;
	}
	while (*str2)
	{
		res[i++] = *str2++;
	}
	res[i] = '\0';
	return (res);
}



char	*get_next_line(int fd)
{
	int			read_len;
	char		*buff;
	static char	*res;

	read_len = 1;
	while (read_len)
	{
		buff = malloc(BUFFER_SIZE + 1);
		buff[BUFFER_SIZE] = '\0';
		read_len = read(fd, buff, BUFFER_SIZE);
		res = _nsx_strjoin(res, buff);
		free(buff);
		printf("[static res] : %s\n", res);
	}
	return (res);
}

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	printf("return : (%s)\n", get_next_line(fd));
	// printf("return : (%s)", get_next_line(fd));
}