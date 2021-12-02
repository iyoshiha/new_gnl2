/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:46:32 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/12/02 23:36:36 by iyoshiha         ###   ########.fr       */
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
	// exam save
	while ()
	{
		txt.len_read = read(fd, txt.buf, BUFFER_SIZE);
						if (txt.len_read < 0 || txt.len_read && save == NULL) // if error  // if EOF && save == NULL
							return (NULL);
			/////////////////////////
		if (txt.len_read == END_OF_FILE) // ^1
			// true means ^2 |
			jump if find_breakline() ture
			end_make(line);
			/////////////////////////
			if search was flase // same excution: code 1
			{
				make(line)
			}
		if (txt.len_read) // required info is if txt was read or not here. save doesnt matter coz above conditional expression exclude read val
		{				  // len is only positive(successfully read) or 0 (all txt was read)
			// ^ 3
			txt.buf[BUFFER_SIZE + 1] == '\0';
			save_buf(txt);
					if (find_breakline() is TRUE)// ^3 | same excution: code 1
							break;
		}
	}
	if find_breakline(save) == GNL_FOUND // ^5
		save -> line ;
		free(save);
		save = NULL pointer;
	make(line); // ^4
	return line;
}
