#include "ft_printf.h"

char	*join_prefix(char *s1, char *s2, t_format *format)
{
	char *str;
	
	str = ft_strjoin(s1, s2);
	free (s2);
	format->length = ft_strlen(str);
	return (str);
}

char	*join_postfix(char *s1, char *s2, t_format *format)
{
	char *str;
	
	str = ft_strjoin(s1, s2);
	free (s1);
	format->length = ft_strlen(str);
	return (str);
}

char	*join_strings(char *s1, char *s2, t_format *format)
{
	char *str;
	
	str = ft_strjoin(s1, s2);
	//free (s1);
	//free (s2);
	format->length = ft_strlen(str);
	return (str);
}