#include "main.h"

/**
  *print_hex_binary - printbinary of numbers
  *@args: binary
  *Return: count on success
  */

int print_hex_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int i, count = 0;

	int printed = 0;

	for (i = sizeof(num) * 8 - 1; i >= 0; i--)
	{
		if ((num & (1u << i)) || printed)
		{
			putchar((num & (1u << i)) ? '1' : '0');
			count++;
			printed = 1;
		}
	}
	return (count);
}
