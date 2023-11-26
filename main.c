/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:54:40 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/26 10:38:08 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int	main(void)
{
	int	fd;

	fd = open("file", O_RDONLY);
	printf("<%s>", get_next_line(fd));
	printf("<%s>", get_next_line(fd));
	printf("<%s>", get_next_line(fd));
}
