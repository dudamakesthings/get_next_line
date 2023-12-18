/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 11:02:14 by edribeir      #+#    #+#                 */
/*   Updated: 2023/12/18 19:45:16 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	chr;

	chr = (unsigned char)c;
	i = 0;
	while (str[i] != '\0' && str[i] != chr)
		i++;
	if (str[i] == chr)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strjoin(char *basin_buffer, char *cup_buffer)
{
	char	*basin_plus_cup;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (basin_buffer == NULL)
	{
		basin_buffer = malloc(1 * sizeof(char));
		basin_buffer[0] = '\0';
	}
	if (!basin_buffer || !cup_buffer)
		return (NULL);
	basin_plus_cup = malloc((ft_strlen(basin_buffer)+ ft_strlen(cup_buffer) + 1) * sizeof(char));
	if (basin_plus_cup == NULL)
		return (NULL);
	if (basin_buffer)
		while (basin_buffer[i] != '\0')
			basin_plus_cup[j++] = basin_buffer[i++];
	i = 0;
	while (cup_buffer[i] != '\0')
		basin_plus_cup[j++] = cup_buffer[i++];
	basin_plus_cup[j] = '\0';
	return (basin_plus_cup);
}
