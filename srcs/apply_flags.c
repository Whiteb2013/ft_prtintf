#include "ft_printf.h"

int		apply_hash(t_format *format)
{
	if (format->type == 'x' || format->type == 'X' || format->type == 'p')
	{
		//printf("content = %s\n", format->content.string2show);
		if (!(format->content.string2show = join_prefix("0x", format->content.string2show, format)))
            return (0);
	}
	else if (format->type == 'f' && !format->precision)
	{
		if (!(format->content.string2show = join_postfix(format->content.string2show, ".", format)))
			return (0);
	}
	else if (format->type == 'o')
	{
		if (!(format->content.string2show = join_prefix("0", format->content.string2show, format)))
            return (0);
	}
	format->length = ft_strlen(format->content.string2show);
	return (1);
}

int		apply_space(t_format *format)
{
	if (format->type == '%' || format->type == 'u')
		return (1);
	if (!(format->content.string2show = join_prefix(" ", format->content.string2show, format)))
		return (0);
	format->length = ft_strlen(format->content.string2show);
	return (1);
}

int		apply_plus(t_format *format)
{
	if (format->type == 'u')
		return (1);
	if (!(format->content.string2show = join_prefix(&format->content.sign, format->content.string2show, format)))
		return (0);
	format->length = ft_strlen(format->content.string2show);
	return (1);
}

int		apply_zero(t_format *format)
{
	if (format->type == 'c')
		return (1);
	if (format->content.sign == '-' || format->flag.plus == 't')
		format->length = ft_strlen(format->content.string2show) + 1;
	if (!apply_width(format))
		return (0);
	format->length = ft_strlen(format->content.string2show);
	return (1);
}

int		apply_flags(t_format *format)
{
	if ((format->content.sign != '-' && format->flag.plus != 't' && format->flag.space == 't') && !apply_space(format))
		return (0);
	//printf("\ncontent = %s\n", format->content.string2show);
	if (format->flag.hash == 't' && format->flag.zero != 't' && !apply_hash(format))
		return (0);
	//printf("\ncontent = %s\n", format->content.string2show);
	if (format->flag.zero == 't' && format->flag.hash != 't' && !apply_zero(format))
		return (0);
	// next condition for the case: printf("%#08x", 42);
	if (format->flag.hash == 't' && format->flag.zero == 't')
	{
		if (format->width > 1)
			format->width -= 2;
		if (!apply_zero(format) || !apply_hash(format))
			return (0);
	}
	if ((format->content.sign == '-' || format->flag.plus == 't') && !apply_plus(format))
		return (0);
	format->length = ft_strlen(format->content.string2show);
	return (1);
}