/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:45:23 by jdussert          #+#    #+#             */
/*   Updated: 2019/12/16 16:42:09 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *res)
{
	write(1, &c, 1);
	(*res)++;
}

void	ft_putstr(char *str, int *res)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++], res);
}
