/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:40:38 by jdussert          #+#    #+#             */
/*   Updated: 2019/12/18 11:48:42 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_percent_type(t_printf *args, int *res)
{
	char			flags;

	flags = (args->flag == '0' ? '0' : ' ');
	if (args->flag == '-')
		ft_putchar('%', res);
	while (args->width-- > 1)
		ft_putchar(flags, res);
	if (args->flag != '-')
		ft_putchar('%', res);
}

void	ft_c_type(va_list parameters, t_printf *args, int *res)
{
	unsigned char	c;
	char			flags;

	c = (unsigned char)va_arg(parameters, int);
	flags = (args->flag == '0' ? '0' : ' ');
	if (args->flag == '-')
		ft_putchar(c, res);
	while (args->width-- > 1)
		ft_putchar(flags, res);
	if (args->flag != '-')
		ft_putchar(c, res);
}

void	ft_s_type(va_list parameters, t_printf *args, int *res)
{
	char	*str;
	int		s_len;

	s_len = 0;
	str = (char *)va_arg(parameters, char *);
	if (!str)
		str = "(null)";
	while ((s_len < args->precision || args->precision == -1) && str[s_len])
		s_len++;
	if (args->flag == '-')
		ft_s_minus(args, str, res, s_len);
	else if (args->flag == '0')
		ft_s_zero(args, str, res, s_len);
	else
		ft_s_spaces(args, str, res, s_len);
}
