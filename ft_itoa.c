#include "libft.h"

static int ft_itoa_len(int n)
{
    int len;
    int tmp;

    len = 0;
    if (n <= 0)
        len = 1;
    tmp = n;
    while (tmp != 0)
    {
        len++;
        tmp = tmp / 10;
    }
    return len;
}
char *ft_itoa(int n)
{
    char *str;
    int len;
    int sign;

    len = ft_itoa_len(n);
    str = malloc(len + 1);
    if (!str)
        return NULL;
    str[len] = '\0';
    sign = (n < 0) ? 1 : 0;
    if (n == 0)
        str[0] = '0';
    if (sign)
        str[0] = '-';
    while (n != 0)
    {
        if (n < 0)
            str[--len] = '0' - (n % 10);
        else
            str[--len] = '0' + (n % 10);
        n = n / 10;
    }
    return str;
}
