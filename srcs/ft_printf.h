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
# define EXP_EXCPN 32767

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
	size_t					base;
	size_t					width;
	size_t					precision;
	size_t					length;
	size_t					length_utf8;
	t_content				content;
	va_list					ap_root;
}							t_format;

typedef union				u_flt
{
	struct					s_union
	{
		unsigned long int	mantissa:64;
		unsigned short int	exponent:15;
		char				sign:1;
	}						t_union;
	long double				dbl;
}							t_flt;

typedef	struct				s_round
{
	int						elem_id;
	int						digit_in_elem;
}							t_round;

typedef struct				s_float
{
	t_flt					dbl;
	short int				fraction_len;
	short int				exponent;
	size_t					zero_counter;
	size_t					dec_prec;

}							t_float;

typedef struct				s_array
{
	unsigned long int		array[MAX_ELEM];
	int						current_element;
	size_t					array_len;
	size_t					first_len;
	t_round					round;
}							t_array;

int							display_static_buffer(const char **str, int i);
int							display_parameter_buffer(t_format *format);
int							ft_printf(const char *str, ...);
int							get_type(\
								const char *str, t_format *format, \
								va_list ap_root);
void						get_options(\
								const char *str, t_format *format, \
								va_list ap, int i);
void						dbl_get_decimal(t_format *format, t_float *flt,
								t_array *decimal);
void						dbl_get_integer(t_format *format, t_float *flt,
								t_array *integer);
int							check_options(char c, char mode);
int							check_type(char c);
int							convert2string(t_format *format, va_list ap);
int							convert_char2string(t_format *format, int a);
int							convert_char2utf8(t_format *format, int c);
int							convert_string2string(t_format *format, char *str);
int							convert_string2utf8(t_format *format, int *str);
int							convert_int2string(\
								t_format *format, long long int a, size_t base);
int							convert_xo2string(\
								t_format *format, unsigned long long a, \
								size_t base);
int							convert_short2string(\
								t_format *format, short a, size_t base);
int							convert_pointer2string(\
								t_format *format, long long int a);
int							convert_double2string(\
								t_format *format, long double a, size_t base);
int							convert_f2string(t_format *format, t_float *flt,
								t_array *integer, t_array *decimal);
int							convert_e2string(t_format *format, t_float *flt, \
								t_array *integer, t_array *decimal);
int							convert_g2string(t_format *format, t_float *flt, \
								t_array *integer, t_array *decimal);
char						*ft_itoa_base(unsigned long long b, size_t base, \
								size_t size);
char						*ft_itoa_base_array(t_array *array, size_t base);
char						*ft_itoa_base_array_precision(t_array *array, \
								size_t zero_counter, size_t precision);
char						*ft_itoa_base_array_precision_e(t_format *format, \
								t_array *array);
size_t						int_length(\
								unsigned long long int b, unsigned int base);
size_t						int_length_array(t_array *array, unsigned int base);
int							dbl_check_exceptions(t_float *flt);
int							dbl_define_exception(t_format *format, \
								t_float *flt);
void						dbl_dec_rounding(t_format *format, t_float *flt, \
								t_array *integer, t_array *decimal);
void						dbl_e_rounding(t_format *format, t_float *flt, \
								t_array *integer, t_array *decimal);
void						dbl_count_leading_zero(t_format *format, \
								t_float *flt, t_array *decimal, int flag);
void						dbl_remove_trailing_zeros(t_format *format);
void						dbl_update_array_length(t_format *format, \
								t_array *a);
int							subroutine_1(t_format *format, va_list ap, int k);
int							subroutine_2(const char *str, t_format *format, \
								va_list ap, \
								int ap_array_that_is_crutch_bc_norm[2]);
void						sum_array(t_array *a, t_array *exp);
void						sum_array_const(t_format *format, t_array *a, \
								unsigned long int value);
void						sum_decimal(t_array *a, t_array *exp);
int							sum_decimal_const(t_format *format, t_float *flt, \
								t_array *a);
t_array						*power(\
								unsigned long int base, short int power, \
								t_array *exp);
char						*join_prefix(char *s1, t_format *format);
char						*join_postfix(t_format *format, char *s2);
char						*join_strings(char *s1, char *s2, t_format *format);
int							apply_default_options_general(t_format *format, \
								va_list ap_root);
int							apply_default_options_dbl(t_format *format, \
								t_float *flt, size_t base);
int							apply_width(t_format *format);
int							apply_length(t_format *format, va_list ap);
int							apply_flags(t_format *format);
int							apply_precision(t_format *format);
int							apply_precision_string(t_format *format);
int							apply_precision_int(t_format *format);
int							format_string(t_format *format);
int							try_dollar(\
								const char *str, t_format *format, \
								va_list ap, int k);
void						ft_putchar_utf8(int c);
int							clean_format(t_format *format);
void						clean_array(t_array *array);
void						clean_array_initial(t_array *array);
int							undefined_behaviour(t_format *format);

#endif
