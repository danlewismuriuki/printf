#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * custom_print_identifiers - prints special characters
 * @next: character after the %
 * @arg: argument for the identifier
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int custom_print_identifiers(char nxt_char, va_list arg_var)
{
	int index;

	identifierStruct custom_functs[] = {
		{"c", custom_print_char},
		{"s", custom_print_str},
		{"d", custom_print_int},
		{"i", custom_print_int},
		{"u", custom_print_unsigned},
		{"b", custom_print_unsignedToBinary},
		{"o", custom_print_oct},
		{"x", custom_print_hex},
		{"X", custom_print_HEX},
		{"S", custom_print_STR},
		{NULL, NULL}
	};
	for (index = 0; custom_functs[index].identifier != NULL; index++)
	{
		if (custom_functs[index].identifier[0] == nxt_char)
			return (custom_functs[index].printer(arg_var));
	}
	return (0);
}

/**
 * custom_printf - mimic printf from stdio
 * Description: produces output according to a format
 * write output to stdout, the standard output stream
 * @fmt: character string composed of zero or more directives
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 * return -1 for incomplete identifier error
 */

int custom_printf(const char *fmt, ...)
{
	unsigned int i;
	int idPrinted = 0, chPrinted = 0;
	va_list args;

	va_start(args, fmt);
	if (fmt == NULL)
		return (-1);

	for (i = 0; fmt[i] != '\0'; i++)
	{
		if (fmt[i] != '%')
		{
			_putchar(fmt[i]);
			chPrinted++;
			continue;
		}
		if (fmt[i + 1] == '%')
		{
			_putchar('%');
			chPrinted++;
			i++;
			continue;
		}
		if (fmt[i + 1] == '\0')
			return (-1);

		idPrinted = custom_print_identifiers(fmt[i + 1], args);
		if (idPrinted == -1 || idPrinted != 0)
			i++;
		if (idPrinted > 0)
			chPrinted += idPrinted;

		if (idPrinted == 0)
		{
			_putchar('%');
			chPrinted++;
		}
	}
	va_end(args);
	return (chPrinted);
}
