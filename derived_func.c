#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * custom_print_unsignedToBinary - prints an integer in binary.
 * @arg: argument
 * Return: num of chars to be printed
 */
int custom_print_unsignedToBinary(va_list arg)
{
	unsigned int binaryNum = va_arg(arg, unsigned int);

	unsigned int printedCharacters;

	print_binary(binaryNum, &printedCharacters);
	print_binary(binaryNum, &printedCharacters);

	return (printedCharacters);
}

/**
 * custom_print_oct - prints num in octal.
 * @arg: list
 * Return: num of octals
 */

int custom_print_oct(va_list arg)
{
	unsigned int octalNum = va_arg(arg, unsigned int);
	unsigned int copy;
	char *octalChars;
	int i, j, charsPrinted = 0;

	if (octalNum == 0)
		return (_putchar('0'));

	for (copy = octalNum, j = 0; copy != 0; j++)
	{
		copy = copy / 8;
	}
	octalChars = malloc(j);

	if (!octalChars)
		return (-1);
	for (i = j - 1; i >= 0; i--)
	{
		octalChars[i] = octalNum % 8 + '0';
		octalNum = octalNum / 8;
	}
	for (i = 0; i < j && octalChars[i] == '0'; i++)
		;
	for (; i < j; i++)
	{
		_putchar(octalChars[i]);
		charsPrinted++;
	}
	free(octalChars);
	return (charsPrinted);
}

/**
 * custom_print_unsignedIntToHex - prints num int to hexadecimal.
 * @num: num
 * @_case: letter
 * Return: num or char
 */
int custom_print_unsignedIntToHex(unsigned int num, char _case)
{
	unsigned int numCopy;

	int i, j, remainder, numDigitsPrinted = 0;

	char *hexChars;

	for (numCopy = num; numCopy != 0; numDigitsPrinted++, numCopy /= 16)
		;
	hexChars = malloc(numDigitsPrinted);
	if (!hexChars)
		return (-1);

	for (i = 0; num != 0; i++)
	{
		remainder = num % 16;

		if (remainder < 10)
			hexChars[i] = remainder + '0';
		else
			hexChars[i] = remainder - 10 + _case;
		num = num / 16;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(hexChars[j]);
	free(hexChars);
	return (numDigitsPrinted);
}
