/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:46:16 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/12/04 19:51:32 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dl;
	size_t	sl;
	size_t	i;

	i = 0;
	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	if (dstsize == 0)
		return (sl + dstsize);
	while (src[i] != '\0' && (dl + i) < dstsize - 1)
	{
		dst[dl + i] = src[i];
		i++;
	}
	if (src[i] == '\0' || (dl + i) == dstsize - 1)
		dst[dl + i] = '\0';
	if (dl >= dstsize)
		return (sl + dstsize);
	else
		return (dl + sl);
}
