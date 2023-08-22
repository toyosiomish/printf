#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

/**
 * _print_char - helper function to print a character
 * @args: va_list containing the argument list
 * @charCount: pointer to the character count
 */
void _print_char(va_list args, int *charCount)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	(*charCount)++;
}

/**
 * _print_string - helper function to print a string
 * @args: va_list containing the argument list
 * @charCount: pointer to the character count
 */
void _print_string(va_list args, int *charCount)
{
	const char *str = va_arg(args, const char *);

	while (*str)
	{
		write(1, str, 1);
		str++;
		(*charCount)++;
	}
}

/**
 * _switch - function that selects the format specifier
 * @args: va_list containing the argument list
 * @format: the format specifier
 * @charCount: pointer to the character count
 */
void _switch(va_list args, char format, int *charCount)
{
	switch (format)
	{
		case 'c':
			_print_char(args, charCount);
			break;
		case 's':
			_print_string(args, charCount);
			break;
		case '%':
			write(1, &format, 1);
			(*charCount)++;
			break;
		default:
			break;
	}
}

/**
 * _printf - custom printf function
 * @format: the format string
 * @...: variable number of arguments
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int charCount = 0;

	va_start(args, format);


	while (*format)
	{
		if (*format == '%')
		{
			format++;
			_switch(args, *format, &charCount);
		}
		else
		{
			write(1, format, 1);
			charCount++;
		}

		format++;
	}

	va_end(args);
	return (charCount);
}

