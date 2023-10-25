#include "main.h"
/**
 * print_string - a function for printing a string
 * @args: args of printf
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
 * @args: args of printf
 * Return: 1 or 6 if char is null
 */
int print_char(char c)
{
	write(1, &c, 1);
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
 * print_bin - prints unsigned int in binary format
 * @n: number to be printed
 * Return: number of chars printed
 */
int print_bin(unsigned int n)
{
	int len = 0;
	char ch;

	if (n == 1)
	{
		ch = 1 + '0';
		write(1, &ch, 1);
		len++;
		return (len);
	}
	
	len += print_bin(n / 2);
	ch = (n % 2) + '0';
	write(1, &ch, 1);
	return (++len);
}

/**
 * printf_rot13 - printf str to ROT13 place into buffer
 * @args: type struct va_arg where is allocated printf arguments
 * Return: counter
 *
 */
int printf_rot13(va_list args)
{
	int i, j, counter = 0;
	int k = 0;
	char *s = va_arg(args, char*);
	char alpha[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char beta[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i]; i++)
	{
		k = 0;
		for (j = 0; alpha[j] && !k; j++)
		{
			if (s[i] == alpha[j])
			{
				write(1, &beta[j], 1);
				counter++;
				k = 1;
			}
		}
		if (!k)
		{
			write(1, &s[i], 1);
			counter++;
		}
	}
	return (counter);
}
/**
 * printf_string - print a string.
 * @val: argumen t.
 * Return: the length of the string.
 */

int printf_string(va_list val)
{
	char *s;
	int i, len;

	s = va_arg(val, char *);
	if (s == NULL)
	{
		s = "(null)";
		len = _strlen(s);
		for (i = 0; i < len; i++)
			write(1, &s[i], 1);
		return (len);
	}
	else
	{
		len = _strlen(s);
		for (i = 0; i < len; i++)
			write(1, &s[i], 1);
		return (len);
	}
}
