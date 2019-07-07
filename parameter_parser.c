#include "ft_printf.h"

int     check_flags(char c)
{
    char    *options;
    int     i;
    
    options = " #0-+hlL";
    i = 0;
    while (options[i])
    {
        if (options[i] == c)
            return (1);
        else
            i++;
    }
    return (0);
}

int     check_type(char c)
{
    char    *type;
    int     i;

    type = "%cspdiouxXf";
    i = 0;
    while (type[i])
    {
        if (type[i] == c)
            return (1);
        else
            i++;
    }
    return (0);
}

int     get_type(const char *str, t_format *format)
{
    int     i;
    
    i = 0;
    format->type = '\0';
    while (str[i] && check_flags(str[i]))
        i++;
    if (check_type(str[i]))
        format->type = str[i];
    else
        return (-1);
    return (i);
}