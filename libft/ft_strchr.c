/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 00:23:22 by iyoshiha          #+#    #+#             */
/*   Updated: 2020/10/30 13:20:12 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	char			*str;
	unsigned char	ch;

	ch = (unsigned char)c;
	str = (char *)s;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return (str + i);
		else
			i++;
	}
	if (ch == '\0')
		return (str + i);
	else
		return (NULL);
}
