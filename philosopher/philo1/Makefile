# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 16:58:48 by sungjuki          #+#    #+#              #
#    Updated: 2022/08/10 16:59:18 by sungjuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS		=	main.c \
				act.c \
				init.c \
				utils.c \
				
OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		gcc -o $(NAME) $(OBJS)

%.o			:	%.c
		gcc $(FLAGS) -c $^ -I./ -o $@

clean		:
		rm -f $(OBJS)
		
fclean		:	clean
		rm -f $(NAME)
		
re			:	fclean all

.PHONY		:	all clean fclean re bonus
