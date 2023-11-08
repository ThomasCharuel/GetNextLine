/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:40:48 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/08 19:12:01 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Returns a line read from a
 * file descriptor.
 * 
 * The returned line should include the terminating \n character,
 * except if the end of file was reached and does not end with a \n character.
 *
 * @param fd: The file descriptor to read from.
 *
 * @return Read line: correct behavior.
 * @retval NULL there is nothing else to read, or an error occurred
 */
char	*get_next_line(int fd)
{
	(void)fd;
	//read(fd, &c, 1);
	return (NULL);
}
