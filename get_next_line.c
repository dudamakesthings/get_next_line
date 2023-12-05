/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 16:58:05 by edribeir      #+#    #+#                 */
/*   Updated: 2023/12/01 15:07:10 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_space(int fd, char *str)
{
	char	*buffer;
	int		nbytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while ((find_newline(str) != NULL) && (nbytes_read != 0))
	{
		nbytes_read = read(fd, buffer, BUFFER_SIZE);
		if (nbytes_read == -1)
			return (free(buffer), free(str), NULL);
		buffer[nbytes_read] = "\0";
		str = ft_strjoin(str, buffer);
	}
	return	(free(buffer), str);
}

char	*get_next_line(int fd)
{
	static char	*space;
	char		*line;


	if (BUFFER_SIZE <= 0 || (fd < 0))
		return (NULL);
	space = read_to_space(fd, space);
	if (space == NULL)
		return (NULL);
	line = space_to_line(space);
	space = uptade_space(space);
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	// printf("%i\n", fd);
	get_next_line(fd);
	close(fd); // if open need to close
}

// char	*get_next_line(int fd)
// {
// 	char space[1000];
// 	int nbytesreads;
	
// 	nbytesreads = read(fd, space, BUFFER_SIZE);
// 	space[nbytesreads] = 0;
// 	printf("%d\n", nbytesreads);
// 	printf("%s\n", space);
// }