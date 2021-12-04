#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dl;
	size_t	sl;
	size_t	i;

	i = 0;
	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	if (dstsize == 0)
		return (sl + dstsize);
	while (src[i] != '\0' && (dl + i) < dstsize - 1)
	{
		dst[dl + i] = src[i];
		i++;
	}
	if (src[i] == '\0' || (dl + i) == dstsize - 1)
		dst[dl + i] = '\0';
	if (dl >= dstsize)
		return (sl + dstsize);
	else
		return (dl + sl);
}

int main(void)
{
	char dst[10] = "\0";
	char src[] = "GOOD";

	ft_strlcat(dst , src, 10);
	printf("%s", dst);
	return 0;
}
