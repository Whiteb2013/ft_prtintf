#include "ft_printf.h"

// int		change_zero(t_format *format)
// {
// 	//printf("\nwidth = %d\n", format->width);
// 	if (format->width == 0)
// 	{
// 		format->content.string2show = ft_strnew(0);
// 	}
// 	else
// 	{
// 		format->content.string2show[format->width - 1] = ' ';
// 	}
	
// 	return (1);
// }

int		format_string(t_format *format)
{
	int i;
	
	i = -1;
	if (format->precision_flag == 't' && !apply_precision(format))
		return (0);
	//printf("\ncontent = %s\n", format->content.string2show);
	if (!apply_flags(format))
		return (0);
	//printf("\ncontent = %s\n", format->content.string2show);
	if (!apply_width(format))
		return (0);
	if (format->type >= 'A' && format->type <= 'Z')
        while (format->content.string2show[++i])
            format->content.string2show[i] = ft_toupper(format->content.string2show[i]);
	// don't know where will be better to place next part (for ft_printf("@moulitest: %#.x %#.0x", 0, 0);)
	// if (format->precision_flag == 't' && format->precision == 0 && format->zero_flag == 't')
	// {
	// 	// change '0' in content for something else ('' or ' ')
	// 	change_zero(format);
	// }
	// printf("\nwidth = %d || prec_flag = %c || prec = %d || content = %s\n",format->width, format->precision_flag, format->precision, format->content.string2show);
	// if (format->width != 0 && format->precision_flag == 't' && format->precision == 0 && ft_atoi(format->content.string2show) == 0)
	// 	format->content.string2show[format->width - 1] = ' ';
	return (1);
}