#include "get_next_line.h"
#include <fcntl.h> 
#include <stdio.h>

int main(void)
{
	char	*s;
	int		fd;
	
	fd = open("test.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s\n", s);
	close(fd);
	return (0);
}
