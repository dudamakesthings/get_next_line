/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 11:01:53 by edribeir      #+#    #+#                 */
/*   Updated: 2023/12/15 11:09:14 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*get_next_line(int fd)
{
	int	nbytes_read;
	char	*cup_buffer;

	buffer = malloc (3 + 1 * sizeof(char));
	nbytes_read = read(fd, cup_buffer, 3);
}