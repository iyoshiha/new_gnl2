/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:46:32 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/12/06 07:17:33 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE // delete here when submit
#define BUFFER_SIZE 128
#endif

int find_newline(char *save, t_txt *txt)
{
	txt->save_len = 0;
	txt->newline_index = GNL_NEWLINE_NOT_FOUND;
	if (save == NULL)
		return (GNL_NEWLINE_NOT_FOUND);
	while (save[txt->save_len] != '\0')
	{
		if ((save[txt->save_len] == '\n') && (txt->newline_index == GNL_NEWLINE_NOT_FOUND)) //
			txt->newline_index = txt->save_len;
		txt->save_len++;
	}
	return (txt->newline_index);
}
void	*save_free(char **save)
{
		free(*save);
		*save = NULL;
		return(NULL);
}

void save_buf(char **save, char *buf, t_txt *txt)
{
	int		length;
	char	*for_free;

	buf[txt->len_read] = '\0';
	length = txt->save_len + txt->len_read + END_STR; // save len can be gabage val; but when *save is NULL, save_len will be set.
	if (*save == NULL) // check if its first call of gnl (no malloc if its first coll) //NULL pointer , NULL string is different
	{
		*save = (char *)malloc(length);
		if (*save == NULL)
			return ;
		ft_strlcat(*save, buf, length); // MUST change concatenating uninitialized malloced str ###
		return ;
	}
	for_free = *save;
	*save = ft_strjoin(for_free, buf);
	free(for_free);
	return;
}

void	*creat_oneline(t_txt *txt, char **save)
{
	int i;
	int len_after_newline;
	char *old_save;

	i = 0;
	len_after_newline = txt->save_len - txt->newline_index;
	if (txt->newline_index == GNL_NEWLINE_NOT_FOUND)
		txt->line = (char *)malloc(txt->save_len + END_STR);
	else
		txt->line = (char *)malloc(CONVERT_TO_LEN txt->newline_index + END_STR); // 1 for null, 1 for conv index to len;
	while ((*save)[i] != '\0')
	{
		txt->line[i] = (*save)[i];
		i = NEXT_INDEX_OF i;
		if ((*save)[i OF_PREVIOUS] == '\n') // after put \n in line then move but we didnt exam so -1
			break;
	}
	txt->line[i] = '\0';
	if ((txt->len_read == END_OF_FILE) && (txt->newline_index == GNL_NEWLINE_NOT_FOUND)) //last line // find_break_line's return value can be flag
		return (save_free(save));
	old_save = *save;
	*save = (char *)malloc((len_after_newline));
	**save = '\0';
	ft_strlcat(*save, (old_save + NEXT_INDEX_OF txt->newline_index), len_after_newline);
	free(old_save);
	return (NULL);
}


char *get_next_line(int fd)
{
	static char *save;
	char		buf[BUFFER_SIZE + END_STR];
	t_txt		txt;

	find_newline(save, &txt);
	while (UNTIL_REACH_EOF_OR_FIND_NEWLINE)
	{
		txt.len_read = read(fd, buf, BUFFER_SIZE);
		if (txt.len_read < 0 || ((txt.len_read == END_OF_FILE) && (save == NULL)))
			return (NULL);
		if (txt.len_read == END_OF_FILE)
			break;
		save_buf(&save, buf, &txt);
		if (find_newline(save, &txt) != GNL_NEWLINE_NOT_FOUND)
			break;
	}
	if ((txt.len_read == END_OF_FILE) && *save == '\0')
		return(save_free(&save));
	creat_oneline(&txt, &save);
	return (txt.line);
}
