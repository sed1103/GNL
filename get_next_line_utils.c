#include "get_next_line.h"

// char    *ft_strdup(char *s)
// {
//     int     i;
//     int     len;
//     char    *str_copy;

//     len = ft_strlen(s);
//     str_copy = (char *)malloc((len + 1)*sizeof(char));
//     i = 0;
//     if (str_copy)
//     {
//         while (s[i] != '\0')
//         {
//             str_copy[i] = s[i];
//             i++;
//         }
//         str_copy[i] = '\0';
//         return (s);
//     }
//     return NULL;
// }

int  ft_strlen(const char *s)
{
    int i;

	i = 0;
	if (s == NULL) // attention
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char    *ft_strnew(size_t size)
{
    char    *str;

    str = (char *)malloc((size + 1) * sizeof(char));
    if (!str)
		return (NULL);
	return (str);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *str;
    int		i;
	int		j;

    i = 0;
	j = 0;
    if (s2) // attention only s2
    {
        str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
        if (str)
        {
			//printf("aaa");
            while (i < ft_strlen(s1) && ft_strlen(s1) != 0)
            {
                str[i] = s1[i];
                i++;
            }
            while (j < ft_strlen(s2))
            {
                str[i + j] = s2[j];
                j+=1;
            }
            str[i + j] = '\0';
            return (str);
		}
    }
    return (NULL);
}

// char    *ft_substr(char const *s, unsigned int start, size_t len)
// {
//     char    *substr;
//     unsigned int     i;
//     unsigned int     j;
// 	//if (!s) return NULL;
//     i = start;
//     j = 0;
//     if (s && start + len < ft_strlen(s))
//     {
//         substr = ft_strnew(len);
//         if (substr)
//         {
//             while (i != start + len )
//             {
//                 substr[j] = s[i];
//                 i++;
//                 j++;
//             }
//             substr[i] = '\0';
//             return (substr);
//         }
//     }
//     return (NULL);
// }

char	*ft_substr(char *s, unsigned int start, size_t len, int to_free)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	if (to_free)
		free(s);
	return (str);
}


// char	*ft_substr(char *s, unsigned int start, size_t len, int to_free)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	str = (char *)malloc(sizeof(*s) * (len + 1));
// 	if (str == 0)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		if (i >= start && j < len)
// 		{
// 			str[j] = s[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	str[j] = 0;
// 	return (str);
// 	if (to_free)
// 		free(s);
	
// 	return (str);
// }