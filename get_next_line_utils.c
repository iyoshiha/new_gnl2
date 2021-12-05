/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:46:16 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/12/06 07:33:20 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	joined_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!(joined_str))
		return (NULL);
	while (i < len_s1)
	{
		joined_str[i] = s1[i];
		i++;
	}
	while (i < len_s2 + len_s1)
	{
		joined_str[i] = s2[i - len_s1];
		i++;
	}
	joined_str[i] = '\0';
	return (joined_str);
}
