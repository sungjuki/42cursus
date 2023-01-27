#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 14:08:27 by sungjuki          #+#    #+#              #
#    Updated: 2022/06/23 14:35:48 by sungjuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER   = server
CLIENT   = client
CC	     = gcc
FLAGS    = -Wall -Werror -Wextra
LIBS	 = -Llibft -lft
LIBFT	 = libft.a

all : $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT) : 
	@make -C libft

$(SERVER) : server.o
	$(CC) server.o $(LIBS) -o $@

$(CLIENT) : client.o
	$(CC) client.o $(LIBS) -o $@

%.o : %.c
	$(CC) $(FLAGS) -c $?

clean :
	make clean -C libft
	rm -f *.o

fclean: clean
	make fclean -C libft
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all libft clean fclean re
