/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 23:02:02 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/11/25 05:27:10 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned char		*s;
	unsigned char		chr;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	chr = (unsigned char)c;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == chr)
			return (&d[i + 1]);
		i++;
	}
	return (0);
}
