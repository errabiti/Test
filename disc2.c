#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int _putch(char c)
{
    return (write(1, &c, 1));
}

int print_string(char *s)
{
    int i = 0;

    if (s == NULL)
    {
        print_string("(null)");
        return (6);
    }
    while (s[i])
    {
        _putch(s[i]);
        i++;
    }
    return (i);
}

int len(int num)
{
    if (num == 0)
        return (0);
    return (1 + len(num / 10));
}

int print_int(int n)
{
    if (n == -2147483648)
    {
        _putch('-');
        _putch('2');
        print_int(147483648);
        return (1);
    }
    else if (n < 0)
    {
        _putch('-');
        n = -n;
    }
    if (n >= 10)
    {
        print_int(n / 10);
        print_int(n % 10);
    }
    else if (n < 10)
    {
        _putch(n + '0');
    }
    return (1);
}
/* printf("pjczoc %s ", "alx") */
int _printf(const char *format, ...)
{
    int comp = 0;

    va_list args;
    va_start(args, format);

    if (!format || !format[0])
        return (-1);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c') 
            {
                char c = va_arg(args, int);
                comp += _putch(c);
                
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                comp += print_string(str);
            }
            else if (*format == '%')
            {
                _putch('%');
                comp++;
            }
            else if (*format == 'd' || *format == 'i')
            {
                int nu = va_arg(args, int);
                if (nu < 0)
                    comp++;
                comp += len(nu);
                print_int(nu);
            }
            else 
            {
                _putch('%');
                comp++;
                if (*format)
                {
                  _putch(*format);   
                  comp++;
                }
            }
            format++;
        }
        else
        {
            _putch(*format);
            format++;
            comp++;
        }
    }
    return (comp);
}
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    return (0);
}
