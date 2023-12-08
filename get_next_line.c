/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/07 10:42:25 by edribeir      #+#    #+#                 */
/*   Updated: 2023/12/08 18:15:00 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_join(int fd, char *buffer, char *line)
{
	int	read_bytes;

	read_bytes = 1;
	if (buffer[0] != '\0')
	{
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	while (!find_newline(buffer) && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			buffer[0] = '\0';
			return (free(line), NULL);
		}
		buffer[read_bytes] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_calloc(1, sizeof(char));
	if (!line)
		return (NULL);
	line = read_and_join(fd, buffer, line);
	if (!line)
		return (NULL);
	if (buffer[0] != '\0')
		add_rest_buffer(buffer, find_newline(buffer));
	if (find_len(line) == 0)
		return (free(line), NULL);
	return (line);
}
