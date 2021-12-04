/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:46:32 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/12/04 09:53:39 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#ifndef BUFFER_SIZE // delete here when submit
#define BUFFER_SIZE
#endif

/* func stack
strdup()
strjoin()
strcpy()
*/



int find_break_line(char **save, t_txt *txt);
{
	txt.save_len = 0;
	txt->index_of_breakline == GNL_BREAK_NOT_FOUND;
	if (*save == NULL)
		return (GNL_BREAK_NOT_FOUND);
	while (save[txt->save_len] != '\0')
	{
		if (save[txt->save_len] == '\n' && txt->index_of_brekaline == GNL_BREAK_NOT_FOUND)
			t_txt->index_of_breakline = txt->save_len;
		txt->save_len++;
	}
	return (t_txt->index_of_breakline);
}

void save_buf(char **save, char *buf)
{
	char	*for_free;
	if (save == NULL) // check if its first call of gnl (no malloc if its first coll)
	{
		// dup()
		*save = (char *)malloc(buf_len);
		if (*save == NULL)
			return (NULL);
		strcpy(*save, buf);
		return ;
		// this excution above is dup()
	}
	for_free = *save;
	*save = ft_strjoin(*save, buf); // join()
	free(for_free);
	return;
}

void move_save_to_line(t_txt *txt, char **save)
{
	int i;
	char *old_save;

	i = 0;
	if (txt->index_of_breakline == GNL_BREAK_NOT_FOUND)
		txt->line = (char *)malloc(txt->save_len + 1));
	else
		txt->line = (char *)malloc(txt->index_of_breakline + 1 + 1); // 1 for null, 1 for conv index to len;
	while (*save[i] != '\0')
	{
		txt->line[i] = save[i];
		if (*save[i] == '\n')
			break;
		i++;
	}
	line[i] = '\0';
	if ((txt->len_read == END_OF_FILE) && (txt->index_of_breakline == GNL_BREAK_NOT_FOUND)) // find_break_line's return value can be flag
	{
		free(*save);
		*save = NULL;
		return;
	}
	old_save = *save;
	*save = (char *)malloc((txt->save_len - txt->index_of_breakline));
	strcpy(*save, old_save + (txt->index_of_breakline + 1));
	free(old_save);
}

char *get_next_line(int fd)
{
	static char *save;
	char		buf[BUFFER_SIZE + 1];
	t_txt		txt;

	if (find_break_line(save) == GNL_BREAK_NOT_FOUND) // 1
		while (UNTIL_REACH_EOF_OR_FOUND_BREAK)
		{
			txt.len_read = read(fd, buf, BUFFER_SIZE);
			if (txt.len_read < 0 || ((txt.len_read == END_OF_FILE) && (save == NULL)))
				return (NULL);
			if (txt.len_read == END_OF_FILE)
				break;
			buf[BUFFER_SIZE + 1] = '\0'
			save_buf(&save, buf);
			if (txt.index_of_breakline != GNL_BREAK_NOT_FOUND) // 2
				break;
		}
	move_save_to_line(&txt, &save);
	return (txt.line);
}
