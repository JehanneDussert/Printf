/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:20:03 by jdussert          #+#    #+#             */
/*   Updated: 2019/12/18 11:42:31 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_return(t_printf *args, va_list parameters, int res)
{
	va_end(parameters);
	free(args);
	return (res);
}

void	ft_initialize(t_printf *args)
{
	args->width = -1;
	args->precision = -1;
	args->flag = '+';
	args->type = -1;
}

void	ft_my_args(va_list parameters, const char *format, int *i,
		t_printf *args)
{
	ft_initialize(args);
	if (format[*i] == '0' || format[*i] == '-')
		ft_flags(format, i, args);
	if ((format[*i] >= '0' && format[*i] <= '9') || format[*i] == '*')
		ft_width(parameters, format, i, args);
	if (format[*i] == '.')
		ft_precision(parameters, format, i, args);
	if (ft_is_type(format[*i]) == 1)
	{
		args->type = format[*i];
		(*i)++;
	}
}

void	ft_define_type(va_list parameters, t_printf *args, int *res)
{
	if (args->type == '%')
		ft_percent_type(args, res);
	else if (args->type == 'c')
		ft_c_type(parameters, args, res);
	else if (args->type == 's')
		ft_s_type(parameters, args, res);
	else if (args->type == 'x')
		ft_x_type(parameters, args, res, "0123456789abcdef");
	else if (args->type == 'X')
		ft_x_type(parameters, args, res, "0123456789ABCDEF");
	else if (args->type == 'p')
		ft_p_type(parameters, args, res);
	else if (args->type == 'd' || args->type == 'i')
		ft_di_type(parameters, args, res);
	else if (args->type == 'u')
		ft_u_type(parameters, args, res);
}

int		ft_printf(const char *format, ...)
{
	va_list			parameters;
	t_printf		*args;
	int				i;
	int				res;

	i = 0;
	res = 0;
	va_start(parameters, format);
	if (!(args = (t_printf *)malloc(sizeof(t_printf))))
		return (-1);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			ft_putchar(format[i++], &res);
		if (format[i] == '%')
		{
			i++;
			ft_my_args(parameters, format, &i, args);
			if (ft_is_type(args->type) == 1)
				ft_define_type(parameters, args, &res);
			else
				break ;
		}
	}
	return (ft_return(args, parameters, res));
}
