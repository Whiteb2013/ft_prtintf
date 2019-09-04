#include <stdio.h>
#include "ft_printf.h"



int main()
{
    //#define RED   "\x1B[31m"

    printf(COLOR_RED "This text is RED!" COLOR_RESET "\n");
    printf(COLOR_GREEN "This text is GREEN!" COLOR_RESET "\n");
    printf(COLOR_YELLOW "This text is YELLOW!" COLOR_RESET "\n");
    printf(COLOR_BLUE "This text is BLUE!" COLOR_RESET "\n");
    printf(COLOR_MAGENTA "This text is MAGENTA!" COLOR_RESET "\n");
    printf(COLOR_CYAN "This text is CYAN!" COLOR_RESET "\n");

    printf("Le fichier{COLOR_CYAN}CYAN contient : {COLOR_RED}RED\n");
    printf("Le fichier{COLOR_L_RED}CYAN{eoc} contient : {red}RED{eoc}\n");

    //printf "%40s\n" "${blue}This text is blue${normal}"
    //printf ("%40s\n" "tput setaf 1This text is blue$");
    //i = printf("%s\n", NULL);
    //printf("\ni = %i\n", i);
    // puts("test0");
    // puts("printf");
    puts("");
    printf("%1$d:%3$*.*d:%d:%3$d:%d\n", 1, 2, 3, 4, 5);
    puts("");
    printf("%d:%d:%1$d:%d:%d\n", 1, 2, 3, 4, 5);
    puts("");
    printf("%1$d:%3$*.*d:%d:%d:%d:%d:%d\n", 1, 2, 3, 4, 5, 6, 7);
    puts("");
    // puts("printf");
    // printf("%1$10d:%2$10d:%03$d:%-4$d:%5$d\n", 1, 2, 3, 4, 5);
    // puts("");
    puts("ft_printf");
    ft_printf("%1$d:%3$*.*d:%d:%3$d:%d\n", 1, 2, 3, 4, 5);
    puts("");
    ft_printf("%d:%d:%1$d:%d:%d\n", 1, 2, 3, 4, 5);
    puts("");
    ft_printf("%1$d:%3$*.*d:%d:%d:%d:%d:%d\n", 1, 2, 3, 4, 5, 6, 7);
    //ft_printf("%1$d:%2$d:%3$d:%4$d:%5$d\n", 1, 2, 3, 4, 5);
    //ft_printf("%10.f\n", 12.34);
    puts("");
    puts("");
    ft_printf("some red{red}%s\n", "WOW");

    return (0);
}

// int				main(void)
// {
//    ft_printf("%20.15d\n", 54321);
// //   ft_printf("%-10d\n", 3);
// //   ft_printf("% d\n", 3);
// //   ft_printf("%+d\n", 3);
// //   ft_printf("%010d\n", 1);
//   return (0);
// }
