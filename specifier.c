#include "main.h"
#include <stddef.h>

/**
 * get_specifier_array - Returns the array of specifier_info structs.
 *
 * Return: Pointer to the specifier_info array.
 */
const specifier_info *get_specifier_array(void)
{
	static specifier_info specifiers[] = {
		{'s', print_string},
		{'c', print_character},
		{'d', print_integer},
		{'i', print_integeri},
		{'u', print_unsigned_integer},
		{'p', print_pointer},
		{'o', print_octal},
		{'X', print_hex_upper},
		{'x', print_hex_lower},
		{'%', print_percent},
		{'b', print_hex_binary},
		{0, NULL}
	};
		return (specifiers);
}
