/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:27:14 by mait-elk          #+#    #+#             */
/*   Updated: 2023/11/27 10:45:30 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	_nsx_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

void	_nsx_join(char	**s1, char	*s2)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	if (!s1 || (!*s1 && !s2) || !s2)
		return ;
	len = _nsx_strlen(*s1) + _nsx_strlen(s2);
	res = malloc(len + 1);
	if (!res)
		return (free(*s1), *s1 = NULL, (void) NULL);
	res[len] = '\0';
	len = 0;
	if (*s1)
		while ((*s1)[i])
			res[len++] = (*s1)[i++];
	i = 0;
	while (s2[i])
		res[len++] = s2[i++];
	free(*s1);
	*s1 = res;
}

int	_nsx_there_nwline(char	*s)
{
	if (!s || !*s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*_nsx_get_next(char	*res)
{
	char	*result;
	int		nl_index;
	int		i;

	i = 0;
	nl_index = 0;
	if (!res)
		return (0);
	while (res[nl_index] && res[nl_index] != '\n')
		nl_index++;
	nl_index++;
	if (res[nl_index] == '\0')
		return (0);
	result = malloc(_nsx_strlen(res + nl_index) + 1);
	if (!result)
		return (0);
	while (res[nl_index])
		result[i++] = res[nl_index++];
	result[i] = '\0';
	return (result);
}

char	*_nsx_trimnl(char	*res)
{
	char	*result;
	int		i;

	i = 0;
	if (!res || !*res)
		return (free(res), NULL);
	if (!_nsx_there_nwline(res))
		return (res);
	while (res[i] && res[i] != '\n')
		i++;
	i++;
	result = malloc(i + 1);
	if (!result)
		return (free(res), NULL);
	i = 0;
	while (res[i])
	{
		result[i] = res[i];
		i++;
		if (result[i - 1] == '\n')
			break ;
	}
	result[i] = '\0';
	free(res);
	return (result);
}
