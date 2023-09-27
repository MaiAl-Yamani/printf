#include "main.h"
/**
 * print_from_to - prints from a start to an end char
 * @start: starting point
 * @stop: stopping point
 * @except: exception point
 *
 * Return: number of bytes to be printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int count = 0;

	while (start < stop)
	{
		if (start != except)
			count += _putchar(*start);
		start++;
	}
	return (count);
}
/**
 * print_rev - print a string reversed
 * @ap: argument pointer
 * @params: params_t parameters struct
 *
 * Return: number of characters printed
 */
int print_rev(va_list ap, params_t *params)
{
	int len, count = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			count += _putchar(*str);
	}
	return (count);
}
/**
 * print_rot13 - prints a string in rot13
 * @ap: arguments pointer
 * @params: parameters struct
 *
 * Return: number of bytes to be printed
 */
int print_rot13(va_list ap, params_t *params)
{
	int ind1, ind2;
	int count = 0;
	char arr2[] = "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *arr1 = va_arg(ap, char *);
	(void)params;

	ind1 = 0;
	ind2 = 0;
	while (arr1[ind1])
	{
		if ((arr1[ind1] >= 'A' && arr1[ind1] <= 'Z')
				|| (arr1[ind1] >= 'a' && arr1[ind1] <= 'z'))
		{
			ind2 = arr1[ind1] - 65;
			count += _putchar(arr2[ind2]);
		}
		else
			count += _putchar(arr1[ind1]);
		ind1++;
	}
	return (count);
}
