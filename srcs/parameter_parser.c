#include "ft_printf.h"

/* defining default displaying options */
int     apply_default_options(t_format *format)
{
    format->flag.minus = 'f';
    format->flag.plus = 'f';
    format->flag.space = 'f';
    format->flag.zero = 'f';
    format->flag.hash = 'f';
    format->precision_flag = 'f';
    format->width = 0;
	if (format->type == 'f')
    	format->precision = 6;
	else
		format->precision = 0;
    return (1);
}

int     extract_flag(const char *str, t_format *format)
{
		if (str[0] == '-')
            format->flag.minus = 't';
        else if (str[0] == '+')
            format->flag.plus = 't';
        else if (str[0] == ' ')
            format->flag.space = 't';
        else if (str[0] == '0')
            format->flag.zero = 't';
        else if (str[0] == '#')
            format->flag.hash = 't';
        else if (str[0] == 'L')
            ft_strcpy(format->length_flag, "L");
        else if (str[0] == 'l' && str[1] && str[1] == 'l')
            ft_strcpy(format->length_flag, "ll");
        else if (str[0] == 'l')
            ft_strcpy(format->length_flag, "l");
        else if (str[0] == 'h' && str[1] && str[1] == 'h')
            ft_strcpy(format->length_flag, "hh");
        else if (str[0] == 'h')
            ft_strcpy(format->length_flag, "h");
		if (ft_isalpha(str[0]))
			return ((int)ft_strlen(format->length_flag));
		return (1);
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

/* extracting parameter options (flag, width, precision) */
void    get_options(const char *str, t_format *format, va_list ap, int i)
{
    int     k;

    k = 0;
    while (k < i)
    {
        //printf("str k = %s, char k = %c", str, str[k]);
        if (str[k] == '*')
        {
            format->width = va_arg(ap, size_t);
            k++;
        }
        else if (check_options(str[k], 'w'))
        {
            format->width = ft_atoi(&str[k]);
            k += int_length(format->width, 10);
        }
        else if (check_options(str[k], 'p'))
        {
            format->precision_flag = 't';
            if (k + 1 < i && str[k + 1] == '*')
            {
                format->precision = va_arg(ap, size_t);
                k += 2;
            }
            else
            {
            	format->precision = ft_atoi(&str[++k]);
                k += int_length(format->precision, 10);
            }
        }
        else if (check_options(str[k], 'f'))
            k += extract_flag(&str[k], format);
    }   
}