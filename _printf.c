#include <stdarg.h>
/**
 * _printf - my version of printf function
 * @format: string composed of zero or more directives
 *
 * Return: number of chars printed excluding '\0' at end of string
 */
int _printf(const char *format, ...)
{
	char *ptr, *start;
	va_list ap;
	int i, n;
	params_t params = INIT_PARAMS;

	n = 0;
	va_start(ap, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (*char)format; *p; p++)
	{
		params = init_parameters(&params, ap);
		if (*p != '%')
		{
			n += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
			p++;
		p = get_width(p, &params, ap);
		p = get_percision(p, params, ap);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
		{
			n += print_from_to(start, p,
					params.l_modifier || params.h_modifier ? p - 1 : 0)
		}
		else
			n += print_func(p, ap, &params);
	}
	_putchar(BUF_FREE);
	va_end(ap);
	return (n);
}
