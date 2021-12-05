#include "get_next_line.h"
#include <fcntl.h> // open

int main(void)
{
	int	fd;
	char *str;
	fd = open("files/41_no_nl", O_RDONLY);
	int i = 0;

	str = get_next_line(fd);
	while (str != NULL)
	{
		i++;
		printf("%s", str);
		sleep(1);
		str = get_next_line(fd);
	}
	return 0;
}
