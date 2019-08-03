#include "ft_printf.h"

/* defining default displaying options */
void    apply_default_options(t_format *format)
{
    format->flag.minus = 'f';
    format->flag.plus = 'f';
    format->flag.space = 'f';
    format->flag.zero = 'f';
    format->flag.hash = 'f';
    format->width = 0;
    format->precision = 6;
}

/* checking if symbol matches any predefined format: 1 - true, 0 - false */
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

/* trying to take out parameter type: -1 - no type matches found, i - type found in i steps next to '%' */
int     get_type(const char *str, t_format *format)
{
    int     i;
    
    i = 0;
    /* listing symbols while it looks like parameter options (flag/width/precision) */
    while (str[i] && check_options(str[i], 'a'))
        i++;
    /* checking if we encountered type after options listing. If true - extracting parameter type, else - emergency exit */
    if (check_type(str[i]))
        format->type = str[i];
    else
        return (-1);
    /* defining default paramter options for further analyzes */
    apply_default_options(format);
    return (i);
}

// /* extracting flag and writing to a structure: 1 - flag consists of 1 symbol, 2 - flag consists of 2 symbols */
// int     get_flag(const char *str, t_format *format)
// {
//     format->flag[0] = str[0];
//     if ((str[0] == 'h' && str[1] == 'h') || (str[0] == 'l' && str[1] == 'l'))
//     {
//         format->flag[1] = str[1];
//         return (2);
//     }
//     return (1);
// }

/* extracting parameter options (flag, width, precision) */
void    get_options(const char *str, t_format *format, int i)
{
    int     k;

    k = 0;
    while (k < i)
    {
        if (str[k] >= '1' && str[k] <= '9')
        {
            format->width = ft_atoi(&str[k]);
            k += int_length(format->width, 10) - 1;
        }
        else if (str[k] == '-')
            format->flag.minus = 't';
        else if (str[k] == '+')
            format->flag.plus = 't';
        else if (str[k] == ' ')
            format->flag.space = 't';
        else if (str[k] == '0')
            format->flag.zero = 't';
        else if (str[k] == '#')
            format->flag.hash = 't';
        else if (str[k] == '.')
        {
            format->precision = ft_atoi(&str[++k]);
            //printf("============= format->precision = %zu\n", format->precision);
            k += int_length(format->precision, 10) - 1;
        }
        k++;
    }   
}