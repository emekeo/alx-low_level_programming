#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_c - prints a character
 *
 * @c: characer to retreive
 */
void printchar(va_list c)
{
	printf("%c", (char)va_arg(c, int));
}
/**
 * print_i - prints an integer
 *
 * @i: integer to print
 */
void printint(va_list i)
{
	printf("%i", va_arg(i, int));
}
/**
 * print_f - prints a float number
 *
 * @f: float to print
 */
void printfloat(va_list f)
{
	printf("%f", (float)va_arg(f, double));
}
/**
 * print_s - prints a string
 *
 * @s: string to print
 */
void printstring(va_list s)
{
	char *result;

	result = va_arg(s, char *);
	if (result == NULL)
		printf("(nil)");
	printf("%s", result);
		
}
/**
 * print_all - prints anything
 *
 *
 * @format: list of types of arguments
 *
 */
void print_all(const char * const format, ...)
{
	unsigned int i;
	unsigned int j;
	char *separator;
	va_list ap;

	spec types[] = {
		{"c", printchar},
		{"i", printint},
		{"f", printfloat},
		{"s", printstring}
	};
	i = 0;
	separator = "";
	va_start(ap, format);
	while (format && format[i])
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == *types[j].p)
			{
				printf("%s", separator);
				types[j].f(ap);
				separator = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");
}
