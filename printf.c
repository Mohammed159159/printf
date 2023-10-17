#include "main.h"

/**
 * print_string - a function for printing a string
 * @str: string to be printed
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
 * @ch: char to be printed
 * Return: 1 or 6 if char is null
 */
int print_char(char ch)
{

	write(1, &ch, 1);
	return (1);
}

/**
 * print_dec - prints a decimal
 * @n: number to be printed
 * Return: no. chars printed
 */
int print_dec(int n)
{
	char ch;
	int i = 0;

	if (n % 10 < 0)
	{
		n = -n;
		ch = '-';
		write(1, &ch, 1);
		i++;
	}

	if (n / 10 == 0)
	{
		ch = n + '0';
		write(1, &ch, 1);
		i++;
		return (i);
	}
	else
	{
		i += print_dec(n / 10);
		ch = n % 10 + '0';
		write(1, &ch, 1);
		return (++i);
	}
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
	int n;
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
				n = va_arg(arg_list, int);
				len += print_dec(n);
			}
			else
				return (-1);
		}

		format++;
	}

	va_end(arg_list);

	return (len);
}
