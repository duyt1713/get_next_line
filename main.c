#include "get_next_line.h"
#include <stdio.h>
int main()
{
	char *dest = NULL;
	char *src = "src";
	char *hmm = ft_memmove(dest, src, 3);
	printf("%s\n", hmm);
}
