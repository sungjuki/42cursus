# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 18:55:13 by sungjuki          #+#    #+#              #
#    Updated: 2022/06/08 18:57:45 by sungjuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

AR = ar
ARFLAGS = -cr

RM = rm
RMFLAGS = -f

NAME = libft.a

SRCS_PART1 = \
	ft_isspace.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_strdup.c ft_calloc.c
OBJS_PART1 = $(SRCS_PART1:.c=.o)

SRCS_PART2 = \
	ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c
OBJS_PART2 = $(SRCS_PART2:.c=.o)

SRCS_BONUS = \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	ft_lstiter.c ft_lstmap.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) $^

ifdef bonus
OBJS = $(OBJS_PART1) $(OBJS_PART2) $(OBJS_BONUS)
else
OBJS = $(OBJS_PART1) $(OBJS_PART2)
endif

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.Phony : all clean fclean re bonus

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJS_PART1) $(OBJS_PART2) $(OBJS_BONUS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

bonus :
	make bonus=true all
