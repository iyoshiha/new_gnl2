#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main()
{
int fd = open("text", O_RDONLY);
char* str;
// char fakep;
size_t red_num;

str = malloc(sizeof(char)*128);
// str = calloc(sizeof(char),128);
red_num = read(fd ,str , 100);
printf("%zu\n", red_num);
printf("%s\n", str);
// str = &fakep;
free(str);
close(fd);
return 0;
}
