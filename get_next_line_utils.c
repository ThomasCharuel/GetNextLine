/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:40:51 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/11 09:58:37 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Returns the length of a string.
 * Length includes the the terminating \n character,
 * except if the string does not include a \n character.
 * In this case, the regular length of the string is returned.
 *
 * @param s: The string to get the length from;
 *
 * @return Length until first Line Feed (included)
 */
ssize_t	ft_strlen_with_delimiter(char *s, char delimiter)
{
	ssize_t	len;

	len = 0;
	while (s[len])
	{
		if (s[len++] == delimiter)
			break ;
	}
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

/**
 * @brief Allocates and returns a substring from the input string.
 *
 * This function allocates memory for and returns a new substring from the
 * input string 's'. The substring starts at the specified 'start' index
 * and has a maximum length of 'len' characters.
 *
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string 's'.
 * @param len The maximum length of the substring.
 *
 * @return The newly allocated substring.
 * @retval NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	substr_len;
	size_t	i;

	if (!s || start > ft_strlen(s))
		substr_len = 0;
	else
	{
		s += start;
		substr_len = ft_strlen(s);
		if (len < substr_len)
			substr_len = len;
	}
	substr = (char *)malloc((substr_len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < substr_len)
	{
		substr[i] = s[i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
