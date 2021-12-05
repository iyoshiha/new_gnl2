/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 00:27:42 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/12/06 07:27:15 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *prefix, char const *sufix)
{
	char	*joined_str;
	size_t	i;
	size_t	len_pre;
	size_t	len_su;

	if (prefix == NULL || sufix == NULL)
		return (NULL);
	i = 0;
	len_pre = ft_strlen(prefix);
	len_su = ft_strlen(sufix);
	joined_str = (char *)malloc(sizeof(char) * (len_pre + len_su + 1));
	if (!(joined_str))
		return (NULL);
	while (i < len_pre)
	{
		joined_str[i] = prefix[i];
		i++;
	}
	while (i < len_su + len_pre)
	{
		joined_str[i] = sufix[i - len_pre];
		i++;
	}
	joined_str[i] = '\0';
	return (joined_str);
}
