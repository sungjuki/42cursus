# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 16:58:48 by sungjuki          #+#    #+#              #
#    Updated: 2022/09/28 21:39:56 by sungjuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS		=	main.c \
				check_arg.c \
				check_philo.c \
				init.c \
				state_print.c \
				start.c \
				routine.c \
				save_options.c \
				time.c \
				utils.c

OBJS		= $(SRCS:%.c=%.o)

FLAGS		= -Wall -Wextra -Werror

CDEBUG		= #-fsanitize=thread

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		gcc -o $(NAME) $(OBJS) $(CDEBUG)

%.o			:	%.c
		gcc $(FLAGS) $(CDEBUG) -c $^ -o $@

clean		:
		rm -f $(OBJS)
		
fclean		:	clean
		rm -f $(NAME)
		
re			:	fclean all

.PHONY		:	all clean fclean re bonus
