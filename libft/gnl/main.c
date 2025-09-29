#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd;
	char *line;

	fd = open("tester.txt", O_RDWR | O_CREAT);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("Is: %s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
