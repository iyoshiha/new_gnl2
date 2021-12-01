/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 02:14:21 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/11/25 05:37:45 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	len;

	len = ft_strlen(src);
	str = malloc(sizeof(*str) * (len + 1));
	if (!(str))
		return (NULL);
	ft_strlcpy(str, src, len + 1);
	return (str);
}
