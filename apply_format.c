#include "ft_printf.h"

/* 12.07 here it's time to reveal itoa_base! */
void    apply_int_format(t_format *format, int a)
{

}

void    apply_char_format(t_format *format, int a)
{
    write (1, &a, 1);
}

void    apply_string_format(t_format *format, char *s)
{
    write (1, s, ft_strlen(s));    
}

/* pointer conversion doesn't work yet :( */
void    apply_pointer_format(t_format *format, void *pointer)
{
    unsigned char *p;

    p = (unsigned char *)pointer;
    write (1, p, 11);
}

void    apply_unsigned_format(t_format *format, unsigned char *a)
{

}

void    apply_double_format(t_format *format, double a)
{
    
}

/* 12.07 extend for remaining formats: d, i, o, u, x, X, f */
void    combine_options(t_format *format, va_list ap)
{
    if (format->type == '%')
        apply_char_format(format, '%');
    if (format->type == 'c')
        apply_char_format(format, va_arg(ap, int));
    else if (format->type == 's')
        apply_string_format(format, va_arg(ap, char *));
    else if (format->type == 'p')
        apply_pointer_format(format, va_arg(ap, void *));
    else if (format->type == 'd' || format->type == 'i' || format->type == 'x' || format->type == 'X')
        apply_int_format(format, va_arg(ap, int));
    else if (format->type == 'o' || format->type == 'u')
        apply_unsigned_format(format, va_arg(ap, unsigned char *));
    else if (format->type == 'f')
        apply_double_format(format, va_arg(ap, double));
}