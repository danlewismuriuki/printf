#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int main(void);
int _printf(const char *format, ...);
int _putchar(char c);
int custom_print_int(va_list arg);
int custom_print_unsigned(va_list arg);
int custom_printf(const char *format, ...);
int custom_print_char(va_list arg);
int custom_print_str(va_list arg);
void print_binary(unsigned int n, unsigned int *printed);
int custom_print_unsignedToBinary(va_list arg);
int custom_print_oct(va_list arg);
int custom_print_unsignedIntToHex(unsigned int num, char _case);
/*int custom_print_hex_base(va_list arg, char _case);*/
int custom_print_hex(va_list arg);
int custom_print_HEX(va_list arg);
int custom_print_STR(va_list arg);
/*int custom_print_hex_base(va_list arg, char _case);*/
/*int custom_print_hex_base(unsigned int hexValue, char caseType);*/

/**
 * struct identifierStruct - structure definition of a printTypeStruct
 * @identifier: type
 * @printer: function to print
 */
typedef struct identifierStruct
{
	char *identifier;
	int (*printer)(va_list);
} identifierStruct;

#endif
