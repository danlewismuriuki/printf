#include "main.h"

/**
 * custom_print_hex_base - base function for printing hexadecimal numbers
 * @hexValue: hexadecimal value to be printed
 * @caseType: case type ('a' for lowercase, 'A' for uppercase)
 * Return: number of digits printed
 */
int custom_print_hex_base(unsigned int hexValue, char caseType)
{
	int numDigitsPrinted;

	if (hexValue == 0)
		return (_putchar('0'));

	numDigitsPrinted = custom_print_unsignedIntToHex(hexValue, caseType);

	return (numDigitsPrinted);
}

/**
 * custom_print_hex - prints a hexadecimal in lowercase
 * @arg: list that contains hexadecimal to print
 * Return: number of digits printed
 */

int custom_print_hex(va_list arg)
{
	return (custom_print_hex_base(va_arg(arg, unsigned int), 'a'));
}

/**
 * custom_print_HEX - prints a hexadecimal in uppercase
 * @arg: list that contains hexadecimal to print
 * Return: number of digits printed
 */
int custom_print_HEX(va_list arg)
{
	return (custom_print_hex_base(va_arg(arg, unsigned int), 'A'));
}
