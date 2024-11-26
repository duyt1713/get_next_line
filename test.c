#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int	fd;

	fd = open("one_line.txt", O_RDONLY);
	printf("%d\n", fd);
}
