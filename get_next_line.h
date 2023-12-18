/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/07 10:42:46 by edribeir      #+#    #+#                 */
/*   Updated: 2023/12/18 19:09:56 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
#include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *basin_buffer, char *cup_buffer);
char	*ft_strchr(const char *str, int c);
char	*get_next_line(int fd);

#endif