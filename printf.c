#include "main.h"
#include <limits.h>
/**
 * _printf - Custom implementation of printf that supports %c, %s, and %%
 * @format: A string containing format specifiers
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;
	char *s;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				c = (char)va_arg(args, int);
				count += _putchar(c);
				break;
			case 's':
				s = va_arg(args, char *);
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
				/* Unsupported format specifier, ignore it */
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
