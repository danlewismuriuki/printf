#include "main.h"

/**
 * custom_print_hex_base - func for printing hex num
 * @hexValue: hex value
 * @caseType: type 'a' lower, 'A' for upper
 * Return: num of digits
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
 * custom_print_hex - func prints a hex in lower
 * @arg: list of hex
 * Return: num digits
 */

int custom_print_hex(va_list arg)
{
	return (custom_print_hex_base(va_arg(arg, unsigned int), 'a'));
}

/**
 * custom_print_HEX - func hex in upper
 * @arg: list of hex
 * Return: num of digits
 */
int custom_print_HEX(va_list arg)
{
	return (custom_print_hex_base(va_arg(arg, unsigned int), 'A'));
}
