/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 16:59:02 by edribeir      #+#    #+#                 */
/*   Updated: 2023/12/01 15:54:19 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/**@param char_read every character stored
 * @param next pointer to the next node of the list
 * */
typedef struct source_line_list
{
	char		char_read;
	t_line_list	*next;
}t_line_list;

/**@param position current position in buffer
 * @param nbytes_read the amount of bytes read in buffer
 * @param len the lengh of string
 * @param fd the number of the file descriptor
 * @param buffer the string to store the read char
 * @param line the struct where the line will be storaged
**/
typedef struct s_file{
	int			position;
	int			nbytes;
	int			len;
	int			fd;
	char		buf[BUFFER_SIZE];
	t_line_list	*line;
}t_file;

char	*get_next_line(int fd);

#endif