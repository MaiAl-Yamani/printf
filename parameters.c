#include "main.h"
/**
 * init_parameters - initialize paramter flags
 * @params: parameters from struct parameters
 * @ap: argument list
 *
 * Return: void
 */
void init_parameters(params_t *params, va_list ap)
{
	params->unsign = 0;
	params->plus_flag = 0;
	params->space_flag = 0;
	params->zero_flag = 0;
	params->hashtag_flag = 0;
	params->minus_flag = 0;
	params->width = 0;
	params->percision = UINT_MAX;
	params->h_modifier = 0;
	params->l_modifier = 0;

	(void)ap;
}
