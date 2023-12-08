/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/07 10:43:04 by edribeir      #+#    #+#                 */
/*   Updated: 2023/12/08 18:09:22 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	copy_str(char *dst, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		if (src[i] == '\n')
			return ;
		i++;
	}
}

void	add_rest_buffer(char *dst, char *src)
{
	size_t	i;

	i = 0;
	if (!src)
		return ;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*find_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i + 1]);
		i++;
	}
	return (NULL);
}

size_t	find_len(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*newstr;
	size_t	len_newstr;
	// int		i;
	// int		j;

	// i = 0;
	// j = 0;
	len_newstr = find_len(line)+ find_len(buffer);
	newstr = ft_calloc((len_newstr + 1), sizeof(char));
	if (newstr == NULL)
		return (free(line), NULL);
	// while (line[j])
	// 	newstr[i++] = line[j++];
	// j = 0;
	// while (buffer[j])
	// 	newstr[i++] = buffer[j++];
	copy_str(newstr, line);
	copy_str(&newstr[find_len(line)], buffer);
	// newstr[i] = '\0';
	return (free(line), newstr);
}


