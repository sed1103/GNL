//#include "get_next_line.h"

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

// #include <stdio.h>

// int main() {
//     const char *originalString = "Hello, World!";

//     char *duplicateString = ft_strdup(originalString);

//     printf("Original String: %s\n", originalString);
//     printf("Duplicate String: %s\n", duplicateString);

//     free(duplicateString);

//     return 0;
// }