/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:46:32 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/12/10 01:33:13 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(char *save, t_txt *txt)
{
	txt->save_len = 0;
	txt->newline_index = GNL_NEWLINE_NOT_FOUND;
	if (save == NULL)
		return (GNL_NEWLINE_NOT_FOUND);
	while (save[txt->save_len] != '\0')
	{
		if ((save[txt->save_len] == '\n') \
		&& (txt->newline_index == GNL_NEWLINE_NOT_FOUND))
			txt->newline_index = txt->save_len;
		txt->save_len++;
	}
	return (txt->newline_index);
}

void	save_buf(char **save, char *buf, t_txt *txt)
{
	int		length;
	char	*for_free;

	buf[txt->len_read] = '\0';
	length = txt->save_len + txt->len_read + END_STR;
	if (*save == NULL)
	{
		*save = ft_strjoin(NULL, buf);
		return ;
	}
	for_free = *save;
	*save = ft_strjoin(for_free, buf);
	free(for_free);
	return ;
}

void	*create_oneline(t_txt *txt, char **save)
{
	int		i;
	char	*old_save;

	i = 0;
	txt->line = (char *)malloc(txt->save_len + END_STR);
	if (txt->line == NULL)
		return (NULL);
	while ((*save)[i] != '\0')
	{
		txt->line[i] = (*save)[i];
		i = NEXT_INDEX_OF i;
		if ((*save)[i OF_PREVIOUS] == '\n')
			break ;
	}
	txt->line[i] = '\0';
	if ((txt->len_read == END_OF_FILE) && \
	(txt->newline_index == GNL_NEWLINE_NOT_FOUND))
		return (save_free(save));
	old_save = *save;
	*save = ft_strjoin(NULL, (old_save + NEXT_INDEX_OF txt->newline_index));
	free(old_save);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		buf[BUFFER_SIZE + END_STR];
	t_txt		txt;


	find_newline(save, &txt);
	while (UNTIL_REACH_EOF_OR_FIND_NEWLINE)
	{
		txt.len_read = read(fd, buf, BUFFER_SIZE);
		if (txt.len_read < 0 || (txt.len_read == END_OF_FILE && save == NULL))
			return (NULL);
		if (txt.len_read == END_OF_FILE)
			break ;
		save_buf(&save, buf, &txt);
		if (find_newline(save, &txt) != GNL_NEWLINE_NOT_FOUND)
			break ;
	}
	if ((txt.len_read == END_OF_FILE) && *save == '\0')
		return (save_free(&save));
	create_oneline(&txt, &save);
	return (txt.line);
}
