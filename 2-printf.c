#include "main.h"

/**
 * print_binary - Print an unsigned int in binary format
 * @n: The unsigned int to print in binary format
 *
 * Return: The number of characters printed
 */

int print_binary(unsigned int n)
{
    int count = 0;
    unsigned int mask = 1;

    /* Count the number of bits needed to represent the number */
    while ((mask << 1) <= n)
        mask <<= 1;

    /* Print the binary representation of the number */
    while (mask > 0) {
        _putchar((n & mask) ? '1' : '0');
        mask >>= 1;
        count++;
    }

    return (count);
}

/**
 * handle_binary - converts an unsigned int to binary and prints it
 * @args: argument list containing the unsigned int to convert
 * @fmt: format string that specifies the conversion specifier
 * @count: pointer to count of characters printed so far
 *
 * Return: number of characters printed
 */
int handle_binary(va_list args, const char *fmt, int *count)
{
	unsigned int num = va_arg(args, unsigned int);
	char binary[32];
	int i, len = 0;

	(void)fmt;

	if (num == 0)
	{
		*count += _putchar('0');
		return (1);
	}

	for (i = 0; num > 0; i++)
	{
		binary[i] = (num % 2) + '0';
		num /= 2;
		len++;
	}

	for (i = len - 1; i >= 0; i--)
		*count += _putchar(binary[i]);

	return (len);
}

/**
 * _printf - Custom printf function that handles some custom conversion specifiers
 * @format: The format string
 * @...: The variable arguments list
 *
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'b':
                    count += handle_binary(args, format, &count);
                    break;
                default:
                    _putchar('%');
                    count++;
                    if (*format != '%') {
                        _putchar(*format);
                        count++;
                    }
                    break;
            }
        } else {
            _putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);

    return (count);
}
