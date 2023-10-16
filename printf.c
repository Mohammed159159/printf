#include "main.h"

/**
 * print_string - a function for printing a string
 * @s: string to be printed
 * Return: length of string printed
 */
int print_string(char *str)
{
	int temp_len = 0;
	char *null_string = "(null)";

	if (str == NULL)
	{
		write(1, null_string, 6);
		return (6);
	}

	while (str[temp_len] != '\0')
		temp_len++;

	write(1, str, temp_len);

	return (temp_len);
}

/**
 * print_char - a function for printing a char
 * @s: char to be printed
 * Return: 1 or 6 if char is null
 */
int print_char(char ch)
{
	char *null_string = "(null)";

	if (ch == NULL)
	{
		write(1, null_string, 6);
		return (6);
	}

	write(1, &ch, 1);

	return (1);
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
	va_list arg_list;

	if (format == NULL ||
		(format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(arg_list, format);

	while (*format)
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
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				len++;
			}
			if (*format == 'c')
			{
				c = va_arg(arg_list, int);
				len += print_char(c);
			}

			if (*format == 's')
			{
				str = va_arg(arg_list, char*);
				len += print_string(str);
			}
		}

		format++;
	}

	va_end(arg_list);

	return (len);
}
