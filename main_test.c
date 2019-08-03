#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...);

int main()
{
    const double RENT = 3852.51;
    
    int n = printf("1%23.0f\n", 12.3);
    int m = ft_printf("1%23.0f\n", 12.3);
    printf("%d = %d\n", n, m);
    puts("");
    
    printf("123%010%%c%s\n", 'a', "abc");
    ft_printf("123%010%%c%s\n", 'a', "abc");
    puts("");

    printf("123%10.10%%c%s\n", 'a', "abc");
    ft_printf("123%10.10%%c%s\n", 'a', "abc");
    puts("");

    printf("%x %X %#x\n", 1234234, 1234234, 1234234);
    ft_printf("%x %X %#x\n", 1234234, 1234234, 1234234);
    puts("");

 
    printf("%p %p* %5p %-20p\n", "a", "", "", "");
    ft_printf("%p %p* %5p %-20p\n", "a", "", "", "");
    puts("");

    printf("**%d**% d% d **\n", 42, 42, -42);
    ft_printf("**%d**% d% d **\n", 42, 42, -42);
    puts("");

    printf("%o\n", 10);
    ft_printf("%o\n", 10);
    puts("");

    printf("%u\n", 10);
    ft_printf("%u\n", 10);
    puts("");

    printf("*%f*\n", RENT);
    ft_printf("*%f*\n", RENT);
	puts("");
    
    printf("*%4.0f*\n", RENT);
    ft_printf("*%4.0f*\n", RENT);
	puts("");

	/*
    //printf("123%.10-+ 0#10.10d\n", 777);
	printf("123%.12+ 0#15.8d\n", 777);
    ft_printf("123%.12+ 0#15.8d\n", 777);
    printf("123%.10-10.10d\n", 777);
	ft_printf("123%.10-10.10d\n", 777);
    printf("123%.10+10.10d\n", 777);
	ft_printf("123%.10+10.10d\n", 777);
    printf("123%.10 10.10d\n", 777);
	ft_printf("123%.10 10.10d\n", 777);
    printf("123%.10010.10d\n", 777);
	ft_printf("123%.10010.10d\n", 777);
    printf("123%.10#10.10d\n", 777);
	ft_printf("123%.10#10.10d\n", 777);
    puts("");
    
    printf("*%3.1f*\n", RENT);
	printf("*%10.3f*\n", RENT);
	printf("*%+4.2f*\n", RENT);
    puts("");

    printf("\n");
    
    printf("%c %*c* %5c %-5c\n", 'a', 8, 'b', 'c', 'd');
    printf("%p %*p* %5p %-20p\n", "a", 8, "", "", "");
    printf("%10.2s=%-8s+%*s*\n", "a*(b+c)", "ab", 3, "ac");
    printf("%#*% % 0 %  %-8%   %+8%     % 0 8%5c", 8);

    printf("\n");

    
	
	printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);
    
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