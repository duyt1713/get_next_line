#include "../get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int fd1 = open("test1", O_RDONLY);
	int fd2 = open("test2", O_RDONLY);
	int fd3 = open("test3", O_RDONLY);

	char *line1, *line2, *line3;
	int read_count = 0;

	while (1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);

		if (!line1 && !line2 && !line3)
			break ;

		read_count++;
		printf("Read %d:\n", read_count);

		if (line1)
			printf("test1 line: %s", line1);
		if (line2)
			printf("test2 line: %s", line2);
		if (line3)
			printf("test3 line: %s", line3);

		printf("\n");

		free(line1);
		free(line2);
		free(line3);
	}
	printf("Pointer1: %p\n", line1);
	printf("Pointer2: %p\n", line2);
	printf("Pointer3: %p\n", line3);

	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
