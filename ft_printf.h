#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct  s_format
{
    char        type;
    char        *flag;
    size_t      width;
    size_t      precision;
}               t_format;

int     ft_printf(const char *str, ...);
int     get_type(const char *str, t_format *format);
#endif