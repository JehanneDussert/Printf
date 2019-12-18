/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 10:23:50 by jdussert          #+#    #+#             */
/*   Updated: 2019/12/18 10:43:00 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_spaces(t_printf *args, char *str, int *res, int s_len)
{
	int i;

	i = 0;
//	i = str[0] == '-' ? 1 : 0;
	while (args->width > s_len && args->width > args->precision && args->precision != 0)
	{
		ft_putchar(' ', res);
		args->width--;
	}
	if (args->precision == 0 && str[0] == '0' && args->width > 0)
		args->width += 1;
	while (args->width > s_len && args->precision <= 0)
	{
		ft_putchar(' ', res);
		args->width--;
	}
}

void	ft_minus(t_printf *args, char *str, int *res, int s_len)
{
	int i;

	i = 0;
	ft_putstr(str, res);
	if (args->precision == -1)
		ft_putstr(str, res);
	while ((args->width - args->precision > s_len) || (args->width > s_len))
	{
		ft_putchar(' ', res);
		args->width--;
	}
}

void	ft_zero(t_printf *args, char *str, int *res, int s_len)
{
	if (str[0] == '-')
	{
		ft_putchar('-', res);
		str++;
		args->precision += 1;
	}
	while ((args->flag == '0' && args->width > s_len)
			|| args->precision > s_len)
	{
		ft_putchar('0', res);
		s_len++;	
	}
	if (!(args->precision == 0 && str[0] == '0'))
		ft_putstr(str, res);
}
