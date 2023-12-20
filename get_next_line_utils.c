/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 11:02:14 by edribeir      #+#    #+#                 */
/*   Updated: 2023/12/20 18:18:27 by edribeir      ########   odam.nl         */
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

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *basin, char *cup)
{
	char	*basin_cup;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (basin == NULL)
	{
		basin = malloc(1 * sizeof(char));
		basin[0] = '\0';
	}
	if (!basin || !cup)
		return (NULL);
	basin_cup = malloc((ft_strlen(basin)+ ft_strlen(cup) + 1) * sizeof(char));
	if (basin_cup == NULL)
		return (NULL);
	if (basin)
		while (basin[i] != '\0')
			basin_cup[j++] = basin[i++];
	i = 0;
	while (cup[i] != '\0')
		basin_cup[j++] = cup[i++];
	basin_cup[j] = '\0';
	return (free(basin), basin_cup);
}
