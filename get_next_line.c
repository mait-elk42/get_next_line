/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:13:31 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/22 17:43:47 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	_nsx_initialize_list(t_nsx_node	**head, int fd)
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

char	*_nsx_nodes_to_str(t_nsx_node	*head)
{
	char	*res;
	int		i;
	int		j;
	t_nsx_node	*tmphead;

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
		while (head->data[i] && head->data[i - 1] != '\n')
		{
			res[j++] = head->data[i++];
		}
		head = head->next;
	}
	res[j] = '\0';
	return (res);
}

char	*_nsx_salloc(char *s)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(_nsx_strlen(s + 1));
	if (!res)
		return (0);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	_nsx_build_nodes(t_nsx_node	**head)
{
	char	*dataa;
	int		i;
	t_nsx_node	*new_head;

	i = 0;
	while ((*head)->next)
	{
		new_head = (*head)->next;
		free((*head)->data);
		free((*head));
		*head = new_head;
	}
	while (new_head->data[i] && new_head->data[i - 1] != '\n')
		i++;
	dataa = _nsx_salloc(new_head->data + i);
	free(new_head->data);
	free(new_head);
	new_head = _nsx_create_node(dataa);
	new_head->next = 0;
	*head = new_head;
}

char	*get_next_line(int fd)
{
	static t_nsx_node	*head;
	char			*newline;

	_nsx_initialize_list(&head, fd);
	newline = _nsx_nodes_to_str(head);
	_nsx_build_nodes(&head);
	return (newline);
}
