#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/* int main(void)
{
	const char *files[] = {"one_line.txt", "two_lines.txt", "lots_of_lines.txt", "non_exsistence.txt"};
	int num_files = sizeof(files) / sizeof(files[0]);

	for (int i = 0; i < num_files; i++)
	{
		int fd = open(files[i], O_RDONLY);
		printf("Opening %s: %d\n", files[i], fd);
		char *buffer = malloc(100);
		if (!buffer)
			return (0);
		ssize_t bytes = read(fd, buffer, 20);
		printf("Read: %s\n", buffer);
		free(buffer);
	}
} */

int main()
{
	int fd = open("two_lines.txt", O_RDONLY);
	char *line = store_line(fd);
	printf("%s\n", line);
}
