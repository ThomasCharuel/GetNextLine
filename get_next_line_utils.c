/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:40:51 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/12 16:36:20 by tcharuel         ###   ########.fr       */
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
size_t	ft_strlen_delimiter(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		if (s[len++] == c)
			return (len);
	}
	return (len);
}

char	*ft_strdup_lf(const char *src)
{
	size_t	len;
	char	*dup;

	len = ft_strlen_delimiter(src, '\n');
	if (!len)
		return (NULL);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	dup[len] = '\0';
	while (len-- > 0)
		dup[len] = src[len];
	return (dup);
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

	if (!s || start > ft_strlen_delimiter(s, '\0'))
		substr_len = 0;
	else
	{
		s += start;
		substr_len = ft_strlen_delimiter(s, '\0');
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

/**
 * @brief Checks if the input string contains a LINE FEED character.
 *
 * This function scans the input string 's' to check if it contains
 * the character \n. It returns 1 if found within 's',
 * and 0 otherwise.
 *
 * @param s The input string to be searched.
 *
 * @return 1 if \n (LINE FEED) is found in the string 's', otherwise 0.
 */
int	ft_str_has_lf(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
