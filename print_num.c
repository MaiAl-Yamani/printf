#include "main.h"
/**
 * _isdigit - checks whether the input is digit or not
 * @c: int
 *
 * Return: 1 if digit, 0 if not
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/**
 * _strlen - returns the length of string
 * @str: string to check its length
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (*str++)
		i++;
	return (i);
}
/**
 * print_num - prints a number
 * @str: string
 * @params: parameters struct
 *
 * Return: chars to be printed
 */
int print_num(char *str, params_t *params)
{
	unsigned int itr = _strlen(str);
	int neg = (!(params->unsign) && *str == '-');

	if (!params->percision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		itr--;
	}
	if (params->percision != UINT_MAX)
		while (itr++ < params->percision)
			*--str = '0';
	if (neg)
		*--str = '-';
	if (params->minus_flag)
		return (print_num_right_justified(str, params));
	else
		return (print_num_left_justified(str, params));
}
/**
 * print_num_right_justified - prints a number (right)
 * @str: string
 * @params: parameters struct
 *
 * Return: chars to be printed
 */
int print_num_right_justified(char *str, params_t *params)
{
	unsigned int itr = _strlen(str);
	unsigned int n = 0, neg1, neg2;
	char pad_ch = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_ch = '0';
	neg1 = neg2 = (!params->unsign && *str == '-');
	if (neg1 && itr < params->width && pad_ch == '0' && !params->minus_flag)
		str++;
	else
		neg1 = 0;
	if ((params->plus_flag && !neg2) ||
			(!params->plus_flag && params->space_flag && !neg2))
		itr++;
	if (neg1 && pad_ch == '0')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_ch == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
			!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (itr++ < params->width)
		n += _putchar(pad_ch);
	if (neg1 && pad_ch == ' ')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_ch == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
			!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}
/**
 * print_num_left_justified - prints a number (left)
 * @str: string
 * @params: parameters struct
 *
 * Return: chars to be printed
 */
int print_num_left_justified(char *str, params_t *params)
{
	unsigned int itr = _strlen(str), n = 0, neg1, neg2;
	char pad_ch = '0';

	if (params->zero_flag && !params->minus_flag)
		pad_ch = '0';
	neg1 = neg2 = (!params->unsign && *str == '-');
	if (neg1 && itr < params->width && pad_ch == '0' && !params->minus_flag)
		str++;
	else
		neg1 = '0';

	if (params->plus_flag && !neg2 && !params->unsign)
		n += _putchar('+'), itr++;
	else if (params->space_flag && !neg2 && !params->unsign)
		n += _putchar(' '), itr++;
	n += _puts(str);
	while (itr++ < params->width)
		n += _putchar(pad_ch);
	return (n);
}
