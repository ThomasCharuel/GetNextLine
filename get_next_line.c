/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:40:48 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/12 17:37:18 by tcharuel         ###   ########.fr       */
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

	bytes_read = read_in_stash(fd, &stash);
	if (bytes_read < 0)
	{
		if (stash)
			free(stash);
		stash = NULL;
	}
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
	char	*line;
	char	*new_stash;

	line = ft_strdup_lf(*stash);
	if (!line || !ft_str_has_lf(line))
	{
		free(*stash);
		*stash = NULL;
	}
	else
	{
		new_stash = ft_substr(*stash, ft_strlen_delimiter(line, '\n'), -1);
		free(*stash);
		*stash = new_stash;
		if (!*stash)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}

ssize_t	read_in_stash(int fd, char **stash)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	char	*new_stash;

	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE && (!*stash || (*stash
				&& !ft_str_has_lf(*stash))))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			if (!*stash)
				new_stash = init_stash(buffer, bytes_read);
			else
				new_stash = concat_stash_and_buffer(*stash, buffer, bytes_read);
			if (!*new_stash)
				return (-2);
			if (*stash)
				free(*stash);
			*stash = new_stash;
		}
	}
	return (bytes_read);
}

char	*init_stash(char buffer[BUFFER_SIZE], ssize_t bytes_read)
{
	char	*new_stash;
	ssize_t	i;

	new_stash = (char *)malloc((bytes_read + 1) * sizeof(char));
	if (!new_stash)
		return (NULL);
	i = 0;
	while (i < bytes_read)
	{
		new_stash[i] = buffer[i];
		i++;
	}
	new_stash[i] = '\0';
	return (new_stash);
}

char	*concat_stash_and_buffer(char *stash, char buffer[BUFFER_SIZE],
		ssize_t bytes_read)
{
	char	*new_stash;
	size_t	len;
	size_t	i;

	len = ft_strlen_delimiter(stash, '\0') + bytes_read;
	new_stash = (char *)malloc((len + 1) * sizeof(char));
	if (!new_stash)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (i < len - bytes_read)
			new_stash[i] = stash[i];
		else
			new_stash[i] = buffer[i - len + bytes_read];
		i++;
	}
	new_stash[i] = '\0';
	return (new_stash);
}
