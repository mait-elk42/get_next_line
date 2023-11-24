/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:27:14 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/24 21:05:42 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	_nsx_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

t_nsx_node	*_nsx_create_node(char	*buffer)
{
	t_nsx_node	*res;

	res = malloc(sizeof(t_nsx_node));
	if (!res)
		return (0);
	res->buffer = buffer;
	res->next = 0;
	return (res);
}

void	_nsx_add_node(t_nsx_node	**head, t_nsx_node	*new)
{
	t_nsx_node	*tmphead;

	tmphead = *head;
	if (!tmphead)
	{
		*head = new;
		return ;
	}
	while (tmphead->next)
		tmphead = tmphead->next;
	tmphead->next = new;
}
