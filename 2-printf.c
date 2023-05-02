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
 * handle_binary - Handle the "b" custom conversion specifier
 * @args: The va_list containing the next argument
 * @fmt: The format string
 * @count: A pointer to the character count
 *
 * Return: The number of characters printed
 */

int handle_binary(va_list args, const char *fmt, int *count)
{
    unsigned int n = va_arg(args, unsigned int);

    return (print_binary(n));
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
