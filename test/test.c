#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	int	fd;
	const char *files[] = {"one_line.txt", "two_lines.txt", "lots_of_lines.txt", "non_exsistence.txt"};
	int num_files = sizeof(files) / sizeof(files[0]);
	int i = 0;

	while (i < num_files)
	{
		fd = open(files[i], O_RDONLY);
		printf("Opening %s: %d\n", files[i], fd);
		i++;
	}
}
