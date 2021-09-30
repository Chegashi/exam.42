#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int abs(int n)
{
    return ( n > 0 ? n : -1 * n);
}

void ft_putstr(char *s)
{
    if (!s)
    {
        write (1, "(null)", 6);
        return ;
    }
    while (*s)
        write(1, s++, 1);
}

void    print_nb(int nember, int base)
{
    char    *base_t;
    char    *nbr;
    int     i;
    int     signe;
    long    n;

    n = nember;
    signe = 0;
    i = -1;
    if (!n)
    {    
        write(1, "0", 1);
        return ;
    }
    if (n < 0)
        signe = 1;
    if (n < 0 && base== 16)
    {
        n += 4294967296;
    }
    if (base == 10)
        base_t = strdup("0123456789");
    else
        base_t = strdup("0123456789abcdef");
    nbr = (char*)malloc(sizeof(char) * 11); 
    while (n)
    {
        *(nbr + ++i) = *(base_t + abs(n % base));
        n /= base;
    }
    *(nbr + ++i) = 0;
    if (signe && base == 10)
        write(1, "-", 1);
    while (--i >= 0)
        write (1, nbr + i, 1);
    free(base_t);
    free(nbr);
}

int     ft_printf(const char *fm, ...)
{
    va_list ap;

    va_start(ap, fm);
    while (*fm)
    {
        if (*fm != '%')
            write(1, fm, 1);
        else
        {
            fm++;
            switch (*fm)
            {
                case 'd':
                    print_nb(va_arg(ap, int), 10);
                    break;
                case 'x':
                    print_nb(va_arg(ap, unsigned int), 16);
                    break;
                case 's':
                    ft_putstr(va_arg(ap, char*));
                    break;
                default:
                    break;
            }
        }
        fm++;
    }
    va_end(ap);
    return (0);
}
