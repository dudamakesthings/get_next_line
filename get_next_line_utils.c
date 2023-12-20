/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 11:02:14 by edribeir      #+#    #+#                 */
/*   Updated: 2023/12/20 22:11:24 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_length(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int ch)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (char) ch)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*combine_strs(char *str1, char *str2)
{
	char	*strjoined;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str1 == NULL || str2 == NULL)
		return (NULL);
	strjoined = malloc((ft_strlen(str1) + get_length(str2) + 1) * sizeof(char));
	if (strjoined == NULL)
		return (NULL);
	while (str1[i] != '\0')
		strjoined[j++] = str1[i++];
	i = 0;
	while (str2[i] != '\0' && str2[i] != '\n')
		strjoined[j++] = str2[i++];
	if (str2[i] == '\n')
		strjoined[j++] = str2[i];
	strjoined[j] = '\0';
	return (strjoined);
}
