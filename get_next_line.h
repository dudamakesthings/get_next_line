/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/07 10:42:46 by edribeir      #+#    #+#                 */
/*   Updated: 2023/12/21 15:45:17 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t	get_length(const char *str);
char	*combine_strs(char *p_line, char *buf);
char	*ft_strchr(char *str, int ch);
char	*get_next_line(int fd);

#endif