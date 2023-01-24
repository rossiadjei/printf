#include "main.h"

/**
 * get_print - selects the function right for the inputed format
 * passes by the conversion specifier
 * @s: character that holds the conversion specifier
 * Return: a pointer to the matching printing function
 */
int (*get_print(char s))(va_list, flags_t *)
{
	ph arr_of_struc[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_bigS},
		{'p', print_address},
		{'%', print_percent}
		};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (arr_of_struc[i].c == s)
			return (arr_of_struc[i].f);
	return (NULL);
}
