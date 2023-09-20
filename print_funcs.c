#include "main.h"
/**
 * print_char - print character
 * @ap: va_list argument pointer
 * @params: params_t parameters struct
 *
 * Return: number of characters printed
 */
int print_char(va_list ap, params_t params)
{
	char padding_ch = ' ';
	unsigned int padding_iter = 1, count = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		count += _putchar(ch);
	while (padding_itr++ < params->width)
		count += _putchar(padding_ch);
	if (!params->minus_flag)
		count += _putchar(ch);
	return (count);
}
/**
 * print_int - prints integer
 * @ap: argument pointer
 * @params: params_t parameters struct
 *
 * Return: number of characters printed
 */
int print_int(va_list ap, params_t *params)
{
	long n;

	if (params->l_modifier)
		n = va_arg(ap, long);
	else if (params->h_modifier)
		n = (short int)va_arg(ap, int);
	else
		n = (int)va_arg(ap, int);
	return (print_num(convert(n, 10, 0, params), params));
}
/**
 * print_string - prints string
 * @ap: argument pointer
 * @params: params_t parameters struct
 *
 * Return: number of characters printed
 */
int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char padding_ch = ' ';
	unsigned int padding_iter = 0, i = 0, count = 0, j;

	switch ((int)(!str))
	case 1:
		str = NULL_STR;

	j = padding_iter = _strlen(str);
	if (params->percision < padding_iter)
		j = padding_iter = params->percision;

	if (params->minus_flag)
	{
		if (params->percision != UINT_MAX)
		{
			for (i = 0; i < padding_iter; i++)
				count += _putchar(*str++);
		}
		else
		{
			count += _puts(str);
		}
	}
	while (j++ < params->width)
		count += _putchar(padding_ch);
	if (!params->minus_flag)
	{
		if (params->percision != UINT_MAX)
			for (i = 0; i < padding_iter; i++)
				count += _putchar(*str++);
		else
			count += _puts(str);
	}
	return (count);
}
/**
 * print_S - print string with custom conversion specifier
 * @ap: argument pointer
 * @params: params_t parameters struct
 *
 * Return: number of characters printed
 */
int print_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char *hexa;
	int count;

	if ((int)(!str))
		return (_puts(NULL_STR));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			hexa = convert(*str, 16, 0, params);
			if (!hexa[2])
				count += _putchar('0');
			count += _puts(hexa);
		}
		else
		{
			count += _putschar(*str);
		}
	}
	return (count);
}
/**
 * print_percent - prints percent
 * @ap: argument pointer
 * @params: params_t parameters struct
 *
 * Return: number of characters printed
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;

	return (_putchar("%"));
}
