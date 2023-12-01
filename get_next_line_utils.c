/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/29 16:58:40 by edribeir      #+#    #+#                 */
/*   Updated: 2023/12/01 16:00:53 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line_list	*get_char_read(int ch)
{
	t_line_list	*string;

	string = malloc(1 * sizeof(t_line_list));
	string->char_read = ch;
	string->next = NULL;
	return (string);
}

