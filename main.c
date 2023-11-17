/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:27:39 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/17 22:19:05 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFERSIZE 12
int _prtchar(char c)
{
	return (write(1, &c, 1));
}

int _prtstr(char *s)
{
	while (*s)
		_prtchar(*s++);
	return (0);
}

char	*get_next_line(int fd)
{
	char *res;
	char *buffer;

	buffer = malloc(BUFFERSIZE + 1);
	while (read(fd, buffer, BUFFERSIZE))
	{
		while()
	}
}

int main()
{
	char *c = malloc(BUFFERSIZE + 1);
	c[BUFFERSIZE] = '\0';
	int fd = open("file.txt", O_RDONLY);
	read(fd, c, BUFFERSIZE);
	_prtstr(c);
	close(fd);
}