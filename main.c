/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 10:58:37 by edribeir      #+#    #+#                 */
/*   Updated: 2023/12/20 11:45:23 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int    fd;
	char  *next_line;
	int  count;

	count = 0;
	fd = open("example.txt", O_RDONLY);

	while (count < 4)
	{
		count++;
		next_line = get_next_line(fd);
		printf("[%d]:%s\n", count, next_line); //count is to show you the line numbers
		free (next_line);
		next_line = NULL;
	}
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	// while (1)
	// {
	// 	count++;
	// 	next_line = get_next_line(fd);
	// 	if (next_line == NULL)
	// 		break;
	// 	printf("[%d]:%s\n", count, next_line); //count is to show you the line numbers
	// 	free (next_line);
	// 	next_line = NULL;
	// }

	close(fd);
	return (0);
}