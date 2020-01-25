/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:04:19 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/11 21:04:22 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MAX_ELEM 300000
# define BASE 10000
# define BASE_LEN 4
# define EXP_DFLT 16383

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef	struct				s_flag
{
	char					minus;
	char					plus;
	char					space;
	char					zero;
	char					hash;
}							t_flag;

typedef struct				s_content
{
	char					*string2show;
	char					sign;
}							t_content;

typedef struct				s_format
{
	char					type;
	char					*length_flag;
	char					precision_flag;
	char					zero_flag;
	t_flag					flag;
	size_t					width;
	size_t					precision;
	size_t					length;
	size_t					length_utf8;
	t_content				content;
	va_list					ap_root;
}							t_format;

typedef union				u_dbl
{
	struct					s_union
	{
		unsigned long int	mantissa:64;
		unsigned short int	exponent:15;
		char				sign:1;
	}						t_union;
	long double				dbl;
}							t_dbl;

typedef struct				s_float
{
	unsigned long int		array[MAX_ELEM];
	int						current_element;
}							t_float;

int							display_static_buffer(const char **str, int i);
int							display_parameter_buffer(t_format *format);
int							ft_printf(const char *str, ...);
// int						ft_printf_2(const char *str, ...);
int							get_type(\
								const char *str, t_format *format, \
								va_list ap_root);
void						get_options(\
								const char *str, t_format *format, \
								va_list ap, int i);
int							check_options(char c, char mode);
int							check_type(char c);
int							convert2string(t_format *format, va_list ap);
int							convert_int2string(\
								t_format *format, long long int a, size_t base);
int							convert_xo2string(\
								t_format *format, unsigned long long a, \
								size_t base);
int							convert_short2string(\
								t_format *format, short a, size_t base);
int							convert_fge2string(\
								t_format *format, long double a);
int							convert_efloat2string(t_format *format, double a);
int							convert_gfloat2string(t_format *format, double a);
int							convert_pointer2string(\
								t_format *format, long long int a);
char						*ft_itoa_base(unsigned long long b, size_t base, \
								size_t size);
char						*ft_itoa_base_array(t_float *array, size_t base);
char						*ft_itoa_base_array_precision(\
								t_float *array, size_t base, \
								size_t zero_counter, size_t precision);
char						*ft_itoa_base_array_precision_e(t_float *array, \
								size_t base, t_format *format);
size_t						int_length(\
								unsigned long long int b, unsigned int base);
size_t						int_length_array(t_float *array, unsigned int base);
void						sum_integer(t_float *a, t_float *exp);
void						sum_integer_const(\
								t_float *a, unsigned long int value);
void						sum_decimal(t_float *a, t_float *exp);
int							sum_decimal_const(t_float *a, \
								size_t *zero_counter, int array_elem_id, \
								int digit_in_elem);
t_float						*power(\
								unsigned long int base, short int power, \
								t_float *exp);
int							get_decimal(t_dbl dbl, t_float *decimal, \
								short int fraction_length, short int exponent);
int							get_integer(t_dbl dbl, t_float *integer, \
								short int *exponent);
char						*join_prefix(char *s1, t_format *format);
char						*join_postfix(t_format *format, char *s2);
char						*join_strings(char *s1, char *s2, t_format *format);
int							apply_width(t_format *format);
int							apply_length(t_format *format, va_list ap);
int							apply_flags(t_format *format);
int							apply_precision(t_format *format);
int							apply_precision_string(t_format *format);
int							apply_precision_int(t_format *format);
int							apply_precision_float(t_format *format);
int							apply_precision_float_2(\
								t_format *format, t_float *integer, \
								t_float *decimal, size_t zero_counter);
int							format_string(t_format *format);
int							try_dollar(\
								const char *str, t_format *format, \
								va_list ap, int k);
void						ft_putchar_utf8(int c);
int							convert_char2utf8(t_format *format, int c);
int							convert_string2utf8(t_format *format, int *str);
int							cleaner(t_format *format);
void						array_cleaner(t_float *array);
int							undefined_behaviour(t_format *format);

#endif
