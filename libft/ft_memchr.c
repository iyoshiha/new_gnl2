/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 23:05:26 by iyoshiha          #+#    #+#             */
/*   Updated: 2020/10/31 14:54:33 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*src;
	unsigned char		chr;

	src = (unsigned char *)s;
	chr = (unsigned char)c;
	while (n--)
		if (*src++ == chr)
			return (src - 1);
	return (NULL);
}
