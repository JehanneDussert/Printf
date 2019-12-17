/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:48:37 by jdussert          #+#    #+#             */
/*   Updated: 2019/12/17 19:29:35 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_p_specification(t_printf *args, int *res, char *str)
{
	int	s_len;

	s_len = 12;
	if (args->flag == '-')
	{
		ft_putstr("0x", res);
		ft_s_minus(args, str, res, s_len);
	}
	else if (args->flag == '0')
	{
		ft_putstr("0x", res);
		ft_s_zero(args, str, res, s_len);
	}
	else
	{
		while (args->width > 14)
		{
			ft_putchar(' ', res);
			args->width--;
		}
		ft_putstr("0x", res);
		ft_putstr(str, res);
	}
	free(str);
	str = NULL;
}

void	ft_p_type(va_list parameters, t_printf *args, int *res)
{
	long int	n;
	char		*str;

	n = (long int)va_arg(parameters, void *);
	str = ft_itoa_base(n, 16, "0123456789abcdef");
	if (args->flag == '-')
		args->width -= 2;
	ft_p_specification(args, res, str);
}
