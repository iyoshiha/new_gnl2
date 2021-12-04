#include "get_next_line.h"
#include <fcntl.h> // open

int main(void)
{
	int	fd;
	char *str;
	fd = open("text.txt", O_RDONLY);

	str = get_next_line(fd);
	while (str)
	{
		printf("%s\n", str);
	}
	return 0;
}
