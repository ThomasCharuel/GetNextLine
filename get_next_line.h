/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:40:44 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/12 16:52:58 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*pick_line_in_stash(char **stash);
ssize_t	read_in_stash(int fd, char **stash);
char	*init_stash(char buffer[BUFFER_SIZE], ssize_t bytes_read);
char	*concat_stash_and_buffer(char *stash, char buffer[BUFFER_SIZE],
			ssize_t bytes_read);

size_t	ft_strlen_delimiter(const char *s, char c);
char	*ft_strdup_lf(const char *src);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_str_has_lf(char const *s);

#endif
