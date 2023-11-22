/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:27:14 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/22 15:02:30 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_node	*_nsx_create_node(char	*data)
{
	t_node	*res;

	res = malloc(sizeof(t_node));
	if (!res)
		return (0);
	res->data = data;
	res->next = 0;
	return (res);
}

void	_nsx_add_node(t_node	**head, t_node	*new)
{
	t_node	*tmpnode;

	tmpnode = *head;
	if (!tmpnode)
	{
		*head = new;
		return ;
	}
	while (tmpnode->next)
		tmpnode = tmpnode->next;
	tmpnode->next = new;
}
