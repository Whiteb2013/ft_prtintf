#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...);

int main()
{
    const double RENT = 3852.99;

    printf("123%-10.5%\n");
    ft_printf("123%-10.5%\n");
    /*
    printf("%c %*c* %5c %-5c\n", 'a', 8, 'b', 'c', 'd');
    printf("%p %*p* %5p %-20p\n", "a", 8, "", "", "");
    printf("%10.2s=%-8s+%*s*\n", "a*(b+c)", "ab", 3, "ac");
    printf("%#*% % 0 %  %-8%   %+8%     % 0 8%5c", 8);

    printf("\n");

    printf("%x %X %#x\n", 31, 31, 31);
	printf("**%d**% d% d **\n", 42, 42, -42);
	printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);

    printf("\n");

    printf("*%8f*\n", RENT);
	printf("*%4.2f*\n", RENT);
	printf("*%3.1f*\n", RENT);
	printf("*%10.3f*\n", RENT);
	printf("*%+4.2f*\n", RENT);

    printf("\n");

    char c = 255;
    int a = -255;
    short int aa = -255;
    long int b = -255;
    long long int d = -255;

    printf("%X %X\n", c, a);
    printf("%X %X\n", (unsigned char)c, (unsigned char)a);
    printf("%hhX %hhX\n", c, a);

    printf("%X %X\n", c, aa);
    printf("%X %X\n", (unsigned short int)c, (unsigned short int)aa);
    printf("%hX %hX\n", c, aa);

    printf("%X %X\n", b, d);
    printf("%X %X\n", (unsigned long int)b, (unsigned long long int)d);
    printf("%lX %llX\n", b, d);
    */

    return (0);
}