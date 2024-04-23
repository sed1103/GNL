#include "get_next_line.h"

int	find_new_line(char *buff)
{
	int		i;
//	char	*temp;

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
			return;
		}
		temp[sz] = '\0';
		tmp1 = *buff;
		*buff = ft_strjoin(*buff, temp);
		free(tmp1);
	}
	free(temp);
	temp = NULL;
	// return (buff);
}

char *get_next_line(int fd)
{
	static char	*buff;
	char 		*send;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fill_buff(&buff, fd);
	if (find_new_line(buff) != -1)
	{
		//printf("buff: is |%s|", buff);
		send = ft_substr(buff, 0, find_new_line(buff) + 1, 0);
		//buff = ft_strdup(buff + find_new_line(buff) + 1);
		buff = ft_substr(buff, find_new_line(buff) + 1, ft_strlen(buff) - find_new_line(buff), 1);
		//buff = buff + find_new_line(buff);
	}
	else
	{
		send = ft_substr(buff, 0, ft_strlen(buff),0);
		free(buff);
		buff = NULL;
	}
	if ((ft_strlen(buff) == 0 && ft_strlen(send) == 0) && (fd >= 0))
	{
		//printf("NULL");
		free(send);
		send = NULL;
		return (NULL);
	}
	if (send && !send[0])
	{
		free(send);
		return(NULL);
	}
	return (send);
}

// int main()
// {
// 	int fd;
// 	char *str1;

// 	fd = open("file.txt", O_RDONLY);
// 	str1 = get_next_line(fd);
// 	while(str1 != NULL)
// 	{
// 		printf("%s",str1);
// 		free(str1);
// 		str1 = get_next_line(fd);
// 	}
// 	system("leaks a.out");

// 	close(fd);
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	//str1 = get_next_line(fd);
// 	//printf("%s", str1);
// 	//free(str1);
	
// 	//printf("%s\n", get_next_line(fd));
// 	//printf("%s\n", get_next_line(fd));
	
// 	return (0);
// }