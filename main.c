/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 10:58:37 by edribeir      #+#    #+#                 */
/*   Updated: 2023/12/15 10:59:25 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int    fd;
	char  *next_line;
	int  count;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	next_line = get_next_line(fd);
	count++;
	printf("[%d]:%s\n", count, next_line); //count is to show you the line numbers
	next_line = NULL;

	close(fd);
	return (0);
}