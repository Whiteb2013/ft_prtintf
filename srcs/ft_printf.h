#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct  s_flag
{
    char        minus;
    char        plus;
    char        space;
    char        zero;
    char        hash;
}               t_flag;

typedef struct  s_format
{
    char        type;
	char		*length_flag;
    char        precision_flag;
    t_flag      flag;
    size_t      width;
    size_t      precision;
    size_t      length;
}               t_format;

int     ft_printf(const char *str, ...);
int     get_type(const char *str, t_format *format);
void    get_options(const char *str, t_format *format, va_list ap, int i);
int     check_options(char c, char mode);
int     combine_options(t_format *format, va_list ap);
char    *ft_itoa_base(size_t b, size_t base, t_format *format, char *str);
size_t  int_length(unsigned long long int b, unsigned int base);
int     get_decimal(size_t precision, double a, long long int *integer);
char	*join_prefix(char *s1, char *s2, t_format *format);
char	*join_postfix(char *s1, char *s2, t_format *format);
char	*join_strings(char *s1, char *s2, t_format *format);
char	*apply_width(char *s, t_format *format);
char	*apply_flags(char *s, t_format *format);

#endif