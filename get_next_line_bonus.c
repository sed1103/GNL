/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:06:07 by skirakos          #+#    #+#             */
/*   Updated: 2024/04/23 20:06:08 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	find_new_line(char *buff)
{
	int		i;

	i = 0;
	if (!buff)
		return (-1);
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_check(char **buff, char **send, int fd)
{
	if ((ft_strlen(*buff) == 0 && ft_strlen(*send) == 0) && (fd >= 0))
	{
		free(*send);
		send = NULL;
		return (NULL);
	}
	if (send && !send[0])
	{
		free(*send);
		return (NULL);
	}
	return (*send);
}

void	fill_buff(char **buff, int fd)
{
	char	*temp;
	char	*tmp1;
	int		sz;

	sz = 1;
	temp = ft_strnew(BUFFER_SIZE + 1);
	while (find_new_line(*buff) == -1 && sz != 0)
	{
		sz = read(fd, temp, BUFFER_SIZE);
		if (sz < 0)
		{
			free(*buff);
			free(temp);
			temp = NULL;
			*buff = NULL;
			return ;
		}
		temp[sz] = '\0';
		tmp1 = *buff;
		*buff = ft_strjoin(*buff, temp);
		free(tmp1);
	}
	free(temp);
	temp = NULL;
}

char	*get_next_line(int fd)
{
	static char		*buff[OPEN_MAX];
	char			*send;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	fill_buff(&buff[fd], fd);
	if (find_new_line(buff[fd]) != -1)
	{
		send = ft_substr(buff[fd], 0, find_new_line(buff[fd]) + 1, 0);
		buff[fd] = ft_substr(buff[fd], find_new_line(buff[fd]) + 1,
				ft_strlen(buff[fd]) - find_new_line(buff[fd]), 1);
	}
	else
	{
		send = ft_substr(buff[fd], 0, ft_strlen(buff[fd]), 0);
		free(buff[fd]);
		buff[fd] = NULL;
	}
	return (ft_check(&buff[fd], &send, fd));
}
