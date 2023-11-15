#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * custom_print_char - writes the character c to stdout
 * @arg: argument
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int custom_print_char(va_list arg)
{
	return (_putchar(va_arg(arg, int)));
}

/**
 * custom_print_int - prints an integer.
 * @arg: argument
 * Return: 0
 */

int custom_print_int(va_list arg)
{
	unsigned int custom_divisor = 1, i, currentDigit, numPrinted = 0;
	int originalNumber = va_arg(arg, int);

	if (originalNumber < 0)
	{
		_putchar('-');
		numPrinted++;
		originalNumber *= -1;
	}
	for (i = 0; originalNumber / custom_divisor > 9; i++, custom_divisor *= 10)
		;
	for (; custom_divisor >= 1; originalNumber %= custom_divisor,
			custom_divisor /= 10, numPrinted++)
	{
		currentDigit = originalNumber / custom_divisor;
		_putchar('0' + currentDigit);
	}
	return (numPrinted);
}

/**
 * custom_print_STR - prints a string with a `S` (upper case) specifier
 * @arg: argument
 * Return: number of character printed
 */

int custom_print_STR(va_list arg)
{
	int i;
	char *str = va_arg(arg, char*);

	if (str == NULL)
		str = "(null)";
	else if (*str == '\0')
		return (-1);

	for (i = 0; str[i]; i++)
	{
		if ((str[i] < 32 && str[i] > 0) || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if (i < 16)
				_putchar('0');
			custom_print_unsignedIntToHex(str[i], 'A');
		}
		else
		{
			_putchar(str[i]);
		}
	}
	return (i);
}

/**
 * custom_print_str - prints a string with a `s` (lower case) specifier
 * @arg: argument
 * Return: number of character printed
 */

int custom_print_str(va_list arg)
{
	int i;
	char *str = va_arg(arg, char*);

	if (str == NULL)
		str = "(null)";
	else if (*str == '\0')
		return (-1);

	for (i = 0; str[i]; i++)
		_putchar(str[i]);
	return (i);
}
/**
 * custom_print_unsigned - prints an unsigned int.
 * @arg: argument
 * Return: 0
 */
int custom_print_unsigned(va_list arg)
{
	int custom_divisor = 1, i, currentDigit;
	unsigned int num = va_arg(arg, unsigned int);

	for (i = 0; num / custom_divisor > 9; i++, custom_divisor *= 10)
		;

	for (; custom_divisor >= 1; num %= custom_divisor, custom_divisor /= 10)
	{
		currentDigit = num / custom_divisor;
		_putchar('0' + currentDigit);
	}

	return (i + 1);
}
