/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:46:32 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/12/01 18:23:10 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#ifndef BUFFER_SIZE // delete here when submit
#define BUFFER_SIZE
#endif

typedef struct s_data
{
	char	*save;
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;
	ssize_t	suxes_read_num;
	char	*line;

}				t_data;

char	*get_next_line(int fd)
{
	char	*save
	read(fd, buf, BUFFER_SIZE);

	return line;
}
