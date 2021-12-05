/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:46:07 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/12/06 06:11:25 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#
#define END_OF_FILE 0
#define NOT_END_OF_FILE 1
#define END_STR 1
#define NEXT_INDEX_OF 1+
#define OF_PREVIOUS -1
#define CONVERT_TO_LEN 1+
#define GNL_BREAK_FOUND 1
#define GNL_NEWLINE_NOT_FOUND -1
#define UNTIL_REACH_EOF_OR_FOUND_NEWLINE 1
// ssize_t range is [-1 =< ssize_t =<  SSIZE_MAX]

typedef struct	s_txt
{
	int		newline_index;
	int		save_len;
	char	*line;
	ssize_t len_read;
} 				t_txt;

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		find_newline(char *save, t_txt *txt);
void	save_buf(char **save, char *buf, t_txt *txt);
void	*creat_oneline(t_txt *txt, char **save);
char	*get_next_line(int	fd);

#endif
