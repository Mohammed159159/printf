#include "main.h"

/**
 * print_string - a function for printing a string
 * @args: args of printf
 * Return: length of string printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char*);

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
int print_char(va_list args)
{
	char ch = va_arg(args, int);
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


/**
 * rot13 - implement the rot13 algorithm on given string
 * @s: string to be manipulated
 * Return: no chars printed
 */
int rot13(char* s) 
{
	char* p;
	int i = 0;

	for (p = s; *p; p++) 
	{
		if (*p >= 'a' && *p <= 'z')
		{
			*p = (*p - 'a' + 13) % 26 + 'a';
			i++;
		} else if (*p >= 'A' && *p <= 'Z')
		{
			*p = (*p - 'A' + 13) % 26 + 'A';
			i++;
		}
	}

	return (i);
}

