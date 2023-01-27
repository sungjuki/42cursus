# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 13:14:48 by sungjuki          #+#    #+#              #
#    Updated: 2022/03/25 14:10:17 by sungjuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

AR = ar
ARFLAGS = -cr

RM = rm
RMFLAGS = -f

NAME = libftprintf.a
LIBFT = libft
LIBFT_LIB = libft.a

MANDATORY_PART =	ft_printf\
					ft_printf_preprocess\
					ft_printf_printphase\
					ft_printf_boxing\
					ft_printf_utils\
					ft_printf_utils2\
					ft_printf_char\
					ft_printf_string\
					ft_printf_pnt\
					ft_printf_unsigned\
					ft_printf_nbr
OBJS_MAN = $(MANDATORY_PART:.c=.o)

BONUS_PART =		ft_printf\
					ft_printf_preprocess\
					ft_printf_printphase\
					ft_printf_boxing\
					ft_printf_utils\
					ft_printf_utils2\
					ft_printf_char\
					ft_printf_string\
					ft_printf_pnt\
					ft_printf_unsigned\
					ft_printf_nbr
OBJS_BONUS = $(BONUS_PART:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) $^

ifdef bonus
OBJS = $(OBJS_BONUS)
else
OBJS = $(OBJS_MAN)
endif

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(ARFLAGS) $@ $^

.Phony : all clean fclean re bonus

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJS_MAN) $(OBJS_BONUS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

bonus :
	make bonus=true all
