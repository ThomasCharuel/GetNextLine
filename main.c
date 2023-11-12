#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*s;

	printf("Buffer size: %d\n", BUFFER_SIZE);
	fd = open("test.txt", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("%s", s);
		s = get_next_line(fd);
	}
	close(fd);
	return (0);
}
