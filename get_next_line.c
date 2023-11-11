/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:40:48 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/11 10:06:24 by tcharuel         ###   ########.fr       */
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
	static char	*stash = NULL;
	char		*line;
	ssize_t		bytes_read;

	add_buffer_read_in_stash(fd, &stash);
	if (!stash)
		return (NULL);
	line = pick_line_in_stash(&stash);
	return (line);
}

/**
 * @brief Allocates and returns a string from the input stash.
 *
 * This function allocates memory for and returns a new substring from the
 * input string 'stash'. The substring starts from the beginning of the stash
 * and ends on the first \n character or \0 terminator.
 * The obtained string is removed from the stash.
 *
 * @param stash The address of the stash string.
 *
 * @return The newly allocated substring.
 * @retval NULL if the allocation fails.
 */
char	*pick_line_in_stash(char **stash)
{
	size_t	line_len;
	size_t	stash_len;
	char	*line;
	size_t	i;

	line_len = ft_strlen_with_delimiter(*stash, '\n');
	if (line_len)
		line = (char *)malloc((line_len + 1) * sizeof(char));
	if (line_len && line)
		stash_len = ft_strlcpy(line, *stash, line_len + 1);
	if (!line_len || !line || line[i - 1] != '\n')
	{
		free(*stash);
		*stash = NULL;
	}
	else
	{
		update_stash(stash, line_len + 1, stash_len);
		if (!*stash)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}

/**
 * @brief Allocates and updates stash to a substring.
 *
 * The substring starts at the specified 'start' index
 * and has a maximum length of 'len' characters.
 *
 * @param stash The address of the stash.
 * @param start The start index of the substring in the string 'stash'.
 * @param len The maximum length of the substring.
 */
void	update_stash(char **stash, size_t start, size_t end)
{
	char	*new_stash;

	new_stash = ft_substr(*stash, start, end);
	free(*stash);
	*stash = new_stash;
}

void	add_buffer_read_in_stash(int fd, char **stash)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	while (!new_line_found(*stash) && bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			if (*stash)
			{
				free(*stash);
				*stash = NULL;
			}
			return ;
		}
		// Add to stash, penser a avoir un \0
	}
}
