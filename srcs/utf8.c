#include "ft_printf.h"

void	ft_putchar_utf8(unsigned int c)
{
	unsigned char   ch[4];

	if (c < 0x80)
		write(1, &c, 1);
	else if (c < 0x800)
	{
		ch[0] = (c>>6) | 0xC0;
		ch[1] = (c & 0x3F) | 0x80;
		write(1, &ch, 2);
	}
	else if (c < 0x10000)
	{
		ch[0] = (c>>12) | 0xE0;
		ch[1] = ((c>>6) & 0x3F) | 0x80;
		ch[2] = (c & 0x3F) | 0x80;
		write(1, &ch, 3);
	}
	else if (c < 0x110000)
	{
		ch[0] = (c>>18) | 0xF0;
		ch[1] = ((c>>12) & 0x3F) | 0x80;
		ch[2] = ((c>>6) & 0x3F) | 0x80;
		ch[3] = (c & 0x3F) | 0x80;
		write(1, &ch, 4);
	}
}

void	ft_putstr_utf8(long int *str)
{
	size_t	i;
	while (str[i])
		ft_putchar_utf8(str[i++]);
}
