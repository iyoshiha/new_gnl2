#include <stdio.h>

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

int main()
{
	char *str;

	str = NULL;
	ft_strlen(str);
	return 0;
}
