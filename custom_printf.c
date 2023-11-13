#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function with limited functionality
 * @format: Format string containing directives
 *
 * Return: Number of characters printed (excluding null byte)
 */

int _printf(const char *format, ...)
{
	int variable_count = 0;/*to count the characters printed*/

	va_list var_arg;

	va_start(var_arg, format);

	/*while (*format)*/
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			/*format++; // move to the next character after '%'*/
			switch (*format)
			{
				case 'c':
					variable_count = variable_count +  putchar(va_arg(var_arg, int));
					break;
				case 's':
					variable_count = variable_count +  printf("%s", va_arg(var_arg, char *));
					break;
				case '%':
					variable_count = variable_count + putchar('%');
					break;
				default:
					putchar('%'); /*print the '%' character*/
					variable_count++;
					putchar(*format); /*print the unknown character*/
			}
		}
		else
		{
			putchar(*format);
			variable_count++;
		}
		format++;
	}
	va_end(var_arg);
	return (variable_count);
}
