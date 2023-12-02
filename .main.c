/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:54:40 by mait-elk          #+#    #+#             */
/*   Updated: 2023/12/02 12:25:05 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

void prt(char *s)
{
	if (!s)
		prt("(NULL)\n");
	write(1, s, _nsx_strlen(s));
}

int	main(void)
{
	char	*str;
	int	fd;

	fd = open("file", O_RDONLY);

	str = get_next_line(fd);
	printf("%s", str);
	free(str);


	str = get_next_line(-fd);
	printf("%s", str);
	free(str);


	str = get_next_line(fd);
	printf("%s", str);
	free(str);


	str = get_next_line(-fd);
	printf("%s", str);
	free(str);

	system("leaks a.out");
}