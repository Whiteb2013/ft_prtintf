#include "printf.h"

int     check_precision(char c)
{
    if (c == '.')
        return (1);
    else
        return (0);
}

/* replace with ft_isdigit */
int     check_width(char c)
{
    if (c >= '1' && c <= '9')
        return (1);
    else
        return (0);
}

int     check_flag(char c)
{
    char    *options;
    int     i;

    options = " #0-+hlL";
    i = 0;
    while (options[i])
    {
        if (options[i] == c)
            return (1);
        else
            i++;
    }
    return (0);
}

/*checking modes:
a - all (check if symbol is part of flag or width or precision);
f - flag (check if symbol is part of flag);
w - width (check if symbol is part of width);
p - precision (check if symbol is part of precision);
*/
int     check_options(char c, char mode)
{
    if (mode == 'a')
        return (check_flag(c) || check_width(c) || check_precision(c));
    else if (mode == 'f')
        return (check_flag(c));
    else if (mode == 'w')
        return (check_width(c));
    else if (mode == 'p')
        return (check_precision(c));
    return (0);
}