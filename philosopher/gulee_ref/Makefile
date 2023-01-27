NAME		=	philo

FLAGS		=	-Wall -Werror -Wextra -g3 -fsanitize=thread
# LEAKS CHECK -fsanitize=address
CC			=	cc
RM			=	rm -rf

PHILO_SRCS	= philo.c \
				check_arg.c \
				check_philo.c \
				init.c \
				state_print.c \
				start.c \
				routine.c \
				save_options.c \
				time.c \
				utils.c

DIR_OBJS	=	obj
DIR_SRCS	=	src

PHILO_OBJS		=	$(PHILO_SRCS:.c=.o)

SRCS		=	$(addprefix $(DIR_SRCS)/,$(PHILO_SRCS))
OBJS		=	$(addprefix $(DIR_OBJS)/,$(PHILO_OBJS))

all					:	$(NAME)


$(NAME)				:	$(OBJS)
			$(CC) $(FLAGS) $^ -o $@

$(DIR_OBJS)/%.o		:	$(DIR_SRCS)/%.c Makefile | $(DIR_OBJS)
			$(CC) $(FLAGS) -c $< -o $@

$(DIR_OBJS)			:
			mkdir -p $@

clean				:
			$(RM) $(DIR_OBJS)

fclean				:
			$(RM) $(DIR_OBJS)
			$(RM) $(NAME)

re					:	fclean all

.PHONY				:	all clean fclean re
