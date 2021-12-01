/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:46:32 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/12/02 03:30:07 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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
		if (txt.len_read == END_OF_FILE)
			jump if search_break() ture
			end_make(line);
			if search was flase
			{
				make(line)
			}
		if (txt.len_read) // required info is if txt was read or not here. save doesnt matter coz above conditional expression exclude read val
		{				  // len is only positive(successfully read) or 0 (all txt was read)
			txt.buf[BUFFER_SIZE + 1] == '\0';
			save_buf(txt);
		}
		if (search_break() is TRUE)
			break;
	}
	make(line);

	return line;
}
