#include "main.h"

/**
 * print_binary - function that prints the binary representation of a number
 * @num: number to be printed in binary
 * @numPrinted: pointer to hold the number of characters printed
 */
void print_binary(unsigned int num, unsigned int *numPrinted)
{
	if (num > 1)
	{
		*numPrinted += 1;
		print_binary(num >> 1, numPrinted);
	}
	_putchar((num & 1) + '0');
}
