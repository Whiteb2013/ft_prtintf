#include "ft_printf.h"

size_t  int_length(unsigned long long int b, unsigned int base)
{
    size_t i;

    i = 0;
    while ((b = (b / base)))
        i++;
    return (++i);
}

int     get_decimal(size_t precision, double a, long long int *integer)
{
    int     decimal;
    size_t  i;
    
    decimal = 0;
    i = 0;
	while (i++ < precision)
        a = a * 10;
    decimal = (int)a;
    if ((a - (int)a) * 10 > 5)
        {
			if (!precision)
				{
					*integer = *integer + 1;
					return (0);
				}
			return (decimal + 1);
		}
    else
        return (decimal);
}