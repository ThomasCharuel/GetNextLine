/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:40:44 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/13 11:14:57 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stash_list
{
	char				*stash;
	int					fd;
	struct s_stash_list	*next;
}						t_stash_list;

char					*get_next_line(int fd);
char					**get_or_create_stash_from_list(
							t_stash_list **stash_list, int fd);
ssize_t					read_in_stash(int fd, char **stash);
char					*pick_line_in_stash(char **stash);
void					remove_stash_from_list(t_stash_list **stash_list,
							int fd);

size_t					ft_strlen_delimiter(const char *s, char c);
char					*ft_strdup_lf(const char *src);
char					*ft_substr(const char *s, unsigned int start,
							size_t len);
int						ft_str_has_lf(char const *s);
void					ft_strcpy(char *dst, const char *src);

#endif
