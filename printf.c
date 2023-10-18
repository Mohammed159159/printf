#include "main.h"

/**
 * _printf - an augmentation for printf
 * @format: formatted string
 * Return: no. chars of format
 */
int _printf(const char *format, ...)
{
	char c, *str;
	int len = 0, n;
	va_list arg_list;

	if (format == NULL)
		return (-1);
	if (*format == '\0')
		return (0);

	va_start(arg_list, format);

	while (*format && format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			len++;
		}
		else
		{
			format++;
			if (*format == '\0')
				return (-1);
			if (*format == '%')
			{
				write(1, format, 1);
				len++;
			}
			else if (*format == 'c')
			{
				c = va_arg(arg_list, int);
				len += print_char(c);
			}
			else if (*format == 's')
			{
				str = va_arg(arg_list, char*);
				len += print_string(str);
			}
			else if (*format == 'd' || *format == 'i')
			{
				n = va_arg(arg_list, int);
				len += print_dec(n);
			}
			else if (*format == 'b')
			{
				n = va_arg(arg_list, int);
				len += print_bin(n);
			}
			else
				return (-1);
		}
		format++;
	}
	va_end(arg_list);
	return (len);
}
