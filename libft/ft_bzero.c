/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:15:34 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/11/25 04:43:29 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*string;

	if (n == 0)
		return ;
	string = (unsigned char *)s;
	while (n-- > 0)
		*(string++) = 0;
	return ;
}
