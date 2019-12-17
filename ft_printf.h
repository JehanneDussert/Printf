/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:22:15 by jdussert          #+#    #+#             */
/*   Updated: 2019/12/16 10:11:30 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../../libft/libft.h"
# include <assert.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_printf
{
	char	flag;
	char	type;
	int		width;
	int		precision;
}					t_printf;

int					ft_istype(char type);
void				ft_initialize(t_printf *args);
void				ft_my_args(va_list parameters, const char *format, int *i,
		t_printf *args);
void				ft_define_type(va_list parameters, t_printf *args,
		int *res);
int					ft_printf(const char *format, ...);

void				ft_c_type(va_list parameters, t_printf *args, int *res);
void				ft_percent_type(t_printf *args, int *res);
void				ft_s_type(va_list parameters, t_printf *args, int *res);
void				ft_s_zero(t_printf *args, char *str, int *res, int s_len);
void				ft_s_spaces(t_printf *args, char *str, int *res, int s_len);
void				ft_s_minus(t_printf *args, char *str, int *res, int s_len);

void				ft_x_type(va_list parameters, t_printf *args, int *res,
		char *tab);
void				ft_p_type(va_list parameters, t_printf *args, int *res);
void				ft_di_type(va_list parameters, t_printf *args, int *res);
void				ft_zero_flag(t_printf *args, char *str, int *res, int s_len);
void				ft_add_specification(t_printf *args, int *res, char *str);
void				ft_u_type(va_list parameters, t_printf *args, int *res);

void				ft_putchar(char c, int *res);
void				ft_putstr(char *str, int *res);
int					ft_l_atoi(const char *str, int *i);
char				*ft_itoa_base(long int n, int base, char *tab);

void				ft_minus(t_printf *args, char *str, int *res, int stop);
void				ft_spaces(t_printf *args, char *str, int *res, int s_len);

void				ft_zero(t_printf *args, char *str, int *res, int s_len);

void				ft_flags(const char *format, int *i, t_printf *args);
void				ft_width(va_list parameters, const char *format, int *i,
		t_printf *args);
void				ft_precision(va_list parameters, const char *format, int *i,
		t_printf *args);

#endif
