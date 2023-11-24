/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:54:40 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/24 20:19:35 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;

	fd = open("file", O_RDONLY);
	printf("RESULT : \n%s", get_next_line(fd));
	printf("RESULT : \n%s", get_next_line(fd));
}
