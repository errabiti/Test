#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * _putch - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putch(char c)
{
	return (write(1, &c, 1));
}
/**
 * print_string - writes the string s to stdout
 * @s: The string to print
 *
 * Return: On success i.
 * On error, 6 is returned.
 */

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
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
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
				char c;

				c = va_arg(args, int);
				comp += _putch(c);
			}
			else if (*format == 's')
			{
				char *str;

				str = va_arg(args, char *);
				comp += print_string(str);
			}
			else if (*format == '%')
			{
				_putch('%');
				comp++;
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
 * main - check the code
 *
 * Return: Always 0.
 */

int main(void)
{
	_printf("%s %c\n", "bro", 'H');
	return (0);
}
