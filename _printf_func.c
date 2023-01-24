#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * _printf - mimic the printf function in c "stdio.h" library
 * @format:  specified format for the printing
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	int (*ptf)(va_list, flags_t *);
	const char *i;
	va_list arg;
	flags_t flags = {0, 0, 0};

	register int count = 0;

	va_start(arg, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (i = format; *i; i++)
	{
		if (*i == '%')
		{
			i++;
			if (*i == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*i, &flags))
				i++;
			ptf = get_print(*i);
			count += (ptf)
				? ptf(arg, &flags)
				: _printf("%%%c", *i);
		} else
			count += _putchar(*i);
	}
	_putchar(-1);
	va_end(arg);
	return (count);

}
