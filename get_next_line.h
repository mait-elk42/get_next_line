/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:24:42 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/24 15:34:43 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_nsx_node
{
	char				*buffer;
	struct s_nsx_node	*next;
}	t_nsx_node;

char		*get_next_line(int fd);
int			_nsx_strlen(char *s);
t_nsx_node	*_nsx_create_node(char	*buffer);
void		_nsx_add_node(t_nsx_node	**head, t_nsx_node	*new);
#endif