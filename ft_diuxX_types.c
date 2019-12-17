/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diuxX_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:26:30 by jdussert          #+#    #+#             */
/*   Updated: 2019/12/16 19:19:26 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_specification(t_printf *args, int *res, char *str)
{
	int	s_len;

	s_len = 0;
	while (str[s_len] != '\0')
		s_len++;
	if (args->flag == '0' && args->width - args->precision > s_len)
		args->flag = '+';
	if ((args->precision > s_len && args->width == -1) ||
			args->precision > args->width)
		ft_zero(args, str, res, s_len);
	else if ((args->flag == '0' || args->flag == '+') && args->width > 0)
		ft_zero_flag(args, str, res, s_len);
	else if (args->flag == '-')
	{
		ft_zero(args, str, res, s_len);
		ft_spaces(args, str, res, s_len);
	}
	else
		ft_putstr(str, res);
	free(str);
	str = NULL;
}

void	ft_u_type(va_list parameters, t_printf *args, int *res)
{
	unsigned int	n;
	char			*str;

	n = (unsigned int)va_arg(parameters, unsigned int);
	str = ft_itoa_base(n, 10, "0123456789");
	ft_add_specification(args, res, str);
}

void	ft_di_type(va_list parameters, t_printf *args, int *res)
{
	int		n;
	char	*str;

	n = (int)va_arg(parameters, int);
	str = ft_itoa_base(n, 10, "0123456789");
	ft_add_specification(args, res, str);
}

void	ft_x_type(va_list parameters, t_printf *args, int *res, char *tab)
{
	unsigned int	n;
	char			*str;

	n = (unsigned int)va_arg(parameters, unsigned int);
	str = ft_itoa_base(n, 16, tab);
	ft_add_specification(args, res, str);
}

void	ft_zero_flag(t_printf *args, char *str, int *res, int s_len)
{
	if (args->width > s_len && args->precision < 0)
	{
		args->flag == '0' ? ft_zero(args, str, res, s_len)
			: ft_spaces(args, str, res, s_len);
		if (args->flag != '0')
			ft_putstr(str, res);
	}
	else if (args->width > args->precision && args->width > 0)
	{
		ft_spaces(args, str, res, s_len);
		ft_zero(args, str, res, s_len);
	}
}
