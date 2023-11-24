/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:13:31 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/24 21:07:04 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	_nsx_there_newline(char	*s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	_nsx_nodes_clear(t_nsx_node	*head, t_nsx_node	**headptr)
{
	t_nsx_node	*tmp;

	if (!head)
		return ;
	while (head)
	{
		tmp = head->next;
		free(head->buffer);
		free(head);
		head = tmp;
	}
	*headptr = head;
}

char	*_nsx_nodes_to_str(t_nsx_node	**head)
{
	char		*res;
	t_nsx_node	*tmphead;
	int			len;
	int			i;

	len = 0;
	tmphead = *head;
	while (tmphead)
	{
		len += _nsx_strlen(tmphead->buffer);
		tmphead = tmphead->next;
	}
	res = malloc(len + 1);
	if (!res)
		return (0);
	tmphead = *head;
	len = 0;
	while (tmphead)
	{
		i = 0;
		while (tmphead->buffer[i])
		{
			res[len++] = tmphead->buffer[i++];
			if (tmphead->buffer[i-1] == '\n')
				return (res);
		}
		tmphead = tmphead->next;
	}
	res[len] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static t_nsx_node	*head = 0;
	int					nl_index;
	int					read_len;
	char				*buff;

	read_len = 1;
	nl_index = 0;
	while (read_len)
	{
		buff = malloc(BUFFER_SIZE + 1);
		read_len = read(fd, buff, BUFFER_SIZE);
		buff[read_len] = '\0';
		nl_index = _nsx_there_newline(buff);
		_nsx_add_node(&head, _nsx_create_node(buff));
		if (nl_index != -1)
			break ;
	}
	buff = _nsx_nodes_to_str(&head);
	_nsx_nodes_clear(head, &head);
	return (buff);
}
