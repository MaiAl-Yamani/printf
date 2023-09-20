#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define OUT_BUF_SIZE 1024
#define BUF_FREE -1

#define INIT_PARAMS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define NUL_STR "(null)"
/**
 * struct parameters - struct for parameters
 *
 * @unsign: flag to check if value is unsigned
 * @plus_flag: flag is on if plus flag is specified (add + or - sign)
 * @space_flag: flag is on if space flag is specified (pad with space)
 * @zero_flag: flag is on if zero flag is specified (pad with zero)
 * @hashtag_flag: on if hashtag flag is specified
 * @minus_flag: flag is on if minus flag is specified (left shifted)
 *
 * @width: width of field to be printed
 * @percision: percision of field to be printed
 *
 * @h_modifier: on if h_modifier is specified (short argument)
 * @l_modifier: on if l_modifier is specified (long argument)
 */
typedef struct parameters
{
	unsigned int unsign;

	unsigned int plus_flag;
	unsigned int space_flag;
	unsigned int zero_flag;
	unsigned int hashtag_flag;
	unsigned int minus_flag;

	unsigned int width;
	unsigned int percision;

	unsigned int h_modifier;
	unsigned int l_modifier;
} params_t;

/**
 * struct specifier - struct for specifier
 *
 * @specifier: an element/token in format
 * @f: the function associated with its corresponding specifier
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t);
} specifier_t;

/* _printf.c module */
int _printf(const char *format, ...);

/* parameters.c module */
void init_parameters(params_t *params, va_list ap);

/* specifier.c module */
int (*get_specifier(char *str))(va_list ap, params_t *params);
int print_func(char *str, va_list ap, params_t *params);
int get_flag(char *str, params_t *params);
int get_modifier(char *str, params_t *params);
char *get_width(char *str, params_t *params, va_list ap);

/* _puts.c module */
int _puts(char *str);
int _putchar(int c);

/* print_funcs.c module */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

/* num.c module */
char *conver(long int num, int base, int flag, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* print_num.c module */
int _isdigit(int c);
int _strlen(char *str);
int print_num(char *str, params_t *params);
int print_num_right_justified(char *str, params_t *params);
int print_num_left_justified(char *str, params_t *params);

/* convert_num.c module */
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

/* printers.c module */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/* get_percision.c module */
char *get_percision(char *str, params_t *params, va_list ap);

#endif
