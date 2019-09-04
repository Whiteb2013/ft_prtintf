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

typedef struct	s_content
{
	char		*string2show;
	char		sign;
}				t_content;

typedef struct  s_format
{
	char        type;
	char		*length_flag;
	char        precision_flag;
	char        zero_flag;
	t_flag      flag;
	size_t      width;
	size_t      precision;
	size_t      length;
	t_content   content;
}               t_format;

int		display_static_buffer(const char **str, int i);
int		display_parameter_buffer(t_format *format);
int     ft_printf(const char *str, ...);
int     get_type(const char *str, t_format *format);
void    get_options(const char *str, t_format *format, va_list ap, va_list ap2, int i);
int     check_options(char c, char mode);
int     convert2string(t_format *format, va_list ap);
char    *ft_itoa_base(unsigned long long b, size_t base);
size_t  int_length(unsigned long long int b, unsigned int base);
int     get_decimal(size_t precision, long double a, long long int *integer);
//int     get_decimal(size_t precision, long double a, int *integer);
char	*join_prefix(char *s1, t_format *format);
char	*join_postfix(t_format *format, char *s2);
char	*join_strings(char *s1, char *s2, t_format *format);
int		apply_width(t_format *format);
int		apply_flags(t_format *format);
int		apply_precision(t_format *format);
int		apply_precision_string(t_format *format);
int		apply_precision_int(t_format *format);
int		apply_precision_float(t_format *format);
int		format_string(t_format *format);
int		cleaner(t_format *format);

#endif