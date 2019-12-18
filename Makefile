# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdussert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/25 10:27:05 by jdussert          #+#    #+#              #
#    Updated: 2019/12/18 11:30:20 by jdussert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS	= ft_printf.c ft_flags.c ft_printf_utils.c ft_print_it.c \
		  ft_find_my_args.c ft_cs_types.c ft_s_flags.c ft_p_type.c \
		  ft_diux_types.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

$(NAME) : ${OBJS}
	ar rcs ${NAME} ${OBJS} 

all : ${NAME}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all
