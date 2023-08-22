#include "main.h"

/**
 *print_character - Print format specifier %c
 *@args: arguments passed to function
 *Return: count
 */


int print_character(va_list args)
{
	char c = (char)va_arg(args, int);

	putchar(c);
	return (1);
}
/**
 *print_percent - print %
 *@args: arguments passed to function
 *Return: count
 */

int print_percent(va_list args)
{
	putchar('%');
	(void)args;

	return (1);
}


/**
 *print_integer - print integer where seen
 *@args: arguments passed to function
 *Return: count
 */

int print_integer(va_list args)
{
	int num = va_arg(args, int);
	int i, count = 0;
	char buffer[32];
	int len = snprintf(buffer, sizeof(buffer), "%d", num);

	for (i = 0; i < len; i++)
	{
		putchar(buffer[i]);
		count++;
	}

	return (count);
}

/**
 * print_integeri - print unsigned integer from va_list
 * @args: va_list containing the unsigned integer to print
 * Return: count
 */
int print_integeri(va_list args)
{
	int num = va_arg(args, int);
	int i, count = 0;
	char buffer[32];
	int len = snprintf(buffer, sizeof(buffer), "%d", num);

	for (i = 0; i < len; i++)
	{
		putchar(buffer[i]);
		count++;
	}

	return (count);
}



/**
 *print_string - prints a string from va_list
 *@args: va_list containing the string to print
 *Return: count
 */

int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	size_t len, i;
	int count = 0;

	if (str == NULL)
	{
		const char null_str[] = "(null)";

		len = strlen(null_str);

		for (i = 0; i < len; i++)
		{
			putchar(null_str[i]);
			count++;
		}
	}
	else
	{
		len = strlen(str);

		for (i = 0; i < len; i++)
		{
			putchar(str[i]);
			count++;
		}
	}

	return (count);
}
