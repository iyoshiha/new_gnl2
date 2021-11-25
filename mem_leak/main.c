#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	r(int fd, char* str, int i)
{
	printf("this is %d times\n", i);
	return (read(fd ,str , 100));
}

int	main()
{
	/*
int fd = open("text", O_RDONLY);
char* str;
int i = 0;
size_t red_num;
*/
static char * sstr;
int i;
// char fakep;

sstr = malloc(sizeof(char)*128);
sstr[0] = 1;
sstr[1] = '\0';
free(sstr+1);
sstr = "jjj";
// i = r(0, sstr, 111);
// printf("%d\n", i);
// str = calloc(sizeof(char),128);
/* for read loop ;
while (i < 3)
{
	red_num = r(fd, str, i);
	i++;
	puts("#############");
	ft_putstr_fd(str, STDOUT_FILENO);
	puts("#############");
	printf("\n%zu\n", red_num);
}
 end for read loop*/

// printf("%zu\n", red_num);
printf("%s\n", sstr);
// str = &fakep;
// close(fd);
return 0;
}
