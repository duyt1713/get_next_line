#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int fd1 = open("test3", O_RDONLY);

	char *line1;
	while ((line1 = get_next_line(fd1)) != NULL)
	{
		printf("Line: %s", line1);
		free(line1);
	}
	printf("Pointer: %p", line1);
	close(fd1);
	return (0);
}
