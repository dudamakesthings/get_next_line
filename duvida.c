#include "get_next_line.h"



char	*get_next_line(int fd)
{
	char space[1000];
	int nbytesreads;
	nbytesreads = read(fd, space, BUFFER_SIZE);
	space[nbytesreads] = 0;
	printf("%d\n", nbytesreads);
	printf("%s\n", space);
	return 0;
}

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	// printf("%i\n", fd);
	get_next_line(fd);
	close(fd); // if open need to close
}

// str[i + 1] = "\0";
// uhuhuhuh.\0
// hello\n 
// heyheyehy.\0
