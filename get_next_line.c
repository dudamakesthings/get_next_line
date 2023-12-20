/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 11:01:53 by edribeir      #+#    #+#                 */
/*   Updated: 2023/12/20 18:20:20 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_new_basin(char *basin_buffer)
{
	int		i;
	int		j;
	char	*new_basin;

	i = 0;
	while (basin_buffer[i] && basin_buffer[i] != '\n')
		i++;
	if (!basin_buffer[i])
		return (free(basin_buffer), NULL);
	new_basin = malloc((ft_strlen(basin_buffer) - i + 1));
	if (new_basin == NULL)
		return (NULL);
	if (basin_buffer[i] == '\n')
		i++;
	j = 0;
	while (basin_buffer[i])
		new_basin[j++] = basin_buffer[i++];
	new_basin[j] = '\0';
	free(basin_buffer);
	return (new_basin);
}

static char	*ft_get_line(char *basin_buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!basin_buffer[i])
		return (NULL);
	while (basin_buffer[i])
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (basin_buffer[i] && basin_buffer[i] != '\n')
	{
		str[i] = basin_buffer[i];
		i++;
	}
	if (basin_buffer[i] == '\n')
	{
		str[i] = basin_buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_read_to_basin(int fd, char *basin_buffer)
{
	char	*cup_buffer;
	int		nbytes_read;

	cup_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (cup_buffer == NULL)
		return (NULL);
	nbytes_read = 1;
	while (ft_strchr(basin_buffer, '\n') == NULL && nbytes_read != 0)
	{
		nbytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (nbytes_read == -1)
			return (free(cup_buffer), NULL);
		cup_buffer[nbytes_read] = '\0';
		basin_buffer = ft_strjoin(basin_buffer, cup_buffer);
	}
	free(cup_buffer);
	return (basin_buffer);
}

char	*get_next_line(int fd)
{
	static char	*basin_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	basin_buffer = ft_read_to_basin(fd, basin_buffer);
	if (!basin_buffer)
		return (NULL);
	line = ft_get_line(basin_buffer);
	basin_buffer = ft_new_basin(basin_buffer);
	return (line);
}
