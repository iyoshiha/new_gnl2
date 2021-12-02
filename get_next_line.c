/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:46:32 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/12/03 00:36:50 by iyoshiha         ###   ########.fr       */
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
	ssize_t	len_read;
}				t_txt;

save_buf(t_txt txt)
{

	return;
}

int	find_break_line();


char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	t_txt		txt;

	txt.len_read = 0;
	if (find_break_line(save) == GNL_NOT_FOUND_BREAK)
	{
		while (REACH_EOF_OR_FOUND_BREAK)
		{ /// loooop
			txt.len_read = read(fd, txt.buf, BUFFER_SIZE);
			if (txt.len_read < 0 || txt.len_read && save == NULL)
				return (NULL);
				// ^1
			if (txt.len_read == END_OF_FILE)
				break; // need to go to ^2
			save_buf(): // when reach here without break means read_num is positive!
			if (find_break_line() == GNL_FOUND_BREAK)
				break;
		} //// loooooooop end
		if (txt.len_read == END_OF_FILE)
			if (find_break_line() == GNL_NOT_FOUND_BREAK)
				copy_save_to_line(, GNL_ALL);
				return (line);
		copy_save_to_line(, GNL_UNTIL_BREAK);
		return (line);
}
