#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	char *s;
	int fd;

	fd = open("blabla.txt", O_RDONLY);

	while ((s = get_next_line(fd)))
	{
		printf("%s", s);
		free(s);
	}
	return (0);
}
