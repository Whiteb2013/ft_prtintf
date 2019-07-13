#include "ft_printf.h"

size_t  int_length(unsigned long long int b, unsigned int base)
{
    size_t i;

    i = 0;
    while ((b = (b / base)))
        i++;
    return (++i);
}

char    *ft_itoa_base(size_t b, size_t base, t_format *format, char *str)
{
    size_t	i;
    char	values[16] = "0123456789abcdef";
    
    i = 0;
    if (format->type == 'X')
        while (values[i])
        {
            values[i] = ft_toupper(values[i]);
            i++;
        }
    i = format->length;
    str[i] = '\0';
    while (b / base)
    {
        str[--i] = values[b % base];
        b = b / base;
    }
    str[--i] = values[b % base];
    return (str);
}

/* decimal calculation goes wrong here due to unknown reason */
int     get_decimal(size_t precision, double a)
{
    int     decimal;
    size_t  i;
    
    decimal = 0;
    i = 0;
    while (i <= precision)
    {
        decimal = decimal * 10 + (int)a;
        a = (a - (int)a) * 10;
        printf("decimal = %d, float = %f\n", decimal, a);
        i++;
    }
    if ((int)a >= 5)
        return (decimal / 10 + 1);
    else
        return (decimal / 10);
}

int		convert2char(t_format *format, int a)
{
    format->length = 1;
    write (1, &a, 1);
	return (1);
}

int		convert2string(t_format *format, char *s)
{
    format->length = ft_strlen(s);
    write (1, s, ft_strlen(s));
	return (1);    
}

int     convert2int(t_format *format, long long int a, size_t base)
{
    char                    *str;
    size_t                  sign;
    unsigned long long int  b;

    sign = 0;
    if (a < 0)
    {
        b = -a;
        sign = 1;
    }
    else
        b = a;
    format->length = int_length(b, base) + sign;
    if (!format->length || !(str = ft_strnew(format->length)))
        return (0);
    str = ft_itoa_base(b, base, format, str);
    if (sign)
        str[0] = '-';
    convert2string(format, str);
    free (str);
    return (1);
}

int		convert2float(t_format *format, double a)
{
	int     integer;
    int     decimal;

    integer = (int)a;
    decimal = get_decimal(format->precision, (a - (int)a) * 10);
    /* this is for testing only. Has to be improved 1) add +1 in case of exceeded precision 2)adopt length, etc. */
    convert2int(format, integer, 10);
    convert2char(format, '.');
    convert2int(format, decimal, 10);
    return (1);
}

int     combine_options(t_format *format, va_list ap)
{
    int res;
	
	if (format->type == '%')
        res = convert2char(format, '%');
    else if (format->type == 'c')
        res = convert2char(format, va_arg(ap, int));
    else if (format->type == 's')
        res = convert2string(format, va_arg(ap, char *));
    else if (format->type == 'p')
        res = convert2int(format, va_arg(ap, long long int), 16);
    else if (format->type == 'd' || format->type == 'i')
        res = convert2int(format, va_arg(ap, int), 10);
    else if (format->type == 'x' || format->type == 'X')
        res = convert2int(format, va_arg(ap, unsigned int), 16);
    else if (format->type == 'o')
    	res = convert2int(format, va_arg(ap, unsigned int), 8);
    else if (format->type == 'u')
		res = convert2int(format, va_arg(ap, unsigned int), 10);
	else if (format->type == 'f')
        res = convert2float(format, va_arg(ap, double));
    return (res);
}