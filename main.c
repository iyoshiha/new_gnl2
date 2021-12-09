#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fd;
	char *str;

	fd = open("files/alternate_line_nl_no_nl" , O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	/*
	while(str)
	{
		printf("%s", str);
		str = get_next_line(fd);
	}
	*/
	return (0);
}
