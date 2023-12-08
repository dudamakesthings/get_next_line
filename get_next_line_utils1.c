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

#include "get_next_line1.h"

int	find_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

size_t	find_len(const char *str)
{
	size_t	counter;

	counter = 0;
	if (!str)
		return (0);
	while (*str)
		counter++;
	return (counter);
}

char	*ft_strjoin(char *s1, char *buffer)
{
	char	*newstr;
	size_t	len_newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len_newstr = find_len(s1)+ find_len(buffer);
	newstr = (char *)malloc((len_newstr + 1) * sizeof(char));
	if (newstr == NULL)
		return (free(s1), NULL);
	while (s1[j])
		newstr[i++] = s1[j++];
	j = 0;
	while (buffer[j])
		newstr[i++] = buffer[j++];
	newstr[i] = '\0';
	return (free(s1), newstr);
}
