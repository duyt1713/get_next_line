#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int fd = open("./gnlTester/files/multiple_nlx5", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}

	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	if (close(fd) == -1)
	{
		perror("Error closing file");
		return (1);
	}

	return (0);
}
