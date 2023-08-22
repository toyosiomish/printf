#include "main.h"
/**
  *print_unsigned_integer -print unsigned integer
  *@args: unsigned integer
  *Return: count
  */

int print_unsigned_integer(va_list args)
{
	unsigned  int num = va_arg(args, int);
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
  *print_octal - print Octal
  *@args: octal
  *Return: Count
  */

int print_octal(va_list args)
{
	int num = va_arg(args, int);
	int i, len;
	char buffer[32];
	int count;

	len = snprintf(buffer, sizeof(buffer), "%o", num);
	count = 0;

	for (i = 0; i < len; i++)
	{
		putchar(buffer[i]);
		count++;
	}

	return (count);
}


/**
  *print_hex_lower - print hex lower
  *@args: hex lower
  *Return: Count
  */

int print_hex_lower(va_list args)
{
	int num = va_arg(args, int);
	int i;
	int count = 0;
	char buffer[32];
	int len = snprintf(buffer, sizeof(buffer), "%x", num);

	for (i = 0; i < len; i++)
		count += putchar(tolower(buffer[i]));
	return (count);
}

/**
  *print_hex_upper -print hex upper
  *@args: hex upper
  *Return: Count
  */
int print_hex_upper(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[32];
	int len = snprintf(buffer, sizeof(buffer), "%X", num);

	int i, count = 0;

	for (i = 0; i < len; i++)
	{
		putchar(buffer[i]);
		count++;
	}
	return (count);
}
/**
  *print_pointer - print pointer
  *@args: pointer
  *Return: Count
  */
int print_pointer(va_list args)
{
	void *ptr = va_arg(args, void *);
	int count = 0;
	int i;
	char buffer[20];
	int len = snprintf(buffer, sizeof(buffer), "%p", ptr);

	for (i = 0; i < len; i++)
	{
		putchar(buffer[i]);
		count++;
	}
	return (count);
}
