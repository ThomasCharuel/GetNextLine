#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int			fd;
	static char	buffer[BUFFER_SIZE];
	ssize_t		bytes_read;

	// char *s;
	printf("Buffer size: %d\n", BUFFER_SIZE);
	fd = open("empty.txt", O_RDONLY);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	printf("test.txt: %zd\n", bytes_read);
	close(fd);
	// s = get_next_line(fd);
	return (0);
}
