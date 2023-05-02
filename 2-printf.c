#include "main.h"

/**
 * print_uint_helper - helper function to print an unsigned integer
 * @buffer: buffer to store the output
 * @num: the unsigned integer to print
 * @base: the base to use for conversion
 * @width: the minimum field width
 * @size: the maximum number of digits to print
 *
 * Return: the number of characters printed
 */

int print_uint_helper(char buffer[], unsigned int num, char *base,
                      int width, int size);


/**
 * print_binary - Converts an unsigned int argument to binary
 * @types: A va_list containing the arguments to print
 * @buffer: A buffer to store the printed string
 * @flags: Flags used to modify the output
 * @width: Minimum width of the printed string
 * @precision: Precision of the printed string
 * @size: Maximum number of bytes to be written in buffer
 *
 * Return: The number of bytes written in buffer.
 */

int print_binary(va_list types, char buffer[],
                __attribute__((unused))int flags, int width,
                __attribute__((unused))int precision, int size)
{
	unsigned int num = va_arg(types, unsigned int);
	unsigned int bin = 0, rem, i = 1;

	while (num != 0)
	{
		rem = num % 2;
		num /= 2;
		bin += rem * i;
		i *= 10;
	}

	return (print_uint_helper(buffer, bin, "01", width, size));
}
