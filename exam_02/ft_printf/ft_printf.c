#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

void ft_write(char c, int *ret)
{
    write(1, &c, 1);
    (*ret)++;
}

void ft_putstr(char *s, int *ret)
{
    while (*s)
        ft_write(*s++, ret);
}

void    print_nb(int number, char *base, int b, int *ret)
{
    long long   n;

    n = number;
    if (!n)
    {    
        ft_write('0', ret);
        return ;
    }
    if (n < 0 && b == 10)
    {
        ft_write('-', ret);
        n *= -1;
    }
    if (n < 0 && b== 16)
        n += 4294967296;
    if ((n > 9 && b == 10) || (n > 15 && b == 16))
    {
        print_nb(n / b, base , b, ret);
        print_nb(n % b, base , b, ret);
    }
    else
        ft_write(*(base + n), ret);
}

int     ft_printf(const char *fm, ...)
{
    va_list ap;
    int     ret;
    char    *t = "012356789";
    char    *T = "0123456789abcdef";

    ret = 0;
    va_start(ap, fm);
    while (*fm)
    {
        if (*fm != '%')
            ft_write(*fm, &ret);
        else
        {
            fm++;
            switch (*fm)
            {
                case 'd':
                    print_nb(va_arg(ap, int), t, 10, &ret);
                    break;
                case 'x':
                    print_nb(va_arg(ap, unsigned int), T, 16, &ret);
                    break;
                case 's':
                    ft_putstr(va_arg(ap, char*), &ret);
                    break;
                default:
                    break;
            }
        }
        fm++;
    }
    va_end(ap);
    return(ret);
}
