/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:24:42 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/29 15:06:19 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char		*get_next_line(int fd);
int			_nsx_strlen(char *s);
char		*_nsx_join(char	*s1, char	*s2);
int			_nsx_there_nwline(char	*s);
char		*_nsx_get_next(char	*res);
char		*_nsx_trimnl(char	*res, char	**static_buffer);
#endif