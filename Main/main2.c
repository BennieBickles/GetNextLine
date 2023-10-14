#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"


int	main( void ) {
	
	char *line = get_next_line(-1);
	while (line) {
		printf("%s", line);
		free(line);
		line = get_next_line(-1);
	}
	return (0);
}
