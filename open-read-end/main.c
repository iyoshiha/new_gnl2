#include <fcntl.h>

int	main()
{
	int fd = open("text.txt", O_RDONLY);
	// int fd = creat(, O_RDONLY);
	return 0;
}
