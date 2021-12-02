/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:46:32 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/12/03 02:34:43 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#ifndef BUFFER_SIZE // delete here when submit
#define BUFFER_SIZE
#endif

typedef struct s_txt
{
	char	buf[BUFFER_SIZE + 1];
	int		flag;
	char	*line;
	ssize_t len_read;
} t_txt;

save_buf(t_txt txt)
{

	return;
}

int find_break_line(char *save);
{
	int	i;

	i = 0;
	if (save == NULL) // why this save is not recognized???
		return (GNL_NOT_FOUND);
	while (save[i] != '\0')
	{
		if (save[i] == '\n')
			return (GNL_FOUND);
	}
	return (GNL_NOT_FOUND);
}

void save_buf(char *save, t_txt *txt);
void move_save_to_line(char *line, char *save, int flag);

char *get_next_line(int fd)
{
	static char *save;
	t_txt txt;

	txt.len_read = 0;
	txt.flag = GNL_UNTIL_BREAK;
	if (find_break_line(save) == GNL_NOT_FOUND)
		while (UNTIL_REACH_EOF_OR_FOUND_BREAK)
		{
			txt.len_read = read(fd, txt.buf, BUFFER_SIZE);
			if (txt.len_read < 0 || txt.len_read && save == NULL)
				return (NULL);
			if (txt.len_read == END_OF_FILE)
				break;
			save_buf(save, &txt);
			if (find_break_line(save) == GNL_FOUND)
				break;
		}
	if (txt.len_read == END_OF_FILE)
		if (find_break_line() == GNL_NOT_FOUND)
			txt.flag = GNL_ALL;
	move_save_to_line(&txt.line, save, txt.flag);
	return (txt.line);
}
