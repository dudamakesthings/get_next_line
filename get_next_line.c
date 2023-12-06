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

char	*update_space(char *str)
{
	int	i;
	int	j;

	i = find_newline(str);
	if ((find_newline(str) == 0) && str[i] != '\n')
		return (free(str), NULL);
	j = 0;
	while (str[i + 1])
	{
		str[j++] = str[i + 1];
		i++;
	}
	while (str[j] != '\0')
	{
		str[j] = '\0';
		j++;
	}
	return (str);
}

char	*ft_turn_into(char *str)
{
	char	*new;
	size_t	len;
	size_t	i;

	i = 0;
	len = find_len(str);
	new = malloc((len + 1) * sizeof(char));
	if (new == NULL)
		return (free(str), NULL);
	while (str[i] && (str[i] != '\n'))
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		(new[i]) = '\n';
		i++;
	}
	return (free(str), new);
}

char	*space_to_line(char *str)
{
	char	*line;
	size_t	len;

	len = find_len(str);
	line = malloc((len + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	line = ft_strjoin(line, str);
	if (line[0] == NULL)
		return (free(line), NULL);
	return (ft_turn_into(line));
}

char	*read_to_space(int fd, char *space)
{
	char	*buffer;
	int		nbytes_read;

	nbytes_read = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while ((!find_newline(space)) && (nbytes_read != 0))
	{
		nbytes_read = read(fd, buffer, BUFFER_SIZE);
		if (nbytes_read == -1)
			return (free(buffer), free(space), NULL);
		buffer[nbytes_read] = 0;
		space = ft_strjoin(space, buffer);
	}
	return (free(buffer), space);
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
	space = update_space(space);
	return (line);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("file.txt", O_RDONLY);
// 	// printf("%i\n", fd);
// 	get_next_line(fd);
// 	close(fd); // if open need to close
// }

// char	*get_next_line(int fd)
// {
// 	char space[1000];
// 	int nbytesreads;
// 	nbytesreads = read(fd, space, BUFFER_SIZE);
// 	space[nbytesreads] = 0;
// 	printf("%d\n", nbytesreads);
// 	printf("%s\n", space);
// }