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

	if (str[0] == '\0')
		return (0);

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
	if (ch == '\0')
		return (0);

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
