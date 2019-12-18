/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:41:45 by jdussert          #+#    #+#             */
/*   Updated: 2019/12/18 10:23:45 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_s_spaces(t_printf *args, char *str, int *res, int s_len)
{
	int i;

	i = 0;
	while (args->width - s_len > 0)
	{
		ft_putchar(' ', res);
		args->width--;
	}
	while (i < s_len)
		ft_putchar(str[i++], res);
}

void	ft_s_minus(t_printf *args, char *str, int *res, int s_len)
{
	int i;

	i = 0;
	while (i < s_len)
		ft_putchar(str[i++], res);
	while (args->width - s_len > 0)
	{
		ft_putchar(' ', res);
		args->width--;
	}
}

void	ft_s_zero(t_printf *args, char *str, int *res, int s_len)
{
	int	i;

	i = 0;
	while (args->width - s_len > 0)
	{
		ft_putchar('0', res);
		args->width--;
	}
	while (i < s_len)
		ft_putchar(str[i++], res);
}
