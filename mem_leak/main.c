#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	r(int fd, char* str)
{
	static int i;

	printf("this is %d times\n", i);
	i++;
	return (read(fd ,str , 100));
}

int	main()
{
int fd = open("e_text", O_RDONLY);
char* str;
// char fakep;
size_t red_num;

str = malloc(sizeof(char)*128);
// str = calloc(sizeof(char),128);
while (i < 3)
{
	r(fd, str);
	printf("%s \n", str);
}
// printf("%zu\n", red_num);
// printf("%s\n", str);
// str = &fakep;
// free(str);
// close(fd);
return 0;
}
