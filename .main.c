/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:54:40 by mait-elk          #+#    #+#             */
/*   Updated: 2023/12/01 19:15:37 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int	main(void)
{
	char	*str;
	int	fd;

	fd = open("file", O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		printf("(%s)", str);
		free(str);
		str = 0;
	}
	system("leaks c");
	// size_t si = 2147483600;
	// char *s = malloc(si);
	// s[si] = '\0';
	// printf("?%d?", read(fd, s, si));
	// printf("(%s)", s);
}