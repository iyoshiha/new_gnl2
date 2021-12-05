#include <stdio.h>
#include <stdlib.h>
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

char	*ft_strjoin(char const *prefix, char const *sufix)
{
	char	*joined_str;
	size_t	i;
	size_t	len_pre;
	size_t	len_su;

	if (sufix == NULL)
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


int main()
{
	char *str;
	char string[] = "HELLO, WORLD!";

	str = NULL;
	str = ft_strjoin(str, string+7);
	printf("%s\n", str);

	return 0;
}
