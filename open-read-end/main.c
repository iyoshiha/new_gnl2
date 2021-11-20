#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main()
{
	int fd = open("text.txt", O_RDONLY);
	// int fd = creat(, O_RDONLY);
	// int fd = open("../text.txt", O_RDONLY);
	char* str;
	int red_num = read(fd ,str , 10);
	printf("%s\n%d", str, red_num);
	close(fd);
	return 0;
}
