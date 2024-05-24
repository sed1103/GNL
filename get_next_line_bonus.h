/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:07:04 by skirakos          #+#    #+#             */
/*   Updated: 2024/04/23 20:07:05 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
void	fill_buff(char **buff, int fd);
char	*ft_strnew(size_t size);
char	*ft_substr(char *s, unsigned int start, size_t len, int to_free);
char	*ft_strdup(char *s);

#endif
