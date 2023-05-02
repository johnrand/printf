#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _printf - produces output according to a format
 *
 * @format: the format string
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;
	char *s;

	if (format == NULL)
	{
		return (0);
	}

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					s = va_arg(args, char *);
					if (s == NULL)
						s = "(null)";
					while (*s != '\0')
					{
						count += _putchar(*s);
						s++;
					}
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					count += _putchar('%');
					count += _putchar(format[i]);
					break;
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
	}

	va_end(args);

	return (count);
}
