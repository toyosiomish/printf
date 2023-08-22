#include "main.h"
/**
 * printf_string - print a string.
 * @val: argumen t.
 * Return: the length of the string.
 */

int printf_string(va_list val)
{
	char *s;
	int len;

	s = va_arg(val, char *);
	if (s == NULL)
	{
		s = "(null)";
		len = 0;
		while(s[len] != '\0')
		{
			_putchar(s[len]);
			len++;
		}

		return (len);
	}
	else
	{
		len = 0;
		while(s[len] != '\0')
		{
			_putchar(s[len]);
			len++;
		}
		return (len);
	}
}
