/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 00:27:42 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/11/25 05:30:35 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
