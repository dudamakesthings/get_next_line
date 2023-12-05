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
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*find_newline(char *str)
size_t	find_len(const char *str);
char	*ft_strjoin(char const *s1, char const *buffer);

char	*get_next_line(int fd);

#endif