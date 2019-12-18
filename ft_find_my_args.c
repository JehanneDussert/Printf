/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_my_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:52:38 by jdussert          #+#    #+#             */
/*   Updated: 2019/12/18 11:38:09 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_type(char type)
{
	if (type == 'c' || type == 's' || type == 'p' || type == 'd' ||
			type == 'i' || type == 'u' || type == 'x' || type == 'X' ||
			type == '%')
		return (1);
	return (0);
}

void	ft_flags(const char *format, int *i, t_printf *args)
{
	while (format[*i] == '0' || format[*i] == '-')
	{
		args->flag = format[*i];
		(*i)++;
	}
}

void	ft_width(va_list parameters, const char *format, int *i, t_printf *args)
{
	if ((format[*i] >= '0' && format[*i] <= '9') || format[*i] == '*')
	{
		if (format[*i] == '*')
		{
			args->width = (int)va_arg(parameters, int);
			if (args->width < 0)
			{
				args->flag = '-';
				args->width *= -1;
			}
			(*i)++;
		}
		else
			args->width = ft_l_atoi(format, i);
	}
}

void	ft_precision(va_list parameters, const char *format, int *i,
		t_printf *args)
{
	++(*i);
	if ((format[*i] >= '0' && format[*i] <= '9') || format[*i] == '*')
	{
		if (format[*i] == '*')
		{
			args->precision = (int)va_arg(parameters, int);
			if (args->precision < 0)
				args->precision = -1;
			(*i)++;
		}
		else
			args->precision = ft_l_atoi(format, i);
	}
	else
		args->precision = 0;
}
