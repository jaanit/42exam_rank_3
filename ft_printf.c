#include <unistd.h>
# include<stdarg.h>

int len_num(long nb)
{
    int len = 1;

    if (nb < 0)
    {
        nb*=-1;
        len++;
    }
    if (nb >= 0 && nb <= 9)
        return(len);
    while(nb > 9)
    {
        len++;
        nb/=10;
    }
    return (len);
}

int     ft_putstr(char *str)
{
    int i = 0;
    if (!str)
    {
        write(1, "(null)", 6);
        return(6);
    }
    while(str[i])
    {
        write(1,&str[i], 1);
        i++;
    }
    return(i);
}

int     ft_putchar(char c)
{
    int i =0;
    write(1,&c,1);
    return (1);
}

int     ft_putnbr(long x)
{
    if (x < 0)
        {
            ft_putchar('-');
            x*=-1;
        }
    if (x<= 9)
    {
        ft_putchar(x + 48);
    }
    if (x > 9)
    {
        ft_putnbr(x / 10);
        ft_putnbr(x % 10);

    }
    return(len_num(x));
}

int     len_hexa(unsigned int nb)
{
    int len =0;
    if(nb == 0)
        return(1);
    while (nb)
    {
        len++;
        nb/=16;
    }
    return(len);
    
}

int ft_hexa(unsigned int nb)
{
    char *base;
    base = "123456789abcdef";
    
    if (nb>16)
    {
       ft_hexa( nb/=16);
       ft_hexa(nb%16);
    }
    else   
        write(1,&base[nb],1);
    return(len_hexa(nb));
}

int hexa(unsigned int nb)
{
    char *base;
    base = "123456789ABCDEF";
    
    if (nb>16)
    {
       ft_hexa( nb/=16);
       ft_hexa(nb%16);
    }
    else   
        write(1,&base[nb],1);
    return(len_hexa(nb));
}

int ft_type(va_list arg, const char c)
{
    int len_printf = 0;

    if(c== 's')
        len_printf += ft_putstr(va_arg(arg, char *));
    else if (c == 'i' || c == 'd')
        len_printf += ft_putnbr(va_arg(arg, long));
    else if (c == 'x')
         len_printf+= ft_hexa(va_arg(arg, unsigned int));
    else if (c == 'X')
          len_printf+= hexa(va_arg(arg, unsigned int));
    return(len_printf);
}

int ft_printf(const char *str, ...)
{
    va_list arg;
    int len_printf;
    int i;

    i = 0;
    len_printf = 0;
    va_start(arg,str);

    while(str[i])
    {
        if(str[i] == '%')
        {
            if(str[i + 1] == '\0')
                break;
            else
            len_printf += ft_type(arg,str[i+1]);
            i++;

        }
        else
            ft_putchar(str[i]);
            i++;
    }
    va_end(arg);
    return(len_printf);
}
