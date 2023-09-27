#include "main.h"
/**
 * print_hex - print hex number in lowercase
 * @ap: argument pointer
 * @params: parameters struct
 *
 * Return: number of bytes to be printed
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned long l;
	int count = 0;
	char *s;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	s = convert(l, 16, CONVERT_UNSIGN | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && l)
	{
		*--s = 'x';
		*--s = '0';
	}
	params->unsign = 1;
	return (count += print_num(s, params));
}
/**
 * print_HEX - print hex number in uppercase
 * @ap: aruments pointer
 * @params: parameters struct
 *
 * Return: number of bytes to be printed
 */
int print_HEX(va_list ap, params_t *params)
{
	unsigned long l;
	int count = 0;
	char *s;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	s = convert(l, 16, CONVERT_UNSIGN, params);
	if (params->hashtag_flag && l)
	{
		*--s = 'X';
		*--s = '0';
	}
	params->unsign = 1;
	return (count += print_num(s, params));
}
/**
 * print_binary - print binary number
 * @ap: arguments pointer
 * @params: parameters struct
 *
 * Return: number of bytes to be printed
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int i = va_arg(ap, unsigned int);
	int count = 0;
	char *s;

	s = convert(i, 2, CONVERT_UNSIGN, params);
	if (params->hashtag_flag && i)
		*--s = '0';
	params->unsign = 1;
	return (count += print_num(s, params));
}
/**
 * print_octal - print octal number
 * @ap: arguments pointer
 * @params: parameters struct
 *
 * Return: number of bytes to be printed
 */
int print_octal(va_list ap, params_t *params)
{
	unsigned long l;
	int count = 0;
	char *s;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	s = convert(l, 8, CONVERT_UNSIGN, params);
	if (params->hashtag_flag && l)
		*--s = '0';
	params->unsign = 1;
	return (count += print_num(s, params));
}
