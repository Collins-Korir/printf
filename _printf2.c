#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: Format string.
 *
 * Return: Number of characters printed (excluding the null byte).
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			switch (*ptr)
			{
				case 'c':
					count += write(1, va_arg(args, int), 1);
					break;
				case 's':
					count += write(1, va_arg(args, char*), _strlen(va_arg(args, char*)));
					break;
				case '%':
					count += write(1, "%", 1);
					break;
				default:
					count += write(1, "%", 1);
					count += write(1, ptr, 1);
			}
		}
		else
		{
			count += write(1, ptr, 1);
		}
	}

	va_end(args);
	return count;
}

/**
 * _strlen - Returns the length of a string.
 * @s: The string to be measured.
 *
 * Return: The length of the string.
 */
int _strlen(const char *s)
{
	int len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return len;
}

