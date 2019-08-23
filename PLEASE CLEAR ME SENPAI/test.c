#include <stdio.h>
#include <stdlib.h>

size_t  int_length(unsigned long long int b, unsigned int base)
{
    size_t i;

    i = 0;
    while ((b = b / base))
        i++;
    return (++i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *p;

	p = b;
	while (len--)
		*p++ = (unsigned char)c;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	if (n)
		ft_memset(s, 0, n);
}

void	*ft_memalloc(size_t size)
{
	void	*m;

	if (!(m = malloc(size)))
		return (NULL);
	ft_bzero(m, size);
	return (m);
}

char	*ft_strnew(size_t size)
{
	char *str;

	if (!(size + 1) || !(str = (char *)ft_memalloc(size + 1)))
		return (NULL);
	return (str);
}

char    *ft_itoa_base_2(long long int int2convert, size_t base)
{
    char    *str1;
    char    *str2;
    size_t	i;
    size_t  k;
    char	values[16] = "0123456789abcdef";
    
    i = int_length(int2convert, 10);
    if (!(str1 = ft_strnew(i)) || !(str2 = ft_strnew(i)))
        return (NULL);
    k = 0;
    while (int2convert)
    {
        str1[k++] = values[int2convert % base];
        int2convert = int2convert / base;
    }
    i = 0;
    str2[k] = '\0';
    while (k > 0)
        str2[i++] = str1[--k];
    return (str2);
}

int     main()
{
    printf("result = %s\n", convert(4294967254, 16));
    return 0;
}