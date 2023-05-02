#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 *
 * Return: number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += printf("%s", va_arg(args, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				case 'd':
				case 'i':
					count += printf("%d", va_arg(args, int));
					break;
				default:
					count += _putchar('%');
					count += _putchar(*format);
					break;
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}

	va_end(args);

	return (count);
}
