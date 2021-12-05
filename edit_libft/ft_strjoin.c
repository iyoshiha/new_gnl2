/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 00:27:42 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/12/06 03:11:29 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *save, char const *old)
{
	char	*joined_str;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	if (save == NULL || old == NULL)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(save);
	len_s2 = ft_strlen(old);
	joined_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!(joined_str))
		return (NULL);
	while (i < len_s1)
	{
		joined_str[i] = save[i];
		i++;
	}
	while (i < len_s2 + len_s1)
	{
		joined_str[i] = old[i - len_s1];
		i++;
	}
	joined_str[i] = '\0';
	return (joined_str);
}
