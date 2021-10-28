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
    if (!s)
       ft_putstr("(null)", ret);
    else
        while (*s)
            ft_write(*s++, ret);
}

void    print_nb_di(int number, char *base, int *ret)
{

    if (number < 0)
    {
        ft_write('-', ret);
        number *= -1;
    }
    if (number > 9)
    {
        print_nb_di(number / 10, base , ret);
        print_nb_di(number % 10, base , ret);
    }
    else
        ft_write(*(base + number), ret);
}

void    print_nb_hex(unsigned int number, char *base, int *ret)
{
    if (number > 15)
    {
        print_nb_hex(number / 16, base , ret);
        print_nb_hex(number % 16, base , ret);
    }
    else
        ft_write(*(base + number), ret);
}

int     ft_printf(const char *fm, ...)
{
    va_list ap;
    int     ret;
    char    t[] = "0123456789";
    char    T[] = "0123456789abcdef";

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
                    print_nb_di(va_arg(ap, int), t, &ret);
                    break;
                case 'x':
                    print_nb_hex(va_arg(ap, unsigned int), T, &ret);
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
