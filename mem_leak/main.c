#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define LEAK_DETECT
#ifdef LEAK_DETECT
#include "mem_check.h"
#define init() mem_table_init()
#define malloc(s) mem_malloc(s, __FILE__, __LINE__)
#define free mem_free
#define check() leak_check()
#else
#define init()	mem_check_init()
#define check() leak_check()
#endif

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
char *nan;
// char fakep;

sstr = malloc(sizeof(char)*128);
nan	 = malloc(sizeof(char)*128);
sstr[0] = 1;
sstr[1] = '\0';
// nan = sstr; // lost nan pointer mallocted
sstr = nan; // lost sstr poiner mallocted
/*
 * avode both are detected as leak
 */
free(nan);
sstr = "hello";
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
check();
return 0;
}
