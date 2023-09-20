#include "main.h"
/**
 * get_specifier - pointer function to get the specifier to the char
 * @str: pointer to string
 *
 * Return: the corresponding function (number of bytes printed)
 */
int (*get_specifier(char *str))(va_list ap, params_t *params)
{
	specifier_t spec[] = {
		{"c", print_char},
		{"i", print_int},
		{"d", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"S", print_S},
		{"u", print_unsigned},
		{"o", print_octal},
		{"b", print_binary},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (spec[i].specifier)
	{
		if (*str == spec[i].specifier[0])
			return (spec[i].f);
		i++;
	}
	return (NULL);
}
/**
 * print_func - print the correspoding function
 * @str: pointer to string
 * @ap: va_list argument pointer
 * @params: params_t parameters struct
 *
 * Return: number of bytes printed
 */
int print_func(char *str, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(str);

	if (f)
		return (f(ap, params));
	return (0);
}
/**
 * get_flag - finds the flag
 * @str: pointer to string
 * @params: params_t parameters struct
 *
 * Return: 1 if flag is found
 */
int get_flag(char *str, params_t *params)
{
	int i = 0;

	switch (*str)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}
/**
 * get_modifier - finds the modifier
 * @str: pointer to string
 * @params: params_t parameters struct
 *
 * Return: 1 if modifier is valid
 */
int get_modifier(char *str, params_t *params)
{
	int i = 0;

	switch (*str)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}
/**
 * get_width - finds the width from the format str
 * @str: pointer to string (format token)
 * @ap: va_list argument pointer
 * @params: params_t parameters struct
 *
 * Return: new pointer
 */
char *get_width(char *str, va_list ap, params_t *params)
{
	int w = 0;

	if (*str == '*')
	{
		w = va_arg(ap, int);
		str++;
	}
	else
	{
		while (_isdigit(*str))
		{
			w = w * 10 + (*str++ - '0');
		}
	}
	params->width = w;
	return (str);
}

