#include <stdio.h>

typedef enum e_operation_buf
{
	save_buf,
	malloc_buf,
	free_buf
}			t_operation_buf;

int main(void)

{
	t_operation_buf x, y, z;
	/*int a;
	long b;
	unsigned long c;
	*/

	z = save_buf; y = malloc_buf; x = free_buf;

	printf("%d\n", z);
	printf("%d\n", y);
	printf("%u\n", x);
	return 0;
}
