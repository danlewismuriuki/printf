#include "main.h"

/**
 * print_binary - prints binary number
 * @num: number  binary num to be printed
 * @numPrinted: pointer
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
