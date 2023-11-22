/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:13:31 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/22 15:36:39 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	_nsx_initialize_list(t_node	**head, int fd)
{
	int		i;
	char	*readed_str;
	int		len_read;

	len_read = 1;
	while (len_read)
	{
		i = 0;
		readed_str = malloc(BUFFER_SIZE + 1);
		readed_str[BUFFER_SIZE] = '\0';
		len_read = read(fd, readed_str, BUFFER_SIZE);
		_nsx_add_node(head, _nsx_create_node(readed_str));
		while (readed_str[i])
		{
			if (readed_str[i] == '\n')
				return ;
			i++;
		}
	}
}

int	_nsx_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		while (s[i])
			i++;
	return (i);
}

char	*_nsx_nodes_to_str(t_node	*head)
{
	char	*res;
	int		i;
	int		j;
	t_node	*tmphead;

	i = 0;
	tmphead = head;
	while (tmphead)
	{
		i += _nsx_strlen(tmphead->data);
		tmphead = tmphead->next;
	}
	res = malloc(i + 1);
	j = 0;
	while (head)
	{
		i = 0;
		while (head->data[i] && head->data[i] != '\n')
		{
			res[j++] = head->data[i++];
		}
		head = head->next;
	}
	res[j] = '\0';
	return (res);
}

void	_nsx_build_nodes(t_node	**head)
{
	t_node	*new_head;
	
}

char	*get_next_line(int fd)
{
	static t_node	*head;
	char			*newline;

	_nsx_initialize_list(&head, fd);
	newline = _nsx_nodes_to_str(head);
	_nsx_build_nodes(&head);
	return (newline);
}