#include "main.h"

/**
 * _printf - an augmentation for printf
 * @format: formatted string
 * Return: no. chars of format
 */
int _printf(const char *format, ...)
{
	int len = 0, temp_len = 0;
	char c;
	char *str;
	va_list arg_list;

	if (format == NULL)
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
				write(1, &c, 1);
				len++;
			}

			if (*format == 's')
			{
				str = va_arg(arg_list, char*);

				while (str[temp_len] != '\0')
					temp_len++;

				write(1, str, temp_len);

				len += temp_len;
			}
		}

		format++;
	}

	va_end(arg_list);

	return (len);
}

