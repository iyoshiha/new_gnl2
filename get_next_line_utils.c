/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:46:16 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/12/06 08:05:49 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *head, char const *tail)
{
	char	*joined_str;
	size_t	i;
	size_t	len_head;
	size_t	len_tail;

	if (tail == NULL)
		return (NULL);
	i = 0;
	len_head = ft_strlen(head);
	len_tail = ft_strlen(tail);
	joined_str = (char *)malloc(sizeof(char) * (len_head + len_tail + END_STR));
	if (!(joined_str))
		return (NULL);
	while (i < len_head)
	{
		joined_str[i] = head[i];
		i++;
	}
	while (i < len_tail + len_head)
	{
		joined_str[i] = tail[i - len_head];
		i++;
	}
	joined_str[i] = '\0';
	return (joined_str);
}

void	*save_free(char **save)
{
		free(*save);
		*save = NULL;
		return(NULL);
}
