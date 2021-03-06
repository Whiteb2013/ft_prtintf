#include <stdio.h>
#include <unistd.h>
// #include <wchar.h>
// #include <locale.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putchar_int(unsigned int c)
{
    write(1, &c, 1);
}

void    ft_putchar_UTF8(unsigned int c)
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

// void	ft_putstr(char const *s)
// {
// 	while (s && *s)
// 	{
//         write(1, &(*s), 1);
//         *s++;
//     }
// }

//int    ft_putstr(unsigned char *s)
int    ft_putstr_UTF8(char const *s)
{
	int		i;

	i = 0;
    printf("checker || %s\n", s);
	if (!s)
		return (0);
	while (s[i])
    {
        printf("checker || %s\n", s);
		ft_putchar_UTF8(s[i++]);
    }
    return (1);
}

int     main()
{
    long int str_utf[4] = {0x00D8, 0x06D1, 0x2639, 0x1F6B5};
    int str[6] = {80, 81, 82, 83, 84, 85};
	//setlocale(LC_ALL, "en_US.UTF-8");
	int n, m;
	int j = 0;

    while (str[j])
	    ft_putchar_UTF8(str[j++]);
    j = 0;
    puts("");
    puts("");

	while (str_utf[j])
	    ft_putchar_UTF8(str_utf[j++]);
    puts("");
    puts("");

    // puts("printf %ls");
    // printf("%s", "asd");
    // puts("");
    // puts("");

    // puts("putchar");
    // putchar(88);
    // puts("");
    // puts("");

    // puts("putchar");
    // ft_putchar(88);
    // puts("");
    // puts("");

    // puts("putchar");
    // ft_putchar_int(88);
    // puts("");
    // puts("");

    puts("putchar_UTF8");
    ft_putchar_UTF8(8750);
    puts("");
    puts("");

    // puts("ft_putstr");
    // ft_putstr("∮4∮∮");
    // puts("");
    // puts("");

    // puts("printf");
    // printf("∮4∮∮");
    // puts("");
    // puts("");

    return 0;
}
