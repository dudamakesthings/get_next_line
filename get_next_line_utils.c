/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 11:02:14 by edribeir      #+#    #+#                 */
/*   Updated: 2023/12/15 11:22:53 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nitems, size_t sizeitem)
{
	void	*dest;
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)dest;
	i = 0;
	if (nitems != 0 && (nitems * sizeitem) / nitems != sizeitem)
		return (NULL);
	dest = (void *)malloc(nitems * sizeitem);
	if (dest == NULL)
		return (NULL);
	while (i < sizeitem)
	{
		str[i] = 0;
		i++;
	}
	return (dest);
}