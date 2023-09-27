#include "main.h"
/**
 * get_percision - function to find percision
 * @str: pointer to string (format token)
 * @params: params_t parameters struct
 * @ap: argument pointer
 *
 * Return: new pointer
 */
char *get_percision(char *str, params_t *params, va_list ap)
{
	int pr = 0;

	if (*str != '.')
		return (str);
	str++;
	if (*str == '*')
	{
		pr = va_arg(ap, int);
		str++;
	}
	else
	{
		while (_isdigit(*str))
			pr = pr * 10 + (*str++ - '0');
	}
	params->percision = pr;
	return (str);
}
