/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:46:32 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/12/04 22:32:19 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE // delete here when submit
#define BUFFER_SIZE 5
#endif

/* func stack
strcat();
strlen();
*/

int find_break_line(char *save, t_txt *txt)
{
	txt->save_len = 0;
	txt->index_of_breakline = GNL_BREAK_NOT_FOUND;
	if (save == NULL)
		return (GNL_BREAK_NOT_FOUND);
	while (save[txt->save_len] != '\0')
	{
		if (save[txt->save_len] == '\n' && txt->index_of_breakline == GNL_BREAK_NOT_FOUND) //
			txt->index_of_breakline = txt->save_len;
		txt->save_len++;
	}
	return (txt->index_of_breakline);
}

void save_buf(char **save, char *buf, int save_len)
{
	int		length;
	char	*for_free;

	length = save_len + BUFFER_SIZE + 1;
	if (*save == NULL) // check if its first call of gnl (no malloc if its first coll) //NULL pointer , NULL string is different
	{
		*save = (char *)malloc(length);
		if (*save == NULL)
			return ;
		ft_strlcat(*save, buf, length);
		return ;
	}
	for_free = *save;
	*save = ft_strjoin(for_free, buf);
	free(for_free);
	return;
}

void move_save_to_line(t_txt *txt, char **save)
{
	int i;
	char *old_save;

	i = 0;
	if (txt->index_of_breakline == GNL_BREAK_NOT_FOUND)
		txt->line = (char *)malloc(txt->save_len + 1);
	else
		txt->line = (char *)malloc(txt->index_of_breakline + 1 + 1); // 1 for null, 1 for conv index to len;
	while ((*save)[i] != '\0')
	{
		txt->line[i] = (*save)[i];
		i++;
		if ((*save)[i - 1] == '\n') // after put \n in line then move but we didnt exam so -1
			break;
	}
	txt->line[i] = '\0';
	if ((txt->len_read == END_OF_FILE) && (txt->index_of_breakline == GNL_BREAK_NOT_FOUND)) //last line // find_break_line's return value can be flag
	{
		free(*save);
		*save = NULL;
		return;
	}
	old_save = *save;
	*save = (char *)malloc((txt->save_len - txt->index_of_breakline));
	ft_strlcat(*save, old_save + (txt->index_of_breakline + 1), (txt->save_len - txt->index_of_breakline));
	free(old_save);
}

char *get_next_line(int fd)
{
	static char *save;
	char		buf[BUFFER_SIZE + 1];
	t_txt		txt;

	while (find_break_line(save, &txt) == GNL_BREAK_NOT_FOUND) // 1
	{
		txt.len_read = read(fd, buf, BUFFER_SIZE);
		// printf("\\n : %d\nlen_red : %zd\nsave_len : %d\n\n", txt.index_of_breakline, txt.len_read, txt.save_len); // dele
		if (txt.len_read < 0 || ((txt.len_read == END_OF_FILE) && (save == NULL)))
			return (NULL);
		if (txt.len_read == END_OF_FILE)
			break;
		buf[BUFFER_SIZE] = '\0';
		save_buf(&save, buf, txt.save_len);
		if (find_break_line(save, &txt) != GNL_BREAK_NOT_FOUND) // 2
			break;
	}
	move_save_to_line(&txt, &save);
	return (txt.line);
}
