#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*s;

	// char *s;
	printf("Buffer size: %d\n", BUFFER_SIZE);
	fd = open("empty.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s", s);
	close(fd);
	return (0);
}
