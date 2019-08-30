#include "ft_printf.h"

int		cleaner(t_format *format)
{
	if (format)
	{
		if (format->content.string2show && format->type != 's')
		{
			//printf("\ntype = %c\n", format->type);
			free(format->content.string2show);
		}
		if (format->length_flag)
			free(format->length_flag);
		free(format);
	}
	return (-1);  // why -1? why? god please WHYYY???
}