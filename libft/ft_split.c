/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 00:16:20 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/11/25 05:34:07 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_chanks(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
		{
			s++;
			continue ;
		}
		count++;
		while (*s && !(*s == c))
			s++;
	}
	return (count);
}

static char	**split_str(char **splited_strs, const char *s, char c, int count)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] && !(s[len] == c))
			len++;
		splited_strs[i] = malloc(sizeof(char) * (len + 1));
		if (!(splited_strs[i]))
		{
			while (i >= 0)
				free(splited_strs[i--]);
			return (NULL);
		}
		ft_strlcpy(splited_strs[i], s, len + 1);
		i++;
		s += len;
	}
	return (splited_strs);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**splited_strs;

	if (!s)
		return (NULL);
	count = count_chanks(s, c);
	splited_strs = (char **)malloc(sizeof(*splited_strs) * (count + 1));
	if (!(splited_strs))
		return (NULL);
	splited_strs[count] = NULL;
	if (!(split_str(splited_strs, s, c, count)))
	{
		free(splited_strs);
		return (NULL);
	}
	return (splited_strs);
}
