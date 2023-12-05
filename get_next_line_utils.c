/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 16:58:40 by edribeir      #+#    #+#                 */
/*   Updated: 2023/12/01 16:00:53 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_newline(char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == '\n')
			return (str + 1);
		str++;
	}
	return (NULL);
}

size_t	find_len(const char *str)
{
	size_t	counter;

	counter = 0;
	if (!str)
		return (NULL);
	while (*str)
		counter++;
	return (counter);
}

char	*ft_strjoin(char const *s1, char const *buffer)
{
	char	*newstr;
	size_t	len_newstr;
	int		i;

	i = 0;
	len_newstr = ft_strlen(s1)+ ft_strlen(buffer);
	newstr = (char *)malloc((len_newstr + 1) * sizeof(char));
	if (newstr == NULL)
		return (free(s1), NULL);
	while (*s1)
		newstr[j++] = s1++;
	while (*buffer)
		newstr[j++] = buffer++;
	newstr[j] = '\0';
	return (free(s1), newstr);
}