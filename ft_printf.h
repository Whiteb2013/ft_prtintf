#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct  s_format
{
    char        type;
    char        flag[3];
    size_t      width;
    size_t      precision;
    size_t      length;
}               t_format;

int     ft_printf(const char *str, ...);
int     get_type(const char *str, t_format *format);
void    get_options(const char *str, t_format *format, int i);
int     check_options(char c, char mode);
int     combine_options(t_format *format, va_list ap);

#endif