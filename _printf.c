#include "holberton.h"
/**
 * _printf - Function performs like the standard 'printf' function
 * @format: A string that contains characters and format strings
 * Return: Number of characters printed out of @format
 */
int _printf(const char *format, ...)
{
	int count;
	char ch, *str;
	va_list args;

	if (!format || (*format == '%' && *(format + 1) == '\0'))
		return (-1);
	if (*format == '%' && *(format + 1) == ' ' && *(format + 2) == '\0')
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == ' ')
			{
				while (*format == ' ')
					format++;
			}
			if (*format == 'c')
			{
				count++, format++, ch = va_arg(args, int), write(1, &ch, 1);
			} else if (*format == 's')
			{
				str = va_arg(args, char *), write(1, str, strlen(str));
				while (*str != '\0')
					count++, str++;
				format++;
			} else if (*format == '%')
			{
				count++, format++, ch = '%', write(1, &ch, 1);
			}
		} else
			ch = *format, write(1, &ch, 1), count++, format++;
	}
	va_end(args);
	return (count);
}
