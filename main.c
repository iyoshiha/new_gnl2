#include "get_next_line.h"
#include <fcntl.h> // open

int main(void)
{
	int	fd;
	char *str;
	fd = open("text.txt", O_RDONLY);
	int i = 0;


	str = get_next_line(fd);
	while (str != NULL)
	{
		i++;
		puts("**********");
		printf("%s\n%d\n", str, i);
		puts("**********");
		str = get_next_line(fd);
	}
	return 0;
}
