#include "main.h"
/**
 * convert - function like itoa
 * @num: long int number
 * @base: base
 * @flag: flags
 * @params: parameter struct
 *
 * Return: string pointer
 */
char *convert(long int num, int base, int flag, params_t *params)
{
	static char *arr;
	static char buffer[50];
	char sign = 0;
	char *p;
	unsigned long n = num;
	(void)params;

	if (!(flag & CONVERT_UNSIGN) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	arr = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';
	do {
		*--p = arr[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--p = sign;
	return (p);
}
/**
 * print_unsigned - print unsigned ints
 * @ap: argument pointer
 * @params: parameters struct
 *
 * Return: number of bytes printed
 */
int print_unsigned(va_list ap, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_num(convert(l, 10, CONVERT_UNSIGN, params), params));
}
/**
 * print_address - prints address
 * @ap: argument pointer
 * @params: parameters struct
 *
 * Return: number of bytes printed
 */
int print_address(va_list ap, params_t *params)
{
	unsigned long int a = va_arg(ap, unsigned long int);
	char *str;

	if (!a)
		return (_puts("(nil)"));
	str = convert(a, 16, CONVERT_UNSIGN | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_num(str, params));
}
