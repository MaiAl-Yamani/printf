#include "main.h"
/**
 * _puts - prints a string
 * @str: pointer to string
 *
 * Return: int length of the string
 */
int _puts(char *str)
{
	char *start = str;

	while (*str)
	{
		_putchar(*str);
		str++;
	}
	return (str - start);
}
/**
 * _putchar - prints character to stdout
 * @c: character to be printed
 *
 * Return: 1 on success, -1 on failure
 */
int _putchar(int c)
{
	static int i;
	static char buffer[OUT_BUF_SIZE];

	if (c == BUF_FREE || i >= OUT_BUF_SIZE)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != BUF_FREE)
		buffer[i++] = c;
	return (1);
}
