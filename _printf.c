#include <unistd.h>
#include <stdarg.h>
#include <limits.h>


/**
 * _switch - function that select format
 * @format: the format type
 * Return:void
 */

void _switch(char format, va_list args, int count);

/**
 * _printf - function to print input character
 * @format: our formating template
 * ...: rest of the parameterr
 *Return: int count
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count  = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			_switch(*format,args,count);
			format++;

		}
		else
		{
			write(1, format, 1);
			count++;
		}

		format++;
	}
	va_end(args);
	return (count);
}


/**
 * _switch - function that select format
 * @format: the format type
 * Return:void
 */

void _switch(char format, va_list args, int count)
{
	switch (format)
	{
		case 'c':
		{
			char c = va_arg(args, int);

			write(1, &c, 1);
			count++;
			break;
		}
		case 's':
		{
			const char *str = va_arg(args, const char *);

			while (*str)
			{
				write(1, str, 1);
				str++;
				count++;
			}
			break;
		}
		case '%':
		{
			char percent = '%';

			write(1, &percent, 1);
			count++;
			break;
		}

		default:
		break;
	}
}
