/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:46:07 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/12/04 20:01:41 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <string.h>
#include <unistd.h>
#include <stdio.h>
/* #define BUF
#ifdef BUF
#define BUFFER_SIZE 5
#endif
*/
#define END_OF_FILE 0
#define NOT_END_OF_FILE 1
#define NULL_LEN 1

#define GNL_BREAK_FOUND 1
#define GNL_BREAK_NOT_FOUND -1
#define UNTIL_REACH_EOF_OR_FOUND_BREAK 1
#define GNL_ALL 1
#define GNL_UNTIL_BREAK 0
// ssize_t range is [-1 =< ssize_t =<  SSIZE_MAX]

typedef struct s_txt
{
	int		index_of_breakline;
	int		save_len;
	char	*line;
	ssize_t len_read;
} t_txt;

#endif
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int find_break_line(char *save, t_txt *txt);
void save_buf(char **save, char *buf, int save_len);
void move_save_to_line(t_txt *txt, char **save);//
char	*get_next_line(int	fd);
