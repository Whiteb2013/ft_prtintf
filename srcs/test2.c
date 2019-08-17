#include <stdio.h>

void    convert(int nb)
{
    int i;
    while (nb)
    {
        i = nb % 10;
        nb = nb / 10;
        printf("%i", i);
    }
}

void    rec(int nb)
{
    int i;
    if (nb > 0)
    {
        rec(nb / 10);
        i = nb % 10;
        printf("%i", i);
    }
}

int     main()
{
    //convert(12345);
    puts("");
    rec(1234500);
    puts("");
    return 0;
}