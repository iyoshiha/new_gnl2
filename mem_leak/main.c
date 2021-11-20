#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../../ft_printf/libft/libft.h"

int	r(int fd, char* str, int i)
{
	printf("this is %d times\n", i);
	return (read(fd ,str , 100));
}

int	main()
{
int fd = open("text", O_RDONLY);
char* str;
int i = 0;
size_t red_num;
// char fakep;

str = malloc(sizeof(char)*128);
// str = calloc(sizeof(char),128);
while (i < 3)
{
	red_num = r(fd, str, i);
	i++;
	puts("#############");
	ft_putstr_fd(str, STDOUT_FILENO);
	puts("#############");
	printf("\n%zu\n", red_num);
}
// printf("%zu\n", red_num);
// printf("%s\n", str);
// str = &fakep;
// free(str);
close(fd);
return 0;
}
