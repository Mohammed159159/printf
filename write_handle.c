#include "main.h"

/**
 * print_int - a function for printing an integer
 * @num: integer to be printed
 * Return: length of integer printed
 */
int print_int(int num)
{
    char str[12]; // Array to hold digits of int
    int i = 0, j, len;
    char temp;
    if (num == 0)
    {
        write(1, "0", 1);
        return (1);
    }
    if (num < 0)
    {
        write(1, "-", 1);
        num = -num;
    }
    while (num != 0)
    {
        str[i++] = (num % 10) + '0';
        num = num / 10;
    }
    str[i] = '\0';
    len = i;
    for (j = 0; j < i / 2; j++)
    {
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
    write(1, str, len);
    return (len);
}

/**
 * _printf - an augmentation for printf
 * @format: formatted string
 * Return: no. chars of format
 */
int _printf(const char *format, ...)
{
	int len = 0;
	char c;
	char *str;
	int num;
	va_list arg_list;

	if (format == NULL)
		return (-1);

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
				num = va_arg(arg_list, int);
				len += print_int(num);
			}
			else
				return (-1);
		}

		format++;
	}

	va_end(arg_list);

	return (len);
}
