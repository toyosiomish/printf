#include <unistd.h>
#include <stdarg.h>
#include <limits.h>


/**
 * _switch - function that select format
 * @format: the format type
 * Return:void
 */

void _switch(char format, va_list args, int charCount);

/**
 * _printf - function to print input character
 * @format: our formating template
 * ...: rest of the parameterr
 *Return: int charCount
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int charCount = 0;

	while (*format)
	{
		if (*format == '%')
		{
			_switch(*format,args,charCount);
			format++;

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


/**
 * _switch - function that select format
 * @format: the format type
 * Return:void
 */

void _switch(char format, va_list args, int charCount)
{
	switch (format)
	{
		case 'c':
		{
			char c = va_arg(args, int);

			write(1, &c, 1);
			charCount++;
			break;
		}
		case 's':
		{
			const char *str = va_arg(args, const char *);

			while (*str)
			{
				write(1, str, 1);
				str++;
				charCount++;
			}
			break;
		}
		case '%':
		{
			char percent = '%';

			write(1, &percent, 1);
			charCount++;
			break;
		}

		default:
		break;
	}
}
