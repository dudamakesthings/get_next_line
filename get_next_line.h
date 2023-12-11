/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/07 10:42:46 by edribeir      #+#    #+#                 */
/*   Updated: 2023/12/11 15:42:50 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
#include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_strjoin(char const *s1, char const *s2);

size_t	find_len(const char *str);
char	*find_newline(char *str);
void	add_rest_buffer(char *dst, char *src);
void	copy_str(char *dst, char *src);
char	*read_and_join(int fd, char *buffer, char *line);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);

#endif